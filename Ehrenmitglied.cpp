//
// Created by kai0 on 14/04/2025.
//

#include "Texte.h"
#include "Ehrenmitglied.h"

string Ehrenmitglied::defaultBeitrag = "10 Fr.";

Ehrenmitglied::Ehrenmitglied(string telefon)
    : Mitglieder(telefon) {
    Geldbetrag = defaultBeitrag;
}

void Ehrenmitglied::Datenout() const {
    cout << "Ehrenmitglied: " << Nachname << ", " << Vorname
         << ", Geschlecht: " << Geschlecht
         << ", Tel: " << getTelnummer()
         << ", Betrag: " << getGeldbetrag()
         << ", Mitgliedernr. " << getMitgliedernummer()
         << endl;
}

string Ehrenmitglied::getDefaultBeitrag() {
    return defaultBeitrag;
}

void Ehrenmitglied::setDefaultBeitrag(const string &betrag) {
    defaultBeitrag = betrag;
}
