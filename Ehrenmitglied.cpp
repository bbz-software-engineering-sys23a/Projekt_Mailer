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


Ehrenmitglied::Ehrenmitglied(string telefon, string betrag)
    : Mitglieder(telefon), Geldbetrag(betrag) {}


void Ehrenmitglied::Datenout() const {
    cout << "Ehrenmitglied: " << Nachname << ", " << Vorname << ", Tel: " << Telnummer << ", Betrag: " << Geldbetrag << endl;
}