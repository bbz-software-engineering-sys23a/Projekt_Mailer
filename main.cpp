#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>

using namespace std;

bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
                    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ);

string filtern_csv();

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

int main()
{
    string mitgliedernummer="2";
    string nachname ="Meierr";
    string vorname="Peter";
    string geschlecht="w";
    string email="pm@ffch";
    string strasse="Rheinstrasse.";
    string hausnummer="50";
    string plz="8200";
    string wohnort="Schaffhausen";
    string typ="a";
    string telefonnummer = "052111222";

   /*if (!schreiben_csv( mitgliedernummer,nachname,vorname,strasse, hausnummer,
                        plz, wohnort, email, telefonnummer, geschlecht,typ))
    {
        cerr << "Ein Fehler ist aufgetreten." << std::endl;
        return 1;
    }
*/

    string result =   filtern_csv();
    cout << "Der String ist :1"<<result <<endl;
    return 0;
}//END main

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
    if (!datei) {
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
}//END schreiben_csv()

//Filtern mit auswahl und erstellen zusammengesetzten string
string filtern_csv() {
    string dateiname = "adresse.csv";
    ifstream datei(dateiname);
    int i;

    if (!datei)
    {
        cerr << "Datei konnte nicht geoeffnet werden.\n";
        //return 0;
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
        if (cin.fail()) {
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

    while (getline(datei, zeile)) {
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
            //return 0;
        }



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
                        // 🟢 Werte in Variablen abfüllen
                        string mitgliedernummer_   = zeile[0];
                        string nachname_           = zeile[1];
                        string vorname_            = zeile[2];
                        string strasse_            = zeile[3];
                        string hausnummer_         = zeile[4];
                        string plz_                = zeile[5];
                        string wohnort_            = zeile[6];
                        string  email_             = zeile[7];
                        string telefonnummer_      = zeile[8];
                        string geschlecht_         = zeile[9];
                        string typ_                = zeile[10];
                        cout<<mitgliedernummer_<<"tttt"<<endl;
                        zusammenhang =  mitgliedernummer_ + " " + nachname_ + " "+vorname_ + " " + strasse_
                        + " " + hausnummer_ + " "+ plz_ + " " + wohnort_ + " "+email_ + " " + telefonnummer_
                        + " "+ geschlecht_ + " " + typ_ ;

                        detailGefunden = true;
                        return zusammenhang;
                        // break;
                    }
                }
                if (!detailGefunden)
                {
                    cout << "Mitgliedsnummer nicht in der Auswahl gefunden.\n";
                    //return 0;
                }
            }

    }// END filtern()
