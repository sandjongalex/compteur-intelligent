#!/usr/bin/env python3
"""Barriere statique M09 pour corrections P1/P2; la CI compile aussi l'AVR."""
from pathlib import Path
p=Path(__file__).resolve().parents[1]
ino=(p/"courant/CompteurIntelligent/CompteurIntelligent.ino").read_text()
snapshot=(p/"etapes/M09/Compteur_M09/Compteur_M09.ino").read_text()
assert ino==snapshot, "Le snapshot M09 doit egaler le firmware courant"
sim=(p/"courant/CompteurIntelligent/SimulationM09.h").read_text()
assert sim==(p/"etapes/M09/Compteur_M09/SimulationM09.h").read_text()
h=(p/"courant/CompteurIntelligent/EnergieM08.h").read_text()
assert h==(p/"etapes/M09/Compteur_M09/EnergieM08.h").read_text()
assert "#if ALEXTECH_PZEM_REEL && !ALEXTECH_RTC_LCD_REELS" in ino
assert "DATE_SIMULEE" in ino and "DATE_DS3231" in ino
assert "OrigineDateM09 lireDate(" in ino
assert "simulation.indexWh(millis())" in ino
assert "SoftwareSerial portPzem(10, 11)" in ino
assert "92200UL*deltaMs" in sim
assert "M08_CUMUL_SATURE" in h
assert "GSM" in (p.parent/"AGENTS.md").read_text()
print("PASS: synchronisation M09, horodatage qualifie, simulation et PZEM D10/D11")
