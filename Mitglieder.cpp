//
// Created by kai0 on 14/04/2025.
//
#include "Mitglieder.h"

int Mitglieder::MitgliedernummerCounter = 1;

Mitglieder::Mitglieder(string telefon) : Telnummer(telefon) {
    Mitgliedernummer = "Mitglied " + to_string(MitgliedernummerCounter);
    MitgliedernummerCounter++;  // Erhöhen des Zählers für die nächste Mitgliedernummer
}
string Mitglieder::getMitgliedernummer() const {
    return Mitgliedernummer;
}
string Mitglieder::getTelnummer() const {
    return Telnummer;
}

void Mitglieder::Datenout() const {
    cout << "Vorname: " << Vorname << endl;
    cout << "Nachname: " << Nachname << endl;
    cout << "Email: " << email << endl;
    cout << "Strasse: " << Strasse << endl;
    cout << "Hausnummer: " << Hausnummer << endl;
    cout << "PLZ: " << Plz << endl;
    cout << "Wohnort: " << Wohnort << endl;
    cout << "Telefonnummer: " << Telnummer << endl;
}




