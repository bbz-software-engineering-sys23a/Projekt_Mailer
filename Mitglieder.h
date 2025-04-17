//
// Created by kai0 on 14/04/2025.
//
#ifndef MITGLIEDER_H
#define MITGLIEDER_H

#include "Texte.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <limits>

using namespace std;

class Mitglieder {
protected:
    static int MitgliedernummerCounter;
    string Mitgliedernummer;
    string Telnummer;
    string Geldbetrag;

public:

    // Persistenz Counter Mitgliedernummer
    static void setCounter(int i);
    static int getCounter();

    // Daten der Mitglieder
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

    // Schreiben eines Datensatzes in die CSV Datei und Filtern der Datensätze in der CSV Datei
    bool schreiben_csv() const;
    static string filtern_csv();
};

#endif
