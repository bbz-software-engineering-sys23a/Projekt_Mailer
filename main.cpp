#include <iostream>
#include <string>
#include "Mitglieder.h"
#include "Aktiv.h"
#include "Passiv.h"
#include "Ehrenmitglied.h"

using namespace std;

int main() {

    string vorname, nachname, geschlecht, email, strasse, hausnummer, plz, wohnort, telefon, geldbetrag;
    int mitgliedsart;


    cout << "Willkommen zur Registrierung!" << endl;
    
    cout << "Vorname: ";
    cin >> vorname;

    cout << "Nachname: ";
    cin >> nachname;

    cout << "geben sie ihr geschlecht an: ";
    cin >> geschlecht;

    cout << "E-Mail: ";
    cin >> email;

    cout << "Strasse: ";
    cin >> strasse;

    cout << "Hausnummer: ";
    cin >> hausnummer;

    cout << "PLZ: ";
    cin >> plz;

    cout << "Wohnort: ";
    cin >> wohnort;

    cout << "Telefonnummer: ";
    cin >> telefon;

    cout << "Bitte wähle die Art des Mitglieds (1 = Aktiv, 2 = Passiv, 3 = Ehrenmitglied): ";
    cin >> mitgliedsart;


    Mitglieder* mitglied = nullptr;
    if (mitgliedsart == 1) {
        cout << "Geldbetrag fuer aktives Mitglied: ";
        cin >> geldbetrag;
        mitglied = new Aktiv(telefon, geldbetrag);
    } else if (mitgliedsart == 2) {
        cout << "Geldbetrag fuer passives Mitglied: ";
        cin >> geldbetrag;
        mitglied = new Passiv(telefon, geldbetrag);
    } else if (mitgliedsart == 3) {
        cout << "Geldbetrag fuer Ehrenmitglied: ";
        cin >> geldbetrag;
        mitglied = new Ehrenmitglied(telefon, geldbetrag);
    } else {
        cout << "Ungültige Auswahl!" << endl;
        return 1;
    }


    mitglied->Vorname = vorname;
    mitglied->Nachname = nachname;
    mitglied->Geschlecht = geschlecht;
    mitglied->email = email;
    mitglied->Strasse = strasse;
    mitglied->Hausnummer = hausnummer;
    mitglied->Plz = plz;
    mitglied->Wohnort = wohnort;


    mitglied->Datenout();
    delete mitglied;

    return 0;
}