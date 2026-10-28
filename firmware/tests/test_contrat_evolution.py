#!/usr/bin/env python3
"""Verifie le contrat de continuite du firmware, sans materiel externe.

Les fonctions physiques exigent en plus une validation sur carte reelle.
"""
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT.parent

manifest = json.loads((ROOT / "manifest.json").read_text(encoding="utf-8"))
assert manifest["schema_version"] == 1, "Version de manifeste inconnue"
stages = manifest["stages"]
assert stages and len(stages) == len({v["module"] for v in stages}), "Versions absentes ou dupliquees"
numbers = [int(s["module"][1:]) for s in stages]
assert all(re.fullmatch(r"M\d{2}", s["module"]) for s in stages), "Noms de modules invalides"
assert numbers == sorted(numbers) and numbers[0] == 3, "Versions mal ordonnees"
assert manifest["latest_firmware_stage"] == numbers[-1], "Version active incorrecte"

# Le parcours M03-M11 suit chaque version de firmware. Les modules
# backend/PCB peuvent ne pas toucher au firmware ensuite.
if numbers[-1] <= 11:
    assert numbers == list(range(3, numbers[-1] + 1)), "Etape intermediaire manquante"

stage_dir = ROOT / "etapes"
existing = sorted(
    int(p.name[1:]) for p in stage_dir.iterdir()
    if p.is_dir() and re.fullmatch(r"M\d{2}", p.name)
)
assert existing == numbers, (
    f"Snapshots GitHub {existing} != manifeste {numbers}. "
    "Ajouter toute version dans firmware/manifest.json."
)
for stage in stages:
    ident = stage["module"]
    relative = Path(stage["sketch"])
    expected = Path("etapes") / ident / f"Compteur_{ident}" / f"Compteur_{ident}.ino"
    assert relative == expected, f"Chemin du sketch invalide : {ident}"
    path = ROOT / relative
    assert path.is_file(), f"Sketch manquant : {path}"
    assert (ROOT / "etapes" / ident / "README.md").is_file(), (
        f"Documentation de l'etape manquante : {ident}"
    )
    source = path.read_text(encoding="utf-8")
    assert "void setup()" in source and "void loop()" in source, f"Structure Arduino absente : {ident}"

latest = stages[-1]
latest_source = ROOT / latest["sketch"]
current = ROOT / manifest["current_sketch"]
assert current.is_file(), "Le programme principal courant manque"
assert current.read_bytes() == latest_source.read_bytes(), (
    "La version courante et le dernier snapshot .ino divergent"
)

# Comparer aussi les .h et les autres sources associees au sketch.
# Le seul fichier renomme entre les dossiers est le .ino principal.
old_files = {
    p.name: p.read_bytes() for p in latest_source.parent.iterdir()
    if p.is_file() and p.name != latest_source.name
}
new_files = {
    p.name: p.read_bytes() for p in current.parent.iterdir()
    if p.is_file() and p.name != current.name
}
assert old_files == new_files, "Les en-tetes/sources du courant divergent du snapshot"

policy = REPO / "docs/formation/REGLE_EVOLUTION_CONTINUE.md"
assert policy.is_file(), "Regle de progression obligatoire non trouvee"
guide = (REPO / "formation/GUIDE_PEDAGOGIQUE.md").read_text(encoding="utf-8")
assert "REGLE_EVOLUTION_CONTINUE.md" in guide, "Le guide ne pointe plus vers la regle"
matrix = (ROOT / "PROGRESSION.md").read_text(encoding="utf-8")
assert "REGLE_EVOLUTION_CONTINUE.md" in matrix, "La progression ne pointe plus vers le contrat"

# Chaque module futur doit porter ce contrat jusque dans son README.
for document in (REPO / "formation/modules").glob("M*/README.md"):
    match = re.match(r"M(\d{2})-", document.parent.name)
    if match and int(match.group(1)) >= 9:
        assert "REGLE_EVOLUTION_CONTINUE.md" in document.read_text(encoding="utf-8"), (
            f"Regle fil rouge absente de {document.parent.name}"
        )

if numbers[-1] >= 9:
    recent = latest["module"]
    previous = stages[-2]["module"]
    assert f"{previous} → {recent}" in matrix, (
        f"Ajout {recent} : mettre a jour la matrice avec la transition "
        f"{previous} → {recent}"
    )
    assert f"{previous} → {recent} (à réaliser)" not in matrix, (
        "La progression indique encore que le module est a realiser"
    )


# Contrat du brochage cible M10-M16 : PZEM sur D6/D7, GSM sur D0/D1.
# Les sketches pedagogiques M09 conservent leur ancien brochage D10/D11.
pinmap = (REPO / "docs/hardware/TABLEAU_AFFECTATION_ATMEGA328P_PDIP28.md").read_text(encoding="utf-8")
policy_content = policy.read_text(encoding="utf-8")
m10_guide = (REPO / "formation/modules/M10-sim800l-gsm-gprs/README.md").read_text(encoding="utf-8")
firmware_guide = (ROOT / "README.md").read_text(encoding="utf-8")
assert "SoftwareSerial(6, 7)" in pinmap, "Brochage PZEM cible non mis a jour"
assert "D6/RX = PD6 broche 12" in policy_content, "Broche PZEM RX M10 incoherente"
assert "D7/TX = PD7 broche 13" in policy_content, "Broche PZEM TX M10 incoherente"
assert "D6/RX (PD6, pin 12), D7/TX (PD7, pin 13)" in m10_guide, "M10 incoherent"
assert "SoftwareSerial(6, 7)" in firmware_guide, "Guide firmware non synchronise"
if manifest["latest_firmware_stage"] == 9:
    assert "SoftwareSerial portPzem(10, 11)" in current.read_text(encoding="utf-8"), (
        "M09 historique modifie avant migration pedagogique M10"
    )

print(
    f"PASS : regle de progression, {len(stages)} versions, "
    f"snapshot {latest['module']} = firmware courant et fichiers associes"
)
