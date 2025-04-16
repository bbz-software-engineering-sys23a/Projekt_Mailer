//
// Created by kai0 on 14/04/2025.
//
#include "Passiv.h"

Passiv::Passiv(string telefon)
    : Mitglieder(telefon) {
    Geldbetrag = "30 Fr.";
}

void Passiv::Datenout() const {
    cout << "Passivmitglied: " << Nachname << ", " << Vorname
         << ", Geschlecht: " << Geschlecht
         << ", Tel: " << getTelnummer()
         << ", Betrag: " << getGeldbetrag()
         << ", Mitgliedernr. " << getMitgliedernummer()
         << endl;
}

