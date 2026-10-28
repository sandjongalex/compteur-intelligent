#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Assemble le livre AlexTech Academy sans importer de documents de production.

Le brouillon est un outil interne. La publication nécessite les seize chapitres,
leurs corrigés et la validation de toutes les illustrations au registre.
Dépendances : bibliothèque standard Python 3.10+ uniquement.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import shutil
import sys
from pathlib import Path
from urllib.parse import unquote

TITRE = "Concevez votre compteur électrique intelligent IoT"
SOUS_TITRE = "De la mesure électrique à la supervision énergétique sur Internet"
AUTEUR = "Sandjong Tchoungong Alex"
NOMBRE_CHAPITRES = 16

RE_CHAPITRE = re.compile(r"^(\d{2})-[^/]+\.md$")
RE_CORRIGE = re.compile(r"^CORRIGE_M(\d{2})\.md$")
RE_H1 = re.compile(r"^# (.+)$", re.MULTILINE)
RE_COMMENTAIRE = re.compile(r"<!--[\s\S]*?-->")
RE_FIGURE = re.compile(r"<!--\s*ILLUSTRATION À PRODUIRE\s*—\s*FIGURE\s+(\d+\.\d+)")
RE_REPERE = re.compile(r"ILLUSTRATION À INSÉRER\s*—\s*Figure\s+(\d+\.\d+)")
RE_IMAGE = re.compile(r"!\[([^\]\n]*)\]\(([^)\n]+)\)")
RE_REGISTRE = re.compile(r"^\|\s*\*\*(\d+\.\d+)\*\*\s*\|.+\|\s*([^|]+?)\s*\|\s*$", re.MULTILINE)
RE_INTERDIT = re.compile(
    r"github\.com|raw\.githubusercontent\.com|github\b|pull request\b|"
    r"\b(?:AGENTS|PLAN_EDITORIAL|PRODUCTION_INTERNE|RELECTURE_M\d+)\.md\b|"
    r"\bREADME\.md\b",
    re.IGNORECASE,
)


class ErreurAssemblage(ValueError):
    """Erreur de contenu empêchant l'assemblage ou la publication."""


def titre_markdown(texte: str, chemin: Path) -> str:
    correspondance = RE_H1.search(texte)
    if not correspondance:
        raise ErreurAssemblage(f"Titre principal absent dans {chemin}")
    return correspondance.group(1).strip()


def chapitres_disponibles(dossier: Path) -> list[tuple[int, Path]]:
    if not dossier.is_dir():
        raise ErreurAssemblage(f"Dossier des chapitres introuvable : {dossier}")
    chapitres: dict[int, Path] = {}
    for fichier in sorted(dossier.glob("*.md")):
        correspondance = RE_CHAPITRE.fullmatch(fichier.name)
        if not correspondance:
            continue
        numero = int(correspondance.group(1))
        if numero in chapitres:
            raise ErreurAssemblage(f"Deux fichiers pour le chapitre {numero}")
        if not 1 <= numero <= NOMBRE_CHAPITRES:
            raise ErreurAssemblage(f"Chapitre hors programme : {numero}")
        chapitres[numero] = fichier

    if not chapitres:
        raise ErreurAssemblage("Aucun chapitre rédigé n'a été trouvé.")
    attendus = set(range(1, max(chapitres) + 1))
    absents = sorted(attendus - set(chapitres))
    if absents:
        raise ErreurAssemblage(f"Numérotation non continue : chapitres absents {absents}")
    return sorted(chapitres.items())


def corriges_disponibles(dossier: Path, numeros: list[int]) -> list[Path]:
    corriges = []
    for numero in numeros:
        chemin = dossier / f"CORRIGE_M{numero:02d}.md"
        if not chemin.is_file():
            raise ErreurAssemblage(
                f"Corrigé manquant pour le chapitre {numero} : {chemin.name}"
            )
        corriges.append(chemin)
    # Si un corrigé a été créé en avance, il n'entre pas dans l'aperçu.
    return corriges


def statuts_figures(registre: Path) -> dict[str, str]:
    if not registre.is_file():
        raise ErreurAssemblage(f"Registre d'illustrations absent : {registre}")
    statuts: dict[str, str] = {}
    for identifiant, statut in RE_REGISTRE.findall(registre.read_text(encoding="utf-8")):
        if identifiant in statuts:
            raise ErreurAssemblage(f"Figure {identifiant} en double au registre.")
        statuts[identifiant] = statut.strip()
    return statuts


def nettoyer_texte(texte: str) -> str:
    # Les commentaires réservés au maquettiste ne sont pas destinés aux lecteurs.
    return RE_COMMENTAIRE.sub("", texte).strip()


def verifier_contamination(texte: str, chemin: Path) -> None:
    probleme = RE_INTERDIT.search(texte)
    if probleme:
        raise ErreurAssemblage(
            f"Référence de production interdite dans {chemin.name} : {probleme.group(0)}"
        )
    # Les liens de travail ne sont pas nécessaires pour comprendre le livre.
    for cible in re.findall(r"(?<!!)\[[^\]]+\]\(([^)]+)\)", texte):
        if cible.startswith(("http:", "https:")) or cible.endswith(".md"):
            raise ErreurAssemblage(
                f"Lien externe ou Markdown non autorisé dans {chemin.name} : {cible}"
            )


def copier_images(
    texte: str, source: Path, dossier_livre: Path, dossier_sortie: Path
) -> tuple[str, int]:
    """Copie les images locales dans build/assets et réécrit les chemins.

    Les images externes et les chemins qui sortent de livre/ sont refusés.
    Les chemins locaux sont résolus relativement au fichier source.
    """
    copies = 0

    def remplacer(correspondance: re.Match[str]) -> str:
        nonlocal copies
        alt, cible = correspondance.group(1), correspondance.group(2).strip()
        if cible.startswith(("https:", "http:", "data:", "/")):
            raise ErreurAssemblage(f"Image distante ou absolue interdite : {cible}")
        if "#" in cible or "?" in cible:
            raise ErreurAssemblage(f"Ancre/paramètre non pris en charge dans l'image : {cible}")
        original = (source.parent / unquote(cible)).resolve()
        if not original.is_relative_to(dossier_livre.resolve()):
            raise ErreurAssemblage(f"Image hors du répertoire du livre : {cible}")
        if not original.is_file():
            raise ErreurAssemblage(f"Illustration introuvable : {original}")
        empreinte = hashlib.sha256(
            str(original.relative_to(dossier_livre.resolve())).encode("utf-8")
        ).hexdigest()[:10]
        nom = f"{source.stem}-{empreinte}{original.suffix.lower()}"
        destination = dossier_sortie / "assets" / nom
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(original, destination)
        copies += 1
        return f"![{alt}](assets/{nom})"

    return RE_IMAGE.sub(remplacer, texte), copies


def assembler(racine: Path, dossier_sortie: Path, mode: str) -> dict:
    racine = racine.resolve()
    livre = racine / "livre"
    dossier_sortie = dossier_sortie.resolve()

    # Ne jamais écraser les sources du manuscrit.
    if dossier_sortie == livre or dossier_sortie.is_relative_to(livre):
        raise ErreurAssemblage("Le dossier de sortie doit être en dehors de livre/.")
    if not (livre / "00-avant-propos.md").is_file():
        raise ErreurAssemblage("Avant-propos introuvable.")

    chapitres = chapitres_disponibles(livre / "chapitres")
    numeros = [numero for numero, _ in chapitres]
    corriges = corriges_disponibles(livre / "annexes", numeros)
    if mode == "publication" and numeros != list(range(1, NOMBRE_CHAPITRES + 1)):
        raise ErreurAssemblage(
            f"Publication bloquée : {len(numeros)}/{NOMBRE_CHAPITRES} chapitres disponibles."
        )

    documents = [livre / "00-avant-propos.md"]
    documents += [chemin for _, chemin in chapitres]
    documents += corriges
    registre = statuts_figures(livre / "ILLUSTRATIONS_A_PRODUIRE.md")

    morceaux: list[str] = []
    sommaire: list[str] = [
        "# Sommaire du manuscrit",
        "",
        "- Avant-propos",
    ]
    figures: list[str] = []
    images_reelles = 0
    chapitres_titres: list[str] = []
    annexes_titres: list[str] = []

    for chemin in documents:
        contenu = chemin.read_text(encoding="utf-8-sig")
        original = contenu
        h1 = titre_markdown(contenu, chemin)
        identifiants = RE_FIGURE.findall(original)
        if chemin.parent.name == "chapitres":
            numero = int(chemin.name[:2])
            for identifiant in identifiants:
                if not identifiant.startswith(f"{numero}."):
                    raise ErreurAssemblage(
                        f"Figure {identifiant} incorrecte pour chapitre {numero}"
                    )
            chapitres_titres.append(h1)
        elif chemin.parent.name == "annexes":
            annexes_titres.append(h1)

        figures.extend(identifiants)
        contenu = nettoyer_texte(contenu)
        verifier_contamination(contenu, chemin)

        if mode == "publication" and RE_REPERE.search(contenu):
            raise ErreurAssemblage(
                f"Publication bloquée : illustration non réalisée dans {chemin.name}."
            )

        contenu, n_images = copier_images(contenu, chemin, livre, dossier_sortie)
        images_reelles += n_images
        morceaux.append(contenu)
        if chemin.parent.name == "chapitres":
            sommaire.append(f"- {h1}")
        elif chemin.parent.name == "annexes" and len(annexes_titres) == 1:
            sommaire.append("- Annexes et corrigés")

    if len(figures) != len(set(figures)):
        raise ErreurAssemblage("Des identifiants de figures sont répétés.")
    non_referencees = sorted(set(figures) - set(registre))
    if non_referencees:
        raise ErreurAssemblage(f"Figures absentes du registre : {non_referencees}")

    # Une figure déjà intégrée peut ne plus avoir de commentaire de fabrication ;
    # le registre reste alors la source de vérité pour l'autorisation de publier.
    figures_registre = {
        identifiant: statut
        for identifiant, statut in registre.items()
        if identifiant.split(".")[0].isdigit()
        and int(identifiant.split(".")[0]) in numeros
    }
    manquantes_dans_source = set(figures_registre) - set(figures)
    non_validees = sorted(
        identifiant for identifiant, statut in figures_registre.items()
        if statut.upper() != "VALIDÉE"
    )
    if mode == "brouillon":
        non_localisees = sorted(set(non_validees) & manquantes_dans_source)
        if non_localisees:
            raise ErreurAssemblage(
                "Figures à produire non localisées dans les chapitres : "
                + ", ".join(non_localisees)
            )
    else:
        if non_validees:
            raise ErreurAssemblage(
                "Publication bloquée : illustrations non validées au registre : "
                + ", ".join(non_validees)
            )
        if images_reelles < len(figures_registre):
            raise ErreurAssemblage(
                "Publication bloquée : nombre d'images intégrées inférieur "
                f"aux figures du registre ({images_reelles} < {len(figures_registre)})."
            )

    titre = (
        "---\n"
        f'title: "{TITRE}"\n'
        f'subtitle: "{SOUS_TITRE}"\n'
        f'author: "{AUTEUR}"\n'
        "lang: fr-FR\n"
        "---\n\n"
    )
    avertissement = (
        "> **BROUILLON DE TRAVAIL — NON DESTINÉ À LA VENTE.** "
        "Les illustrations indiquées comme manquantes doivent être créées, "
        "vérifiées et intégrées avant la publication.\n\n"
        if mode == "brouillon"
        else ""
    )
    # Le sommaire papier avec numéros de pages est généré par Pandoc.
    # 00-sommaire.md est volontairement exclu : il décrit aussi des chapitres à venir.
    manuscrit = titre + avertissement + "\n\n---\n\n".join(morceaux) + "\n"
    verifier_contamination(manuscrit, dossier_sortie / "manuscrit.md")

    dossier_sortie.mkdir(parents=True, exist_ok=True)
    nom = f"compteur-intelligent-{mode}.md"
    sortie = dossier_sortie / nom
    sortie.write_text(manuscrit, encoding="utf-8")
    sommaire.extend(f"- {x}" for x in annexes_titres)
    (dossier_sortie / "sommaire-dynamique.md").write_text(
        "\n".join(sommaire).rstrip() + "\n", encoding="utf-8"
    )
    rapport = {
        "mode": mode,
        "statut": "BROUILLON - NE PAS DISTRIBUER" if mode == "brouillon" else "À REVÉRIFIER AVANT PUBLICATION",
        "chapitres": len(chapitres),
        "chapitres_attendus": NOMBRE_CHAPITRES,
        "numeros": numeros,
        "annexes": len(corriges),
        "figures_repertoriees_dans_le_manuscrit": len(figures),
        "figures_repertoriees_dans_le_registre": len(figures_registre),
        "figures_encore_non_validees": len(non_validees),
        "images_locales_copiees": images_reelles,
        "sources_incluses": [str(p.relative_to(racine)) for p in documents],
        "sortie": str(sortie.relative_to(racine)) if sortie.is_relative_to(racine) else str(sortie),
    }
    (dossier_sortie / "rapport-assemblage.json").write_text(
        json.dumps(rapport, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    return rapport


def main() -> int:
    analyseur = argparse.ArgumentParser(
        description="Assembler les chapitres et annexes du compteur intelligent."
    )
    analyseur.add_argument(
        "--root", type=Path, default=Path(__file__).resolve().parents[2],
        help="Racine du dépôt (utile pour les tests).",
    )
    analyseur.add_argument(
        "--output-dir", type=Path, default=Path("build/livre"),
        help="Dossier pour le manuscrit et le rapport (par défaut build/livre).",
    )
    analyseur.add_argument(
        "--mode", choices=("brouillon", "publication"), default="brouillon",
        help="Brouillon progressif ou publication bloquée avant validations.",
    )
    args = analyseur.parse_args()
    sortie = args.output_dir
    if not sortie.is_absolute():
        sortie = args.root / sortie
    try:
        resultat = assembler(args.root, sortie, args.mode)
    except (ErreurAssemblage, OSError) as exc:
        print(f"ASSEMBLAGE BLOQUÉ : {exc}", file=sys.stderr)
        return 2
    print(
        f"Assemblage {resultat['mode']} : {resultat['chapitres']}/{NOMBRE_CHAPITRES} "
        f"chapitres, {resultat['annexes']} corrigés, "
        f"{resultat['figures_encore_non_validees']} figures non validées."
    )
    print(f"Manuscrit : {resultat['sortie']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
