//
// Created by kai0 on 14/04/2025.
//
#include "Ehrenmitglied.h"

Ehrenmitglied::Ehrenmitglied(string telefon)
    : Mitglieder(telefon) {
    Geldbetrag = "10 Fr.";
}

void Ehrenmitglied::Datenout() const {
    cout << "Ehrenmitglied: " << Nachname << ", " << Vorname
         << ", Geschlecht: " << Geschlecht
         << ", Tel: " << getTelnummer()
         << ", Betrag: " << getGeldbetrag()
         << ", Mitgliedernr. " << getMitgliedernummer()
         << endl;
}
