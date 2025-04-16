//
// Created by kai0 on 14/04/2025.
//

#ifndef AKTIV_H
#define AKTIV_H

#include "Mitglieder.h"
#include <string>
#include <iostream>

using namespace std;

class Aktiv final : public Mitglieder {
public:
    Aktiv(string telefon);
    void Datenout() const override;
};
#endif

