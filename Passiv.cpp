//
// Created by kai0 on 14/04/2025.
//
#include <iostream>
#include <string>
#include "Mitglieder.h"
#include "Aktiv.h"
#include "Passiv.h"
#include "Ehrenmitglied.h"

using namespace std;

Passiv::Passiv(string telefon, string betrag)
    : Mitglieder(telefon), Geldbetrag(betrag) {}


void Passiv::Datenout() const {

    cout << "Passiv Mitglied: " << Nachname << ", " << Vorname << ", Geschlecht: " << Geschlecht << ", Tel: " << Telnummer << ", Betrag: " << Geldbetrag << endl;
}


