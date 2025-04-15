#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>
using namespace std;
int schreiben_csv();
int lesen_csv();

int main()
{
   schreiben_csv();
    return 0;
}
//END main


int schreiben_csv()
{

    //Kontrollieren ob Datei existiert.
    std::string dateiname = "adresse.csv";

    if (std::filesystem::exists(dateiname))
        {
        std::cout << "Die Datei existiert." << std::endl;

        // Öffne Datei im Anhängemodus
        std::ofstream datei(dateiname, std::ios::app);

        // Überprüfen, ob Datei geöffnet werden konnte
        if (!datei)
            {
            std::cerr << "Fehler beim oeffnen der Datei!" << std::endl;
            return 1;
            }

        // Neue Adresszeile (zum Beispiel: Name, Straße, Stadt, PLZ)
        datei  <<"109;Meier;Peter;8200;Schaffhausen;rr@ee;0529988978;Aktiv" <<std::endl;

        // Datei schließen (optional, da der Destruktor das auch macht)
        datei.close();

        std::cout << "Adresszeile erfolgreich hinzugefuegt!" << std::endl;
        return 0 ;
       }
    else
        {
        std::cout << "Die Datei existiert nicht." << std::endl;
        std::ofstream file("adresse.csv");
        std::vector<std::vector<std::string>> data =
            {
            {"Mitglied-Nr.","Name","Vorame","PLZ","Wohnort","E-Mail", "Tel.Nr.","Typ",},
            };

        for (const auto& row : data)
            {
            for (size_t i = 0; i < row.size(); i++)
                {
                file << row[i];
                if (i < row.size() - 1) file << ";";
                }
            file << "\n";
            }
        std::cout<<"Datei erstellt" <<std::endl;
        std::cout<<"Spaltentexte eingefuellt" <<std::endl;
        return 0 ;
        }
}//END int schreiben_csv()

int lesen_csv()
{


}
//END int lesen_csv();















