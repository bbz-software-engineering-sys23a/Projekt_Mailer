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

void betragAnpassen();


//K
Mitglieder* mitgliedZuweisen(const string& telefonnummer, const string& typ);


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

//Configfile für Mitgliedernummer und Typus
void ladeConfig();
void saveConfig();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    ladeConfig();

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
                cout << Texte::Haupt_Wahl_1 << endl;
            datenErfassen();
            break;
            case 2:
                cout << Texte::Haupt_Wahl_2 << endl;
            datenAusgeben();
            break;
            case 3:
                cout << Texte::Haupt_Wahl_3 << endl;
            mailVersenden();
            break;
            case 4:
                x = false;
                saveConfig();
            break;
            case 5:
                betragAnpassen();
                saveConfig();
            break;
            default:
            break;
        }
    }
    return 0;
}

void ladeConfig() {
    ifstream cfg("settings.cfg");
    if (!cfg) return;
    string line;
    while (getline(cfg,line)) {
        auto p = line.find('=');
        if (p==string::npos) continue;
        string key = line.substr(0,p), val = line.substr(p+1);
        if      (key=="counter") Mitglieder::setCounter(stoi(val));
        else if (key=="A")       Aktiv::setDefaultBeitrag(val);
        else if (key=="P")       Passiv::setDefaultBeitrag(val);
        else if (key=="E")       Ehrenmitglied::setDefaultBeitrag(val);
    }
}

void saveConfig() {
    ofstream cfg("settings.cfg");
    if (!cfg) { cerr<< Texte::Error_Speichern; return; }
    cfg<<"counter="<<Mitglieder::getCounter()<<"\n"
       <<"A="      <<Aktiv::getDefaultBeitrag()      <<"\n"
       <<"P="      <<Passiv::getDefaultBeitrag()     <<"\n"
       <<"E="      <<Ehrenmitglied::getDefaultBeitrag()<<"\n";
}


void datenErfassen() {

    string eingabe;
    int auswahl;

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


    Mitglieder* mitglied = mitgliedZuweisen(telefonnummer, typ);
    if (mitglied) {

        mitglied->Nachname = nachname;
        mitglied->Vorname  = vorname;
        mitglied->Strasse  = strasse;
        mitglied->Hausnummer = hausnummer;
        mitglied->Plz = plz;
        mitglied->Wohnort = wohnort;
        mitglied->email = email;
        mitglied->Geschlecht = geschlecht;
        // Schreibe den Datensatz in die CSV-Datei
        mitglied->schreiben_csv();
        mitglied->Datenout();
        delete mitglied;
        saveConfig();
    } else {
        cout << Texte::Error_Typ + "– " + Texte::Error_Ausgabe << endl;
    }
}



void datenAusgeben() {
    //cout << "Daten Ausgeben\n" << endl;
    string result = Mitglieder::filtern_csv();
    cout << result << "\n" << endl;
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
    return -1;
}

void betragAnpassen() {
    string beitragAnpassen;
    string eingabe;
    int auswahl;
    cout << Texte::Was_2 + Texte::Auswahl_2 + Texte::back_4 << endl;
    cin >> eingabe;
    auswahl = falscheingabeAbfangen(eingabe,1,4,Texte::Was_2 + Texte::Auswahl_2 + Texte::back_4);
    cout << "\n" << endl;

    switch (auswahl) {
        case 1:
            cout << Texte::Betrag_A << Aktiv::getDefaultBeitrag() << "\n" << endl;
            cout << Texte::Bitte_1 + Texte::Betrag << endl;
            cin >> eingabe;
            auswahl = falscheingabeAbfangen(eingabe,2,0,Texte::Bitte_1 + Texte::Betrag);
            beitragAnpassen = to_string(auswahl) + " SFr.";
            Aktiv::setDefaultBeitrag(beitragAnpassen);
            cout << Texte::Betrag_N << Aktiv::getDefaultBeitrag() << "\n"<< endl;
        break;
        case 2:
            cout << Texte::Betrag_A << Passiv::getDefaultBeitrag() << "\n" << endl;
            cout << Texte::Bitte_1 + Texte::Betrag << endl;
            cin >> eingabe;
            auswahl = falscheingabeAbfangen(eingabe,2,0,Texte::Bitte_1 + Texte::Betrag);
            beitragAnpassen = to_string(auswahl)  + " SFr.";
            Passiv::setDefaultBeitrag(beitragAnpassen);
            cout << Texte::Betrag_N << Passiv::getDefaultBeitrag() << "\n"<< endl;
        break;
        case 3:
            cout << Texte::Betrag_A << Ehrenmitglied::getDefaultBeitrag() << "\n" << endl;
            cout << Texte::Bitte_1 + Texte::Betrag << endl;
            cin >> eingabe;
            auswahl = falscheingabeAbfangen(eingabe,2,0,Texte::Bitte_1 + Texte::Betrag);
            beitragAnpassen = to_string(auswahl) + " SFr.";
            Ehrenmitglied::setDefaultBeitrag(beitragAnpassen);
            cout << Texte::Betrag_N << Ehrenmitglied::getDefaultBeitrag() << "\n"<< endl;
        break;
        case 4:
            return;
        break;
    }
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