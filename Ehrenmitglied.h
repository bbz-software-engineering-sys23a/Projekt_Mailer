//
// Created by kai0 on 14/04/2025.
//

#ifndef EHRENMITGLIED_H
#define EHRENMITGLIED_H

#include "Mitglieder.h"
#include "Texte.h"
#include <string>
#include <iostream>

using namespace std;

class Ehrenmitglied final : public Mitglieder {
public:
    Ehrenmitglied(string telefon);
    void Datenout() const override;

    static string getDefaultBeitrag();
    static void setDefaultBeitrag(const string &betrag);
private:
    static string defaultBeitrag;
};

#endif
