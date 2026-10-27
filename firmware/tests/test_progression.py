#!/usr/bin/env python3
"""Regression statique du firmware progressif; ne remplace PAS une compilation."""
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]

def lire(p):
    path = ROOT / p
    assert path.exists(), f"Fichier manquant : {path}"
    return path.read_text(encoding="utf-8")

stages = {
    3: lire("etapes/M03/Compteur_M03/Compteur_M03.ino"),
    4: lire("etapes/M04/Compteur_M04/Compteur_M04.ino"),
    5: lire("etapes/M05/Compteur_M05/Compteur_M05.ino"),
    6: lire("etapes/M06/Compteur_M06/Compteur_M06.ino"),
    7: lire("etapes/M07/Compteur_M07/Compteur_M07.ino"),
    8: lire("etapes/M08/Compteur_M08/Compteur_M08.ino"),
}
for number, source in stages.items():
    for token in ("void setup()", "void loop()", "LED_BUILTIN",
                  "pinMode(", "digitalWrite("):
        assert token in source, f"M{number:02} : fonction de base perdue : {token}"
    assert source.count("{") == source.count("}"), f"M{number}: accolades suspectes"

for token in ("delay(1000)", "digitalWrite(LED_BUILTIN, HIGH)",
              "digitalWrite(LED_BUILTIN, LOW)"):
    assert token in stages[3], f"M03 : demo LED incomplete : {token}"

for token in ("float calculerEnergieKWh(", "void commanderLED(",
              "Serial.begin(9600)", "PUISSANCE_SIMULEE_W",
              "delay(TEMPS_ALLUME_MS)"):
    assert token in stages[4], f"M04 : acquisition C++ incomplete : {token}"

for number in range(5, 9):
    source = stages[number]
    for token in ("traiterBouton(", "traiterCommandes(", "PIN_BOUTON = 2",
                  "millis()", "Serial.begin(9600)"):
        assert token in source, f"M{number:02} : regression bouton/UART : {token}"
    assert "delay(" not in source.split("void loop() {")[-1], (
        f"M{number:02} : loop() est a nouveau bloquee par delay()"
    )

for n in (6, 7, 8):
    source = stages[n]
    for token in ("#define ALEXTECH_PZEM_REEL 0", "struct Mesures",
                  "bool lireMesures(", "isfinite(", "void afficherMesures("):
        assert token in source, f"M{n:02} : regression M06 : {token}"

for n in (7, 8):
    source = stages[n]
    for token in ("#define ALEXTECH_RTC_LCD_REELS 0", "rtc.now()", "lcd.begin(20, 4)",
                  "DATE: A REGLER", "JOUR:"):
        assert token in source, f"M{n:02} : regression M07 : {token}"

for token in ("SuiviEnergieM08 suivi", '#include "EnergieM08.h"',
              "ResultatM08 resultat", "M08_INDEX_REINITIALISE",
              "jourComplet", "moisComplet"):
    assert token in stages[8], f"M08 : moteur absent : {token}"

# Acquis historiques M03-M08; le contrat dynamique controle les versions futures.
import json
manifest = json.loads(lire("manifest.json"))
h = lire("etapes/M08/Compteur_M08/EnergieM08.h")
assert h == lire("tests/EnergieM08.h"), "Moteur historique M08 modifie"
if manifest["latest_firmware_stage"] == 8:
    courant = lire("courant/CompteurIntelligent/CompteurIntelligent.ino")
    assert courant == stages[8], "Firmware courant et snapshot M08 divergents"
    assert h == lire("courant/CompteurIntelligent/EnergieM08.h"), "Moteurs non identiques"
assert lire("tests/test_m08.cpp").count("assert(") >= 20, "Suite C++ incomplete"
print("PASS : 6 etapes M03-M08, transitions verifiees, M08 courant synchronise")
