//
// Purpose: impelement basic hash table
//

#include "BasicHashTable.h"
#include <fstream>
#include <iostream>
#include <sstream>

/*
 * Purpose: Load entire data from file
 */
void BasicHashTable::load(std::atomic<int>& progress, std::string fileName) {
    // Open file
    std::ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Ignore headers
    int count = 0;
    while (std::getline(file, line)) {

        std::getline(file, line);
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        if (row[7].empty() || row[2].empty()) {
            continue;
        } else if (row[10].empty()) {
            row[10] = "0";
        }
        data[row[7]][row[2]].push_back(std::stof(row[10]));
        progress++;
        count++;
        std::cout << count << std::endl;
    }
    progress = -1;
    std::getline(file, line);
    std::cout << line;

    file.close();
}

/*
 * Purpose: Load specific number of dataset
 */
void BasicHashTable::load(std::atomic<int>& progress, std::string fileName, int maxLoad) {
    // Open file
    std::ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Ignore headers

    // Only get maxLoad entries
    int count = 0;
    while(std::getline(file, line)) {
        if (count >= maxLoad) {
            break;
        }

        std::getline(file, line);
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        if (row[7].empty() || row[2].empty()) {
            continue;
        } else if (row[10].empty()) {
            row[10] = "0";
        }
        data[row[7]][row[2]].push_back(std::stof(row[10]));
        count++;
        progress++;
    }
    progress = -1;
}

/*
 * Purpose: Basic search through data
 */
std::vector<float> BasicHashTable::search(std::string question, std::string state) {
    // Key-value pair for question-states
    auto questionStatesPair = data.find(question);

    // Check key exists
    if (questionStatesPair != data.end()) {

        // Key-value pair for state-results
        auto stateResultsPair = questionStatesPair->second.find(state);

        // Check key exists
        if (stateResultsPair != questionStatesPair->second.end()) {

            // Return results
            return stateResultsPair->second;
        }
    }

    // Return empty vector
    return std::vector<float>();
}

/*
 * Purpose: Get available states for question
 */
std::vector<std::string> BasicHashTable::searchStates(std::string question) {
    // Key-value pair for question-states
    auto questionStatesPair = data.find(question);

    // Check key exists
    if (questionStatesPair != data.end()) {
        std::vector<std::string> availableStates;

        for (auto stateResultsPair : questionStatesPair->second) {
            availableStates.push_back(stateResultsPair.first);
        }

        return availableStates;
    }

    // Question not found
    return std::vector<std::string>();
}