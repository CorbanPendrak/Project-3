#include <iostream>
#include <SFML/Graphics.hpp>
#include "BasicHashTable.h"
#include <string>


int main() {
    std::string fileName = "Nutrition__Physical_Activity__and_Obesity_-_Behavioral_Risk_Factor_Surveillance_System.csv";

    // Load data
    BasicHashTable basicHashTable;
    basicHashTable.load(fileName, 100);

    // Query
    std::string question = "Percent of adults who engage in no leisure-time physical activity";
    std::string state = "Alaska";
    std::vector<float> result = basicHashTable.search(question, state);

    // Print result
    std::cout << question << "\n\t" << state << "\n\t\t<";
    for (unsigned int i = 0; i < result.size(); i++) {
        if (i == 0) {
            std::cout << result[i];
        }
        std::cout << ", " << result[i];
    }
    std::cout << ">" << std::endl;

    /*
    for (auto question : basicHashTable.data) {
        std::cout << question.first << std::endl;
        for (auto state : question.second) {
             std::cout << "\t" << state.first << std::endl;
            std::cout << "\t\t<";
            for (auto value : state.second) {
                std::cout << value << ", ";
            }
            std::cout << ">\n";
        }
    }
    */
}
