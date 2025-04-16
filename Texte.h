//
// Created by steph on 16.04.2025.
//

#ifndef TEXTE_H
#define TEXTE_H

#include <string>
using namespace std;

namespace Texte {
    // Begrüssungen
    const string Begrüssung = "Guten Tag\n";

    // Fragen
    const string Was = "Was möchten sie tun? \n";
    const string Was_2 = "Welche Geldbeträge möchten Sie Anpassen?\n";

    // Auswahlmöglichkeiten
    const string Auswahl_1 = "\n 1) Daten erfassen \n 2) Daten anzeigen \n 3) Ein Mail versenden \n 4) Das Programm beenden \n";
    const string Auswahl_2 = "\n 1) Aktives Mitglied \n 2) Passives Mitglied \n 3) Ehrenmitglied \n";
    const string Auswahl_3 = "\n 1) Weiblich \n 2) Männlich \n 3) Neutral \n";

    // Hilfstexte
    const string Bitte_1 = "Bitte geben Sie ";
    const string Geschlecht = "das Geschlecht des Mitglieds an:  ";
    const string Status = "den Status des Mitglieds an: ";

    // Erfassung
    const string Nachname = "den Nachnamen an: ";
    const string Vorname = "den Vornamen an: ";
    const string Strasse = "die Strasse an: ";
    const string Hausnummer = "die Hausnummer an: ";
    const string PLZ = "die PLZ an";
    const string Wohnort = "den Wohnort an: ";
    const string Mail = "die E-Mail Adresse an: ";
    const string Phone = "die Telefonnummer an: ";
    const string Betrag = "den neuen Betrag an: ";

    // Fehler
    const string Eingabe_ungültig = "Ungültige Eingabe\n";

}



#endif //TEXTE_H
