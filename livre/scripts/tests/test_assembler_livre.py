# -*- coding: utf-8 -*-
"""Tests autonomes de l'assembleur ; aucune dépendance réseau ou GitHub."""

from __future__ import annotations

import json
import tempfile
import unittest
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from assembler_livre import ErreurAssemblage, assembler


class AssemblageTests(unittest.TestCase):
    def setUp(self):
        self._temp = tempfile.TemporaryDirectory()
        self.addCleanup(self._temp.cleanup)
        self.root = Path(self._temp.name)
        self.livre = self.root / "livre"
        (self.livre / "chapitres").mkdir(parents=True)
        (self.livre / "annexes").mkdir()
        (self.livre / "assets").mkdir()
        (self.livre / "00-avant-propos.md").write_text(
            "# Avant-propos\n\nTexte du lecteur.\n", encoding="utf-8"
        )
        # Un document interne doit rester hors des fichiers assemblés.
        (self.livre / "PLAN_EDITORIAL.md").write_text(
            "# Notes privées de fabrication\n\nCONFIDENTIEL_INTERNE\n",
            encoding="utf-8",
        )
        self.nouveau_chapitre(1)
        self.nouveau_chapitre(2)

    def nouveau_chapitre(self, numero: int, image_validee: bool = False):
        if image_validee:
            visuel = self.livre / "assets" / f"fig-{numero}.svg"
            visuel.write_text(
                '<svg xmlns="http://www.w3.org/2000/svg" width="160" height="40">'
                '<text x="3" y="25">Figure</text></svg>',
                encoding="utf-8",
            )
            texte_figure = (
                f"![Dessin du chapitre {numero}](../assets/fig-{numero}.svg)\n\n"
            )
        else:
            texte_figure = (
                f"<!-- ILLUSTRATION À PRODUIRE — FIGURE {numero}.1\n"
                "Type : infographie.\n"
                "Contenu et annotations : exemple de test.\n"
                f"Légende finale : Figure {numero}.1 — Schéma pédagogique.\n"
                "Texte alternatif : Illustration pédagogique de test.\n"
                "Contraintes : données fictives.\n"
                "Statut : À PRODUIRE.\n"
                "-->\n"
                f"> **[ILLUSTRATION À INSÉRER — Figure {numero}.1]** Schéma.\n\n"
            )
        (self.livre / "chapitres" / f"{numero:02d}-chapitre.md").write_text(
            f"# Chapitre {numero} — Titre\n\n"
            f"Contenu de cours {numero}.\n\n"
            + texte_figure
            + f"**Figure {numero}.1 — Schéma pédagogique.**\n",
            encoding="utf-8",
        )
        (self.livre / "annexes" / f"CORRIGE_M{numero:02d}.md").write_text(
            f"# Annexe du chapitre {numero}\n\nSolution {numero}.\n",
            encoding="utf-8",
        )
        self.maj_registre(image_validee)

    def maj_registre(self, image_validee: bool = False):
        lignes = [
            "# Registre d'illustrations interne",
            "| Figure | Type | Emplacement | Contenu | Statut |",
            "|---|---|---|---|---|",
        ]
        for chapitre in sorted((self.livre / "chapitres").glob("[0-9][0-9]-*.md")):
            n = int(chapitre.name[:2])
            statut = "VALIDÉE" if image_validee else "À PRODUIRE"
            lignes.append(
                f"| **{n}.1** | Photo | §{n}.1 | Schéma pédagogique | {statut} |"
            )
        (self.livre / "ILLUSTRATIONS_A_PRODUIRE.md").write_text(
            "\n".join(lignes) + "\n", encoding="utf-8"
        )

    def sortir(self, mode: str = "brouillon") -> tuple[dict, str]:
        dossier = self.root / "build" / "livre"
        rapport = assembler(self.root, dossier, mode)
        manuscrit = (dossier / f"compteur-intelligent-{mode}.md").read_text(
            encoding="utf-8"
        )
        return rapport, manuscrit

    def test_brouillon_ordonne_chapitres_et_annexes(self):
        rapport, manuscrit = self.sortir()
        self.assertEqual(2, rapport["chapitres"])
        self.assertEqual(2, rapport["annexes"])
        self.assertEqual(2, rapport["figures_encore_non_validees"])
        self.assertLess(
            manuscrit.index("# Chapitre 1"), manuscrit.index("# Chapitre 2")
        )
        self.assertLess(
            manuscrit.index("# Chapitre 2"), manuscrit.index("# Annexe du chapitre 1")
        )
        self.assertIn("BROUILLON DE TRAVAIL", manuscrit)
        self.assertIn("ILLUSTRATION À INSÉRER", manuscrit)
        self.assertNotIn("<!--", manuscrit)
        self.assertNotIn("CONFIDENTIEL_INTERNE", manuscrit)
        self.assertNotIn("PLAN_EDITORIAL", manuscrit)
        sommaire = (self.root / "build" / "livre" / "sommaire-dynamique.md").read_text(
            encoding="utf-8"
        )
        self.assertIn("Chapitre 1", sommaire)
        self.assertIn("Chapitre 2", sommaire)
        with (self.root / "build" / "livre" / "rapport-assemblage.json").open(
            encoding="utf-8"
        ) as f:
            self.assertEqual("brouillon", json.load(f)["mode"])

    def test_corrige_absent_bloque(self):
        (self.livre / "annexes" / "CORRIGE_M02.md").unlink()
        with self.assertRaisesRegex(ErreurAssemblage, "Corrigé manquant"):
            self.sortir()

    def test_chapitre_manquant_bloque(self):
        (self.livre / "chapitres" / "01-chapitre.md").unlink()
        with self.assertRaisesRegex(ErreurAssemblage, "Numérotation non continue"):
            self.sortir()

    def test_publication_bloquee_avant_16_chapitres(self):
        with self.assertRaisesRegex(ErreurAssemblage, "Publication bloquée"):
            self.sortir(mode="publication")

    def test_lien_github_interdit_chez_lecteur(self):
        p = self.livre / "annexes" / "CORRIGE_M01.md"
        p.write_text("# Annexe du chapitre 1\n\nVoir https://github.com/compte/repo\n", encoding="utf-8")
        with self.assertRaisesRegex(ErreurAssemblage, "Référence de production interdite"):
            self.sortir()

    def test_registre_incoherent_bloque(self):
        p = self.livre / "ILLUSTRATIONS_A_PRODUIRE.md"
        p.write_text("# Registre vidé\n", encoding="utf-8")
        with self.assertRaisesRegex(ErreurAssemblage, "Figures absentes du registre"):
            self.sortir()

    def test_publication_requiert_figures_validees_et_images(self):
        for numero in range(3, 17):
            self.nouveau_chapitre(numero)
        with self.assertRaisesRegex(ErreurAssemblage, "illustration non réalisée"):
            self.sortir("publication")

        for numero in range(1, 17):
            self.nouveau_chapitre(numero, image_validee=True)
        rapport, manuscrit = self.sortir("publication")
        self.assertEqual(16, rapport["chapitres"])
        self.assertEqual(16, rapport["images_locales_copiees"])
        self.assertEqual(0, rapport["figures_encore_non_validees"])
        self.assertNotIn("BROUILLON DE TRAVAIL", manuscrit)
        self.assertNotIn("ILLUSTRATION À INSÉRER", manuscrit)
        self.assertIn("assets/", manuscrit)

    def test_registre_valide_sans_images_ne_permet_pas_publication(self):
        for numero in range(3, 17):
            self.nouveau_chapitre(numero)
        # Supprimer les repères mais conserver des fiches validées au registre.
        for chapitre in (self.livre / "chapitres").glob("*.md"):
            t = chapitre.read_text(encoding="utf-8")
            t = t.replace("ILLUSTRATION À INSÉRER", "ILLUSTRATION TRAITÉE")
            chapitre.write_text(t, encoding="utf-8")
        self.maj_registre(image_validee=True)
        with self.assertRaisesRegex(ErreurAssemblage, "nombre d'images intégrées"):
            self.sortir("publication")


if __name__ == "__main__":
    unittest.main()
