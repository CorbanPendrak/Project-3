//
// Created by Adan Alter on 4/19/25
//

#ifndef ORDEREDMAPTABLE_H
#define ORDEREDMAPTABLE_H

#include "HashTable.h"
#include <map>
#include <string>
#include <vector>

class OrderedMapTable : public HashTable {
private:
    // question -> state -> vector<float>
    std::map<std::string, std::map<std::string, std::vector<float>>> data;

public:
    OrderedMapTable() = default;
    ~OrderedMapTable() override = default;

    // Insert single value (for internal use)
    void insert(std::string question, std::string state, float value);

    // Required overrides
    void load(std::atomic<int>& progress, std::string fileName) override;
    void load(std::atomic<int>& progress, std::string fileName, int maxLoad) override;
    std::vector<float> search(std::string question, std::string state) override;
    std::vector<std::string> searchStates(std::string question) override;

    // Optional: for GUI/debugging
    std::vector<std::string> getOrderedQuestions();
};

#endif // ORDEREDMAPTABLE_H
