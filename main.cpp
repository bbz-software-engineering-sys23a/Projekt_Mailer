#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    bool x = true;
    while (x == true) {

        int auswahl;
        cout << "Guten Tag. Was möchten sie tun? \n 1) Daten eingeben \n 2) Daten anzeigen \n 3) Das Programm beenden" << endl;
        cin >> auswahl;
        switch (auswahl) {
            case 1:
                cout << "Sie haben Daten eingeben gewählt" << endl;
            break;
            case 2:
                cout << "Sie haben Daten anzeigen gewählt" << endl;
            break;
            case 3:
                x = false;
            break;
        }
    }
    return 0;
}
