//
// Created by Adan Alter on 4/19/25.
//

#include "OrderedMapTable.h"
#include <fstream>
#include <iostream>
#include <sstream>


/*
 * Purpose: insert question and state into map
 */
void OrderedMapTable::insert(std::string question, std::string state, float value) {
    data[question][state].push_back(value);
}

/*
 * Purpose: Load entire dataset from CSV
 */
void OrderedMapTable::load(std::atomic<int>& progress, std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip headers
    int count = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (row.size() < 11 || row[7].empty() || row[2].empty() || row[10].empty()) {
            continue;
        }

        std::string question = row[7];
        std::string state = row[2];
        float value = std::stof(row[10]);

        insert(question, state, value);
        progress = ++count;
    }

    progress = -1; // signal done
}

/*
 * Purpose: Load up to maxLoad entries from CSV
 */
void OrderedMapTable::load(std::atomic<int>& progress, std::string fileName, int maxLoad) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip headers
    int count = 0;

    while (std::getline(file, line) && count < maxLoad) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (row.size() < 11 || row[7].empty() || row[2].empty() || row[10].empty()) {
            continue;
        }

        std::string question = row[7];
        std::string state = row[2];
        float value = std::stof(row[10]);

        insert(question, state, value);
        progress = ++count;
    }

    progress = -1; // signal done
}

/*
 * Purpose: basic search through data
 */
std::vector<float> OrderedMapTable::search(std::string question, std::string state)  {
    auto firstIt = data.find(question);
    if (firstIt != data.end()) {
        auto secondIt = firstIt->second.find(state);
        if (secondIt != firstIt->second.end()) {
            return secondIt->second;
        }
    }
    return {};
}

/*
 * Purpose: Get States for Question
 */
std::vector<std::string> OrderedMapTable::searchStates(std::string question)  {
    std::vector<std::string> result;
    auto It = data.find(question);
    if (It != data.end()) {
        for (auto& statePair : It->second) {
            result.push_back(statePair.first);
        }
    }
    return result;
}

/*
 * Purpose: debugging/GUI display (can be removed)
 */
std::vector<std::string> OrderedMapTable::getOrderedQuestions()  {
    std::vector<std::string> result;
    for (auto& q : data) {
        result.push_back(q.first);
    }
    return result;
}
