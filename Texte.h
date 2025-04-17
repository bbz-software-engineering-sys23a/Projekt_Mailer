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
    const string Filter_Spalte = "\nNach welcher Spalte möchten Sie filtern?\n";

    // Auswahlmöglichkeiten
    const string Auswahl_1 = "\n 1) Daten erfassen \n 2) Daten anzeigen \n 3) Ein Mail versenden \n 4) Das Programm beenden \n";
    const string Auswahl_2 = "\n 1) Aktives Mitglied \n 2) Passives Mitglied \n 3) Ehrenmitglied \n";
    const string Auswahl_3 = "\n 1) Weiblich \n 2) Männlich \n 3) Neutral \n";
    const string back_4 = " 4) Zurück ins Hauptmenu \n";

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
    const string Suchbegriff = "den Suchbegriff ein: ";
    const string Mitgliedsnummer = "die gewünschte Mitgliedsnummer an: ";

    // Fehler
    const string Eingabe_ungültig = "Ungültige Eingabe\n";
    const string Error_Speichern = "Fehler beim Speichern der Einstellungen\n";
    const string Error_Typ = "Ungültiger Mitgliedstyp! ";
    const string Error_Ausgabe = "keine Ausgabe möglich. \n ";
    const string Error_File_Open = "Fehler beim Oeffnen der Datei!\n";
    const string No_Entry = "Keine passenden Einträge gefunden.\n";

    // Rückmeldungen
    const string Angelegt = "Mitglied erfolgreich hinzugefügt!\n";
    const string Angepasst = "Ihre Änderungen wurden gespeichert.\n";
    const string Betrag_A = "Der bisherige Mitgliederbeitrag ist: ";
    const string Betrag_N = "Der neue Mitgliederbeitrag ist: ";
    const string Haupt_Wahl_1 = "Sie haben Daten erfassen gewählt\n";
    const string Haupt_Wahl_2 = "Sie haben Daten anzeigen gewählt\n";
    const string Haupt_Wahl_3 = "Sie haben Email versenden gewählt. \nAn wenn möchten sie ein Mail versenden?\n";
    const string mk_File_ok = "Datei erstellt und Spaltenueberschriften eingefuegt.\n";
    const string Found_Entry_1 = "\nGefundener Eintrag: \n";
    const string Found_Entry_multi = "\nMehrere Einträge gefunden.\n";

}



#endif //TEXTE_H
