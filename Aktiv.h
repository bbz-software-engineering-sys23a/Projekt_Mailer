//
// Created by kai0 on 14/04/2025.
//

#ifndef AKTIV_H
#define AKTIV_H
#include <iostream>
#include <string>
#include "Mitglieder.h"

using namespace std;
class Aktiv final: public Mitglieder {
public:
    string Geldbetrag;
    Aktiv(string telefon, string betrag);
    void Datenout() const override;
};

#endif
