#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;



#include <fstream>
#include <vector>
#include <filesystem>

void datenErfassen();

void datenAusgeben();

void mailVersenden();

string falscheingabeAbfangen(const string &eingabe, int i, const string &text);

bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    bool x = true;
    //const int  mitgliedernummer;
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




    while (x == true) {
        string eingabe;
        int auswahl;
        cout << "Guten Tag. Was möchten sie tun? \n 1) Daten eingeben \n 2) Daten anzeigen \n 3) Ein Mail versenden \n 4) Das Programm beenden\n" << endl;
        cin >> eingabe;

        try {
            auswahl = stoi(eingabe);
        } catch(const invalid_argument&) {
            cout << "Ungültige Eingabe\n" << endl;
            continue;
        } catch(const out_of_range&) {
            cout << "Ungültige Eingabe\n" << endl;
            continue;
        }

        switch (auswahl) {
            case 1:
                cout << "Sie haben Daten eingeben gewählt\n" << endl;
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
            default:
                cout << "Ungültige Eingabe\n" << endl;
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
    string auswahl;

    cout << "Daten Erfassen\n" << endl;
    cout << "Bitte geben Sie den Nachnamen an: " << endl;
    cin >> nachname;
    cout << "\n" << endl;
    cout << "Bitte geben Sie den vorname an: " << endl;
    cin >> vorname;
    cout << "\n" << endl;
    cout << "Bitte geben Sie die strasse an: " << endl;
    cin >> strasse;
    cout << "\n" << endl;
    cout << "Bitte geben Sie die Hausnummer an: " << endl;
    cin >> hausnummer;
    cout << "\n" << endl;
    cout << "Bitte geben Sie die PLZ an: " << endl;
    cin >> plz;
    cout << "\n" << endl;
    cout << "Bitte geben Sie den Wohnort an: " << endl;
    cin >> wohnort;
    cout << "\n" << endl;
    cout << "Bitte geben Sie die E-Mail Adresse an: " << endl;
    cin >> email;
    cout << "\n" << endl;
    cout << "Bitte geben Sie die Telefonnummer beginnend mit 00 an: " << endl;
    cin >> telefonnummer;
    cout << "\n" << endl;
    cout << "Bitte geben sie das Geschlecht des Mitglieds an:\n1) Weiblich\n2) Männlich\n3) Neutral" << endl;
    cin >> eingabe;
    eingabe = falscheingabeAbfangen(eingabe,3,"Bitte geben sie das Geschlecht des Mitglieds an:\n1) Weiblich\n2) Männlich\n3) Neutral");
    cout << "\n" << endl;
    cout << "Bitte geben Sie den Status des Mitglieds an:\n1) Aktives Mitglied\n2) Passives Mitglied\n3) Ehrenmitglied\n" << endl;
    cin >> eingabe;
    eingabe = falscheingabeAbfangen(eingabe,3,"Bitte geben Sie den Status des Mitglieds an:\n1) Aktives Mitglied\n2) Passives Mitglied\n3) Ehrenmitglied\n");
    cout << "\n" << endl;

    schreiben_csv(mitgliedernummer, nachname, vorname, strasse, hausnummer,
        plz,wohnort,email,telefonnummer,geschlecht,typ);
}



void datenAusgeben() {
    cout << "Daten Ausgeben\n" << endl;
}



void mailVersenden() {
    cout << "Mail Versenden\n" << endl;
}


string falscheingabeAbfangen(const string &eingabe, int i,const string &text) {
    int auswahl;
    string input = eingabe;
    while (true) {
        try {
            auswahl = stoi(input);
            } catch(const invalid_argument&) {
                cout << "Ungültige Eingabe\n" << endl;
                cout << text << endl;
                cin >> input;
                continue;
            } catch(const out_of_range&) {
                cout << "Ungültige Eingabe\n" << endl;
                cout << text << endl;
                cin >> input;
                continue;
        }
        if (auswahl < 1 || auswahl > i) {
            cout << "Ungültige Eingabe\n" << endl;
            cout << text << endl;
            cin >> input;
            continue;
        }
        break;
    }
    return to_string(auswahl);
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