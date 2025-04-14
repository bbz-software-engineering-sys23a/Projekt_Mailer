//
// Created by kai0 on 14/04/2025.
//
#ifndef MITGLIEDER_H
#define MITGLIEDER_H
#include <string>
#include <iostream>

using namespace std;

class Mitglieder {
protected:
    static int MitgliedernummerCounter;
    string Mitgliedernummer;
    string Telnummer;

public:
    string Nachname;
    string Vorname;
    string email;
    string Strasse;
    string Hausnummer;
    string Plz;
    string Wohnort;

  explicit Mitglieder(string telefon);

  [[nodiscard]]  string getMitgliedernummer() const;
   [[nodiscard]]  string getTelnummer() const;

    virtual void Datenout() const;
    virtual ~Mitglieder() = default;
};
#endif