//
// Created by kai0 on 14/04/2025.
//
#include "Texte.h"
#include "Mitglieder.h"
#include "Aktiv.h"
#include "Passiv.h"
#include "Ehrenmitglied.h"

#include <vector>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <limits>
#include <iostream>

int Mitglieder::MitgliedernummerCounter = 1;

// Persistenz Counter Mitgliedernummer
void Mitglieder::setCounter(int j) {
    MitgliedernummerCounter = j;
}

int Mitglieder::getCounter() {
    return MitgliedernummerCounter;
}

Mitglieder::Mitglieder(string telefon) : Telnummer(telefon) {
    Mitgliedernummer = to_string(MitgliedernummerCounter++);
    Geldbetrag = "0 Fr.";
}

string Mitglieder::getMitgliedernummer() const {
    return Mitgliedernummer;
}

string Mitglieder::getTelnummer() const {
    return Telnummer;
}

string Mitglieder::getGeldbetrag() const {
    return Geldbetrag;
}

void Mitglieder::setGeldbetrag(const string& betrag) {
    Geldbetrag = betrag;
}

void Mitglieder::Datenout() const {
    cout << "Mitglied: " << Nachname << ", " << Vorname << endl;
    cout << "Geschlecht: " << Geschlecht << endl;
    cout << "E-Mail: " << email << endl;
    cout << "Adresse: " << Strasse << " " << Hausnummer << ", " << Plz << " " << Wohnort << endl;
    cout << "Telefonnummer: " << Telnummer << endl;
    cout << "Mitgliedsnummer: " << Mitgliedernummer << endl;
    cout << "Geldbetrag: " << Geldbetrag << endl;
}

bool Mitglieder::schreiben_csv() const {
    const string dateiname = "adresse.csv";
    const vector<string> spalten = {
        "Mitglied-Nr.", "Name", "Vorname", "Strasse", "Hausnummer",
        "PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht", "Typ"
    };

    bool dateiExistiert = filesystem::exists(dateiname);
    ofstream datei(dateiname, ios::app);
    if (!datei)
    {
        cerr << Texte::Error_File_Open << endl;
        return false;
    }
    if (!dateiExistiert)
    {
        for (size_t i = 0; i < spalten.size(); ++i)
        {
            datei << spalten[i];
            if (i < spalten.size() - 1)
                datei << ";";
        }
        datei << '\n';
        cout << Texte::mk_File_ok << endl;
    }

    // Bestimme den Typ anhand des dynamischen Typs
    string typLetter;
    if (dynamic_cast<const Aktiv*>(this))
        typLetter = "A";
    else if (dynamic_cast<const Passiv*>(this))
        typLetter = "P";
    else if (dynamic_cast<const Ehrenmitglied*>(this))
        typLetter = "E";
    else
        typLetter = "";

    datei << Mitgliedernummer << ";"
          << Nachname << ";"
          << Vorname << ";"
          << Strasse << ";"
          << Hausnummer << ";"
          << Plz << ";"
          << Wohnort << ";"
          << email << ";"
          << Telnummer << ";"
          << Geschlecht << ";"
          << typLetter << ";"
          << Geldbetrag << "\n";
    cout << Texte::Angelegt << endl;
    return true;
}

string Mitglieder::filtern_csv() {
    string dateiname = "adresse.csv";
    ifstream datei(dateiname);
    if (!datei)
    {
        cerr << Texte::Error_File_Open;
        return "";
    }

    vector<string> spalten = {
        "Mitglied-Nr.", "Name", "Vorname", "Strasse", "Hausnummer",
        "PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht", "Typ"
    };

    cout << Texte::Filter_Spalte << endl;

    for (size_t i = 0; i < spalten.size(); ++i)
    {
        cout << i << ": " << spalten[i] << endl;
    }
    int spaltenIndex;
    while (true)
    {
        cout <<"Spaltenindex eingeben (0 bis " << spalten.size() - 1 << "): ";
        cin >> spaltenIndex;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << Texte::Eingabe_ungültig << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (spaltenIndex < 0 || spaltenIndex >= static_cast<int>(spalten.size()))
        {
            cerr << Texte::Eingabe_ungültig <<"Bitte einen Wert zwischen 0 und " << spalten.size() - 1 << " eingeben.\n";
            continue;
        }
        break;
    }
    cout << Texte::Bitte_1 + Texte::Suchbegriff << endl;
    string suchbegriff;
    getline(cin, suchbegriff);

    string zeile;
    bool ersteZeile = true;

    vector<vector<string>> treffer;


    while (getline(datei, zeile))
    {
        if (ersteZeile)
        {
            ersteZeile = false;
            continue;
        }
        vector<string> felder;
        istringstream ss(zeile);
        string token;
        while(getline(ss, token, ';'))
        {
            felder.push_back(token);
        }
        if (spaltenIndex < felder.size() && felder[spaltenIndex].find(suchbegriff) != string::npos)
        {
            treffer.push_back(felder);

        }
    }

    if (treffer.empty())
    {
        cout << Texte::No_Entry << endl;
        return "";
    }
    // Falls genau ein Treffer besteht, liefern wir diesen zurück.
    if (treffer.size() == 1)
    {
        const auto& zeile = treffer[0];
        string zusammenhang;
        string beitrag;

            zusammenhang = zeile[0] + ";" + zeile[1] + ";" + zeile[2] + ";" +
                           zeile[3] + ";" + zeile[4] + ";" + zeile[5] + ";" +
                           zeile[6] + ";" + zeile[7] + ";" + zeile[8] + ";" +
                           zeile[9] + ";" + zeile[10];

        // Dynamisches Anhängen des Mitgliederbeitrags
        string typString = zeile[10];
        if      (typString=="A") beitrag = Aktiv::getDefaultBeitrag();
        else if (typString=="P") beitrag = Passiv::getDefaultBeitrag();
        else if (typString=="E") beitrag = Ehrenmitglied::getDefaultBeitrag();

        // Rückgeben des Datensatzes mit angepasstem Beitrag.
        zusammenhang += ";" + beitrag;

        cout << Texte::Found_Entry_1 << endl;
        return zusammenhang;
    }
    // Bei mehreren Treffern: Detailabfrage durchführen
    if (treffer.size() > 1) {
        cout << Texte::Found_Entry_multi << endl;
        for (const auto& zeile : treffer)
            {
            for (size_t i = 0; i < zeile.size(); ++i)
                {
                cout << zeile[i];
                if (i < zeile.size() - 1)
                    cout << ";";
            }
        cout << endl;
    }


        cout << Texte::Bitte_1 + Texte::Mitgliedsnummer << endl;
        string mitgliedsnr;
        getline(cin, mitgliedsnr);
        for (const auto& zeile : treffer)
        {
            if (!zeile.empty() && zeile[0] == mitgliedsnr)
            {
                string zusammenhang;
                string beitrag;

                zusammenhang = zeile[0] + ";" + zeile[1] + ";" + zeile[2] + ";" +
                    zeile[3] + ";" + zeile[4] + ";" + zeile[5] + ";" +
                        zeile[6] + ";" + zeile[7] + ";" + zeile[8] + ";" +
                            zeile[9] + ";" + zeile[10];

                // Dynamisches Anhängen des Mitgliederbeitrags
                string typString = zeile[10];
                if      (typString=="A") beitrag = Aktiv::getDefaultBeitrag();
                else if (typString=="P") beitrag = Passiv::getDefaultBeitrag();
                else if (typString=="E") beitrag = Ehrenmitglied::getDefaultBeitrag();

                zusammenhang += ";" + beitrag;

                return zusammenhang;
            }
        }
        cout << Texte::No_Entry << endl;
        return "";
    }
    return "";
}




