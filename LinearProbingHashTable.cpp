//
// Created by Timmy Loos on 4/18/25.
//

#include "LinearProbingHashTable.h"
#include <fstream>
#include <sstream>
#include <iostream>

LinearProbingHashTable::LinearProbingHashTable(int initialSize)
    : capacity(initialSize), size(0) {
    table.resize(capacity);
}

int LinearProbingHashTable::hash(std::string key) {
    // djb2 string hash function
    unsigned long hash = 5381;
    for (char c : key)
        hash = ((hash << 5) + hash) + c;
    return hash % capacity;
}

int LinearProbingHashTable::probe(std::string key) {
    int idx = hash(key);
    int originalIdx = idx;

    while (table[idx].isOccupied && (table[idx].question + "|" + table[idx].state) != key) {
        idx = (idx + 1) % capacity;
        if (idx == originalIdx) return -1; // table full
    }

    return idx;
}

void LinearProbingHashTable::load(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip headers

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
        std::string key = question + "|" + state;

        int idx = probe(key);
        if (idx == -1) continue;

        if (table[idx].isOccupied) {
            table[idx].values.push_back(value);
        } else {
            table[idx].question = question;
            table[idx].state = state;
            table[idx].values.push_back(value);
            table[idx].isOccupied = true;
            size++;
        }
    }
}

void LinearProbingHashTable::load(std::string fileName, int maxLoad) {
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
        std::string key = question + "|" + state;

        int idx = probe(key);
        if (idx == -1) continue;

        if (table[idx].isOccupied) {
            table[idx].values.push_back(value);
        } else {
            table[idx].question = question;
            table[idx].state = state;
            table[idx].values.push_back(value);
            table[idx].isOccupied = true;
            size++;
        }

        count++;
    }
}

std::vector<float> LinearProbingHashTable::search(std::string question, std::string state) {
    std::string key = question + "|" + state;
    int idx = hash(key);

    while (table[idx].isOccupied) {
        if ((table[idx].question + "|" + table[idx].state) == key) {
            return table[idx].values;
        }
        idx = (idx + 1) % capacity;
    }

    return {};
}

std::vector<std::string> LinearProbingHashTable::searchStates(std::string question) {
    std::vector<std::string> states;

    for (const auto& entry : table) {
        if (entry.isOccupied && entry.question == question) {
            states.push_back(entry.state);
        }
    }

    return states;
}
