#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>

using namespace std;



bool schreiben_csv(string mitgliedernummer,string nachname,string vorname,string strasse,string hausnummer,
    string plz,string wohnort,string email,string telefonnummer,string geschlecht,string typ);

int main()
{
    string mitgliedernummer="2";
    string nachname ="Muellerr";
    string vorname="Peter";
    string geschlecht="w";
    string email="pm@ffch";
    string strasse="Rheinstrasse.";
    string hausnummer="48";
    string plz="8200";
    string wohnort="Schaffhausen";
    string typ="a";
    string telefonnummer = "052111222";

    if (!schreiben_csv( mitgliedernummer,nachname,vorname,strasse, hausnummer,
                        plz, wohnort, email, telefonnummer, geschlecht,typ)) {
        std::cerr << "Ein Fehler ist aufgetreten." << std::endl;
        return 1;
    }
    return 0;
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