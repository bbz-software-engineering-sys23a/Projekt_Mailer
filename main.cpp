
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;




int main()
{
    SetConsoleOutputCP(CP_UTF8);

    bool x = true;
    int mitgliedernummer = 0;
    string vorname;
    string nachname;
    int plz;
    string wohnohrt;
    string mail;
    string telefon;
    string typ;

    void datenErfassen();
    void datenAusgeben();
    void mailVersenden();

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
    cout << "Daten Erfassen\n" << endl;
}



void datenAusgeben() {
    cout << "Daten Ausgeben\n" << endl;
}



void mailVersenden() {
    cout << "Mail Versenden\n" << endl;
}