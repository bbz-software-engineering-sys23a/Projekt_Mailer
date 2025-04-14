//
// Created by kai0 on 14/04/2025.
//

#ifndef MITGLIEDER_H
#define MITGLIEDER_H
#include <string>

using namespace std;

class Mitglieder {
public:
    string Nachname;
    string Vorname;
    string Mitgliedernummer;
    string email;
    string Strasse;
    string Hausnummer;
    string Plz;
    string Wohnort;

    virtual void Datenout() const;
    virtual ~Mitglieder() = default;

    private :
        string Telnummer;

};
class Aktiv: public Mitglieder {
public:
    string Geldbetrag;

    void Datenout() const override;
};
class Passiv: public Mitglieder {
public:
    string Geldbetrag;
    void Datenout() const override;
};
    class Ehrenmitglied: public Mitglieder {
    public:
        string Geldbetrag;
        void Datenout() const override;
    };

#endif //MITGLIEDER_H
