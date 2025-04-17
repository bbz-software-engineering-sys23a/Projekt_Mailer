//
// Created by kai0 on 14/04/2025.
//
#include "Texte.h"
#include "Aktiv.h"

string Aktiv::defaultBeitrag = "50 Fr.";

Aktiv::Aktiv(string telefon)
    : Mitglieder(telefon) {
    Geldbetrag = defaultBeitrag;
}

void Aktiv::Datenout() const {
    cout << "Aktivmitglied: " << Nachname << ", " << Vorname
         << ", Geschlecht: " << Geschlecht
         << ", Tel: " << getTelnummer()
         << ", Betrag: " << getGeldbetrag()
         << ", Mitgliedernr. " << getMitgliedernummer()
         << endl;
}

string Aktiv::getDefaultBeitrag() {
    return defaultBeitrag;
}

void Aktiv::setDefaultBeitrag(const string &betrag) {
    defaultBeitrag = betrag;
}
