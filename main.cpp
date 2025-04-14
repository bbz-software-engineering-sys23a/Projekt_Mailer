#include <iostream>
#include <fstream>
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

    while (x == true) {

        int auswahl;
        cout << "Guten Tag. Was möchten sie tun? \n 1) Daten eingeben \n 2) Daten anzeigen \n 3) Ein Mail versenden \n 4) Das Programm beenden" << endl;
        cout << mitgliedernummer << endl;
        cin >> auswahl;
        switch (auswahl) {
            case 1:
                cout << "Sie haben Daten eingeben gewählt" << endl;
            break;
            case 2:
                cout << "Sie haben Daten anzeigen gewählt" << endl;
            break;
            case 3:
                cout << "Sie haben Email versenden gewählt. \nAn wenn möchten sie ein Mail versenden?" << endl;
            break;
            case 4:
                x = false;
            break;
        }
    }
    return 0;
}
