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


//sddsd
using namespace std;

// Definition Deklaration Aufruf Funktionen: i, j = counter / x, y, z = Integer
// Funktionen deklarieren
void datenErfassen();

void datenAusgeben();

void mailVersenden();

int falscheingabeAbfangen(const string &eingabe,int x, int y, const string &text);

bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ);
//K
Mitglieder* mitgliedZuweisen(const string& telefonnummer, const string& typ);
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

        auswahl = falscheingabeAbfangen(eingabe,1,4,Texte::Was + Texte::Auswahl_1);


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
            }
    }
    return 0;
}



void datenErfassen() {

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

bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ)
{
    const std::string dateiname = "adresse.csv";
    const std::vector<std::string> spalten = {
        "Mitglied-Nr.", "Name", "Vorname","Strasse","Hausnummer" ,"PLZ", "Wohnort", "E-Mail", "Tel.Nr.", "Geschlecht","Typ"
    };


    bool dateiExistiert = std::filesystem::exists(dateiname);

    std::ofstream datei(dateiname, std::ios::app);
    if (!datei) {
        std::cerr << "Fehler bein oeffnen der Datei!" << std::endl;
        return false;
    }

    if (!dateiExistiert) {
        for (size_t i = 0; i < spalten.size(); ++i) {
            datei << spalten[i];
            if (i < spalten.size() - 1) datei << ";";
        }
        datei << '\n';
        std::cout << "Datei erstellt und Spaltenueberschriften eingefuegt." << std::endl;
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

    std::cout << "Adresszeile erfolgreich hinzugefuegt!" << std::endl;
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
