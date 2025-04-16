#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>
#include <filesystem>

#include "Mitglieder.h"
#include "Ehrenmitglied.h"
#include "Aktiv.h"
#include "Passiv.h"
#include "Texte.h"

using namespace std;

// Definition Deklaration Aufruf Funktionen: i, j = counter / x, y, z = Integer
// Funktionen deklarieren
void datenErfassen();

void datenAusgeben();

void mailVersenden();

int falscheingabeAbfangen(const string &eingabe,int x, int y, const string &text);

int betragAnpassen();

/*bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ);*/

//K
Mitglieder* mitgliedZuweisen(const string& telefonnummer, const string& typ);
//,string plz,string wohnort,string email,string& telefonnummer,string geschlecht,string typ);

//string filtern_csv();

/*
string mitgliedernummer_;
string nachname_;
string vorname_;
string geschlecht_;
string email_;
string strasse_;
string plz_;
string wohnort_;
string typ_;
string telefonnummer_;
string hausnummer_;
string zusammenhang;
*/

string nachname;
string vorname;
string strasse;
string hausnummer;
string plz;
string wohnort;
string email;
string telefonnummer;
string geschlecht;
string typ;

string mitgliedernummer;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    bool x = true;
    //const int  mitgliedernummer;

    string eingabe;
    int auswahl;

    cout << Texte::Begrüssung << endl;
    // Schleife mit Abbruchbedingung Programm
    while (x == true) {

        cout << Texte::Was + Texte::Auswahl_1 << endl;
        cin >> eingabe;

        auswahl = falscheingabeAbfangen(eingabe,1,5,Texte::Was + Texte::Auswahl_1);


        switch (auswahl) {
            case 1:
                cout << "Sie haben Daten erfassen gewählt\n" << endl;
            datenErfassen();
            break;
            case 2:
                cout << "Sie haben Daten anzeigen gewählt\n" << endl;
            datenAusgeben();
            break;
            case 3:
                cout << "Sie haben Email versenden gewählt. \nAn wenn möchten sie ein Mail versenden?\n" << endl;
            mailVersenden();
            break;
            case 4:
                x = false;
            break;
            case 5:
                betragAnpassen();
            break;
            }
    }

/*
cout << "Der String ist :"<<result <<endl;
*/
    return 0;
}



void datenErfassen() {

    /*
    string nachname;
    string vorname;
    string strasse;
    string hausnummer;
    string plz;
    string wohnort;
    string email;
    string telefonnummer;
    string geschlecht;
    string typ;

    string mitgliedernummer;
    */
    int nummer;


    string eingabe;
    int auswahl;

    //cout << "Daten Erfassen\n" << endl;
    cout << Texte::Bitte_1 + Texte::Nachname << endl;
    cin >> nachname;
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Vorname << endl;
    cin >> vorname;
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Strasse << endl;
    cin >> strasse;
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Hausnummer << endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,2,0,Texte::Bitte_1 + Texte::Hausnummer );
    hausnummer = to_string(auswahl);
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::PLZ << endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,2,0,Texte::Bitte_1 + Texte::PLZ);
    plz = to_string(auswahl);
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Wohnort << endl;
    cin >> wohnort;
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Mail << endl;
    cin >> email;
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Phone << endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,2,0,Texte::Bitte_1 + Texte::Phone);
    telefonnummer = "0041" + to_string(auswahl);
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte:: Geschlecht + Texte::Auswahl_3 << endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,1,3,Texte::Bitte_1 + Texte:: Geschlecht + Texte::Auswahl_3);
    switch (auswahl) {
        case 1:
            geschlecht = "W";
        break;
        case 2:
            geschlecht = "M";
        break;
        case 3:
            geschlecht = "N";
        break;
    }
    cout << "\n" << endl;
    cout << Texte::Bitte_1 + Texte::Status + Texte::Auswahl_2<< endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,1,3,Texte::Bitte_1 + Texte::Status + Texte::Auswahl_2);
    switch (auswahl) {
        case 1:
            typ = "A";
        break;
        case 2:
            typ = "P";
        break;
        case 3:
            typ = "E";
        break;
    }
    cout << "\n" << endl;

    schreiben_csv(mitgliedernummer, nachname, vorname, strasse, hausnummer,
        plz,wohnort,email,telefonnummer,geschlecht,typ);
    //K
        Mitglieder* mitglied = mitgliedZuweisen(telefonnummer, typ);
    if (mitglied) {
        mitglied->Datenout();
        delete mitglied;
    } else {
        cout << "Ungültiger Mitgliedstyp – keine Ausgabe möglich." << endl;
    }
}



void datenAusgeben() {
    cout << "Daten Ausgeben\n" << endl;
    if (!schreiben_csv( mitgliedernummer,nachname,vorname,strasse, hausnummer,
                       plz, wohnort, email, telefonnummer, geschlecht,typ))
    {
        cerr << "Ein Fehler ist aufgetreten." << endl;
        return;
    }

    string result =   filtern_csv();
    cout << result << endl;
}



void mailVersenden() {
    cout << "Mail Versenden\n" << endl;
}


int falscheingabeAbfangen(const string &eingabe,int x, int y,const string &text) {
    int auswahl;
    string input = eingabe;
    if (x == 1) {
        while (true) {
            try {
                auswahl = stoi(input);
            } catch(const invalid_argument&) {
                cout << Texte::Eingabe_ungültig << endl;
                cout << text << endl;
                cin >> input;
                continue;
            } catch(const out_of_range&) {
                cout << Texte::Eingabe_ungültig << endl;
                cout << text << endl;
                cin >> input;
                continue;
            }
            if (auswahl < 1 || auswahl > y) {
                cout << Texte::Eingabe_ungültig << endl;
                cout << text << endl;
                cin >> input;
                continue;
            }
            break;
        }
        return auswahl;

    }
    else if (x == 2) {
        while (true) {
            try {
                auswahl = stoi(input);
            }catch(const invalid_argument&) {
                cout << Texte::Eingabe_ungültig << endl;
                cout << text << endl;
                cin >> input;
                continue;
            } catch(const out_of_range&) {
                cout << Texte::Eingabe_ungültig << endl;
                cout << text << endl;
                cin >> input;
                continue;
            }
            if (auswahl < 1) {
                cout << Texte::Eingabe_ungültig << endl;
                cout << text << endl;
                cin >> input;
                continue;
            }
            break;
        }
        return auswahl;
    }
}

int betragAnpassen() {
    string beitragAnpassen;
    string eingabe;
    int auswahl;
    cout << Texte::Was_2 + Texte::Auswahl_2 << endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,1,3,Texte::Was_2 + Texte::Auswahl_2);
}


bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ)
{
    const string dateiname = "adresse.csv";
    const vector<string> spalten =
        {
        "Mitglied-Nr.", "Name", "Vorname","Strasse","Hausnummer" ,"PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht","Typ"
        };

    bool dateiExistiert = filesystem::exists(dateiname);

    ofstream datei(dateiname, std::ios::app);
    if (!datei)
    {
        cerr << "Fehler beim oeffnen der Datei!" << std::endl;
        return false;
    }
    if (!dateiExistiert)
        {
        for (size_t i = 0; i < spalten.size(); ++i)
            {
            datei << spalten[i];
            if (i < spalten.size() - 1) datei << ";";
            }
        datei << '\n';
        cout << "Datei erstellt und Spaltenueberschriften eingefuegt." << std::endl;
        }
    datei   << mitgliedernummer <<";"
            << nachname << ";"
            << vorname << ";"
            << strasse << ";"
            << hausnummer << ";"
            << plz << ";"
            << wohnort << ";"
            << email << ";"
            << telefonnummer << ";"
            << geschlecht << ";"
            << typ << '\n';
    cout << "Adresszeile erfolgreich hinzugefuegt!" << std::endl;
    return true;
}
//K
Mitglieder* mitgliedZuweisen(const string& telefonnummer, const string& typ) {
    if (typ == "A") {
        return new Aktiv(telefonnummer);
    } else if (typ == "P") {
        return new Passiv(telefonnummer);
    } else if (typ == "E") {
        return new Ehrenmitglied(telefonnummer);
    } else {
        return nullptr;
    }
}

//END schreiben_csv()

//Filtern mit auswahl und erstellen zusammengesetzten string
string filtern_csv()
{
    string dateiname = "adresse.csv";
    ifstream datei(dateiname);

    if (!datei)
        {
        cerr << "Datei konnte nicht geoeffnet werden.\n";
        return ""; //Fehlerfall string zurückgeben
        }

    vector<string> spalten =
        {
        "Mitglied-Nr.", "Name", "Vorname", "Strasse", "Hausnummer",
        "PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht", "Typ"
        };

    cout << "\nNach welcher Spalte moechten Sie filtern?\n";
    for (size_t i = 0; i < spalten.size(); ++i)
        {
        cout << i << ": " << spalten[i] << endl;
        }
    int spaltenIndex;
    while (true)
        {
        cout <<"Spaltenindex eingeben (0 bis " << spalten.size() - 1 << "): ";
        cin >> spaltenIndex;

        // Prüfen ob Eingabe überhaupt eine ganze Zahl ist
        if (cin.fail())
            {
            cin.clear(); // Fehlerstatus zurücksetzen
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Puffer leeren
            cerr <<"Ungueltige Eingabe. Bitte eine ganze Zahl eingeben.\n";
            continue; // Zurück zum Anfang der Schleife
            }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Restliche Eingabe leeren

        // Prüfen ob Zahl im gültigen Bereich liegt
        if (spaltenIndex < 0 || spaltenIndex >= static_cast<int>(spalten.size()))
            {
            cerr << "Ungueltiger Spaltenindex. Bitte einen Wert zwischen 0 und "
                 << spalten.size() - 1 << " eingeben.\n";
            continue;
            }
        break; // Alles OK, Schleife verlassen
    }
    cout << "Suchbegriff eingeben: ";
    string suchbegriff;
    getline(cin, suchbegriff);

    string zeile;
    bool ersteZeile = true;
    bool gefunden = false;

    vector<vector<string>> treffer;

    cout << "\n--- Gefundene Eintraege ---\n";

    while (getline(datei, zeile))
        {
        if (ersteZeile)
            {
            ersteZeile = false;
            continue;
            }

        vector<string> felder;
        size_t pos = 0;
        while ((pos = zeile.find(';')) != string::npos)
            {
            felder.push_back(zeile.substr(0, pos));
            zeile.erase(0, pos + 1);
            }
        felder.push_back(zeile);

        if (spaltenIndex < felder.size() && felder[spaltenIndex].find(suchbegriff) != string::npos)
            {
            treffer.push_back(felder);
            for (size_t i = 0; i < felder.size(); ++i)
                {
                cout << felder[i];
                if (i < felder.size() - 1) cout << ";";
                }
            cout << endl;
            gefunden = true;
            }
        }
        if (!gefunden)
            {
            cout << "Keine passenden Eintraege gefunden.\n";
            return "";
            }
    //Falls genau ein Treffer besteht
    if (treffer.size() == 1)
        {
        const auto& zeile = treffer[0];
        string zusammenhang = zeile[0] + ";" + zeile[1] + ";" + zeile[2] + ";" +
                               zeile[3] + ";" + zeile[4] + ";" + zeile[5] + ";" +
                               zeile[6] + ";" + zeile[7] + ";" + zeile[8] + ";" +
                               zeile[9] + ";" + zeile[10];

        return zusammenhang;
        }

    // Bei mehreren Treffern: Detailabfrage durchführen
    if (treffer.size() > 1)
        {
        cout << "\nMehrere Eintraege gefunden.\n";
        cout << "Bitte Mitgliedsnummer eingeben fuer Detailansicht: ";
        string mitgliedsnr;
        getline(cin, mitgliedsnr);

        bool detailGefunden = false;
        for (const auto& zeile : treffer)
            {
            if (zeile[0] == mitgliedsnr)
                {
                string mitgliedernummer_ = zeile[0];
                string nachname_         = zeile[1];
                string vorname_          = zeile[2];
                string strasse_          = zeile[3];
                string hausnummer_       = zeile[4];
                string plz_              = zeile[5];
                string wohnort_          = zeile[6];
                string email_            = zeile[7];
                string telefonnummer_    = zeile[8];
                string geschlecht_       = zeile[9];
                string typ_              = zeile[10];


                //Zusammensetzen der Daten zu einem string
                string zusammenhang = mitgliedernummer_ + ";" + nachname_ + ";" + vorname_ + ";" +
                                      strasse_ + ";" + hausnummer_ + ";" + plz_ + ";" +
                                      wohnort_ + ";" + email_ + ";" + telefonnummer_ + ";" +
                                      geschlecht_ + ";" + typ_;
                detailGefunden = true;
                return zusammenhang;
                }
            }
        if (!detailGefunden)
            {
                    cout << "Mitgliedsnummer nicht in der Auswahl gefunden.\n";
            return ""; // oder einen Hinweis-String zurückgeben
            }
        }
    // Falls keine Treffer gefunden wurden (obwohl das schon abgefangen wurde)
    return "";
}// END filtern()
