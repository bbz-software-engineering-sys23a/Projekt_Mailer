//
// Created by kai0 on 14/04/2025.
//
#include "Texte.h"
#include "Mitglieder.h"
#include "Aktiv.h"
#include "Passiv.h"
#include "Ehrenmitglied.h"

int Mitglieder::MitgliedernummerCounter = 1;

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
        "PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht", "Typ", "Mitgliederbeitrag"
    };

    bool dateiExistiert = filesystem::exists(dateiname);
    ofstream datei(dateiname, ios::app);
    if (!datei)
    {
        cerr << "Fehler beim Oeffnen der Datei!" << endl;
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
        cout << "Datei erstellt und Spaltenueberschriften eingefuegt." << endl;
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
    cout << "Adresszeile erfolgreich hinzugefuegt!" << endl;
    return true;
}

string Mitglieder::filtern_csv() {
    string dateiname = "adresse.csv";
    ifstream datei(dateiname);
    if (!datei)
    {
        cerr << "Datei konnte nicht geöffnet werden.\n";
        return "";
    }

    vector<string> spalten = {
        "Mitglied-Nr.", "Name", "Vorname", "Strasse", "Hausnummer",
        "PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht", "Typ", "Mitgliederbeitrag"
    };

    cout << "\nNach welcher Spalte möchten Sie filtern?\n";
    // Für die Filterung nutzen wir die ersten 11 Spalten (letzte Spalte ist Mitgliederbeitrag)
    for (size_t i = 0; i < spalten.size() - 1; ++i)
    {
        cout << i << ": " << spalten[i] << endl;
    }
    int spaltenIndex;
    while (true)
    {
        cout <<"Spaltenindex eingeben (0 bis " << spalten.size() - 2 << "): ";
        cin >> spaltenIndex;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr <<"Ungültige Eingabe. Bitte eine ganze Zahl eingeben.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (spaltenIndex < 0 || spaltenIndex >= static_cast<int>(spalten.size()) - 1)
        {
            cerr << "Ungültiger Spaltenindex. Bitte einen Wert zwischen 0 und " << spalten.size() - 2 << " eingeben.\n";
            continue;
        }
        break;
    }
    cout << "Suchbegriff eingeben: ";
    string suchbegriff;
    getline(cin, suchbegriff);

    string zeile;
    bool ersteZeile = true;
    bool gefunden = false;
    vector<vector<string>> treffer;

    cout << "\n--- Gefundene Einträge ---\n";
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
            for (size_t i = 0; i < felder.size(); ++i)
            {
                cout << felder[i];
                if (i < felder.size() - 1)
                    cout << ";";
            }
            cout << endl;
            gefunden = true;
        }
    }
    if (!gefunden)
    {
        cout << "Keine passenden Einträge gefunden.\n";
        return "";
    }
    // Falls genau ein Treffer besteht, liefern wir diesen zurück.
    if (treffer.size() == 1)
    {
        const auto& zeile = treffer[0];
        string zusammenhang;
        if (zeile.size() >= 11)
        {
            zusammenhang = zeile[0] + ";" + zeile[1] + ";" + zeile[2] + ";" +
                           zeile[3] + ";" + zeile[4] + ";" + zeile[5] + ";" +
                           zeile[6] + ";" + zeile[7] + ";" + zeile[8] + ";" +
                           zeile[9] + ";" + zeile[10];
            if (zeile.size() == 12)
                zusammenhang += ";" + zeile[11];
        }
        return zusammenhang;
    }
    // Bei mehreren Treffern: Detailabfrage durchführen
    if (treffer.size() > 1)
    {
        cout << "\nMehrere Eintraege gefunden.\n";
        cout << "Bitte Mitgliedsnummer eingeben fuer Detailansicht: ";
        string mitgliedsnr;
        getline(cin, mitgliedsnr);
        for (const auto& zeile : treffer)
        {
            if (!zeile.empty() && zeile[0] == mitgliedsnr)
            {
                string zusammenhang;
                if (zeile.size() >= 11)
                {
                    zusammenhang = zeile[0] + ";" + zeile[1] + ";" + zeile[2] + ";" +
                                   zeile[3] + ";" + zeile[4] + ";" + zeile[5] + ";" +
                                   zeile[6] + ";" + zeile[7] + ";" + zeile[8] + ";" +
                                   zeile[9] + ";" + zeile[10];
                    if (zeile.size() == 12)
                        zusammenhang += ";" + zeile[11];
                }
                return zusammenhang;
            }
        }
        cout << "Mitgliedsnummer nicht in der Auswahl gefunden.\n";
        return "";
    }
    return "";
}




