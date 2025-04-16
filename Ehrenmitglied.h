//
// Created by kai0 on 14/04/2025.
//

#ifndef EHRENMITGLIED_H
#define EHRENMITGLIED_H

#include "Mitglieder.h"
#include <string>
#include <iostream>

using namespace std;

class Ehrenmitglied final : public Mitglieder {
public:
    Ehrenmitglied(string telefon);
    void Datenout() const override;
};

#endif
