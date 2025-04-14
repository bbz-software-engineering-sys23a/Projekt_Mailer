//
// Created by kai0 on 14/04/2025.
//

#ifndef PASSIV_H
#define PASSIV_H
#include <iostream>
#include <string>
#include "Mitglieder.h"

using namespace std;


class Passiv final: public Mitglieder {
public:
    string Geldbetrag;

    Passiv(string telefon, string betrag);
    void Datenout() const override;
};

#endif
