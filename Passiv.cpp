//
// Created by kai0 on 14/04/2025.
//
#include "Passiv.h"

#include "Texte.h"
#include "Passiv.h"

string Passiv::defaultBeitrag = "30 Fr.";

Passiv::Passiv(string telefon)
    : Mitglieder(telefon) {
    Geldbetrag = defaultBeitrag;
}

void Passiv::Datenout() const {
    cout << "Passivmitglied: " << Nachname << ", " << Vorname
         << ", Geschlecht: " << Geschlecht
         << ", Tel: " << getTelnummer()
         << ", Betrag: " << getGeldbetrag()
         << ", Mitgliedernr. " << getMitgliedernummer()
         << endl;
}

string Passiv::getDefaultBeitrag() {
    return defaultBeitrag;
}

void Passiv::setDefaultBeitrag(const string &betrag) {
    defaultBeitrag = betrag;
}
