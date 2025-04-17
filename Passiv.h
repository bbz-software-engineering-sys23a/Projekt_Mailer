//
// Created by kai0 on 14/04/2025.
//

#ifndef PASSIV_H
#define PASSIV_H

#include "Mitglieder.h"
#include "Texte.h"
#include <string>
#include <iostream>

using namespace std;

class Passiv final : public Mitglieder {
public:
    Passiv(string telefon);
    void Datenout() const override;

    static string getDefaultBeitrag();
    static void setDefaultBeitrag(const string &betrag);
private:
    static string defaultBeitrag;
};

#endif
