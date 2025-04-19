//
// Created by Timmy Loos on 4/18/25.
//

#ifndef LINEARPROBINGHASHTABLE_H
#define LINEARPROBINGHASHTABLE_H

#include "HashTable.h"
#include <vector>
#include <string>
#include <atomic>

class LinearProbingHashTable : public HashTable {
private:
    struct Entry {
        std::string question;
        std::string state;
        std::vector<float> values;
        bool isOccupied = false;
    };

    std::vector<Entry> table;
    int capacity;
    int size;

    int hash(const std::string& key);      // Hash function
    int probe(const std::string& key);     // Linear probing logic
    void resize();                         // Resize when load factor is high

public:
    explicit LinearProbingHashTable(int initialSize = 200003); // Default large prime capacity
    void load(std::atomic<int>& progress, std::string fileName) override;
    void load(std::atomic<int>& progress, std::string fileName, int maxLoad) override;


    std::vector<float> search(std::string question, std::string state) override;
    std::vector<std::string> searchStates(std::string question) override;
};

#endif // LINEARPROBINGHASHTABLE_H

