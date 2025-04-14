//
// Created by kai0 on 14/04/2025.
//

#ifndef EHRENMITGLIED_H
#define EHRENMITGLIED_H
#include <iostream>
#include <string>
#include "Mitglieder.h"

using namespace std;

class Ehrenmitglied final: public Mitglieder {
public:
    string Geldbetrag;

    Ehrenmitglied(string telefon, string betrag);
    void Datenout() const override;
};
#endif //EHRENMITGLIED_H
