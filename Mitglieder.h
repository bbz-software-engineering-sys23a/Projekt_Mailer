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
    string Geldbetrag;

public:

    string Nachname;
    string Vorname;
    string Geschlecht;
    string email;
    string Strasse;
    string Hausnummer;
    string Plz;
    string Wohnort;


    explicit Mitglieder(string telefon);

    
    [[nodiscard]] string getMitgliedernummer() const;
    [[nodiscard]] string getTelnummer() const;
    [[nodiscard]] string getGeldbetrag() const;


    void setGeldbetrag(const string& betrag);


    virtual void Datenout() const;
    virtual ~Mitglieder() = default;
};

#endif
