//
// Created by Corban Pendrak on 18-04-2025.
//

#ifndef BASICHASHTABLE_H
#define BASICHASHTABLE_H

#include <unordered_map>
#include <vector>

#include "HashTable.h"

class BasicHashTable : public HashTable {
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<float>>> data;

public:
    void load(std::string fileName);
    void load(std::string fileName, int maxLoad);

    std::vector<float> search(std::string question, std::string state);
    std::vector<std::string> searchStates(std::string question);
};



#endif //BASICHASHTABLE_H
