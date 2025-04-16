//
// Created by kai0 on 14/04/2025.
//
#include "Mitglieder.h"

int Mitglieder::MitgliedernummerCounter = 1;
Mitglieder::Mitglieder(string telefon) : Telnummer(telefon) {
    Mitgliedernummer = "Mitglied " + to_string(MitgliedernummerCounter++);
    Geldbetrag = "0 Fr.";  
}
string Mitglieder::getMitgliedernummer() const {
    return Mitgliedernummer;
}
string Mitglieder::getTelnummer() const {
    return Telnummer;
}
string Mitglieder::getGeldbetrag() const {
    return Geldbetrag;
}
void Mitglieder::setGeldbetrag(const string& betrag) {
    Geldbetrag = betrag;
}
void Mitglieder::Datenout() const {
    cout << "Mitglied: " << Nachname << ", " << Vorname << endl;
    cout << "Geschlecht: " << Geschlecht;
    cout << "E-Mail: " << email << endl;
    cout << "Adresse: " << Strasse << " " << Hausnummer << ", " << Plz << " " << Wohnort << endl;
    cout << "Telefonnummer: " << Telnummer << endl;
    cout << "Mitgliedsnummer: " << Mitgliedernummer << endl;
    cout << "Geldbetrag: " << Geldbetrag << endl;
}



