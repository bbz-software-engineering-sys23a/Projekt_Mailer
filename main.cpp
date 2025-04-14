#include <iostream>
#include <fstream>
#include <vector>

int main()
{


    void csv_speichern() {



        std::ofstream file("output.csv");
        std::vector<std::vector<std::string>> data = {
            {"Name", "Alter", "Stadt"},
            {"John Doe", "29", "New York"},
            {"Jane Smith", "34", "Los Angeles"}
        };

        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); i++) {
                file << row[i];
                if (i < row.size() - 1) file << ",";
            }
            file << "\n";


            return 0;
        }
    }
    ;*/