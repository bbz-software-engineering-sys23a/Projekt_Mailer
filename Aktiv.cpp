//
// Created by kai0 on 14/04/2025.
//
#include "Aktiv.h"

Aktiv::Aktiv(string telefon)
    : Mitglieder(telefon) {
    Geldbetrag = "50 Fr.";
}

void Aktiv::Datenout() const {
    cout << "Aktivmitglied: " << Nachname << ", " << Vorname
         << ", Geschlecht: " << Geschlecht
         << ", Tel: " << getTelnummer()
         << ", Betrag: " << getGeldbetrag()
         << ", Mitgliedernr. " << getMitgliedernummer()
         << endl;
}
