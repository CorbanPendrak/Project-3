//
// Created by Timmy Loos on 4/18/25.
//

#ifndef LINEARPROBINGHASHTABLE_H
#define LINEARPROBINGHASHTABLE_H

#include "HashTable.h"
#include <vector>
#include <string>
#include <utility> // for std::pair

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

    int hash(std::string key); // hash function
    int probe(std::string key); // linear probing

    void resize();

public:
    LinearProbingHashTable(int initialSize = 200003); // use a large prime number
    void load(std::string fileName) override;
    void load(std::string fileName, int maxLoad) override;
    std::vector<float> search(std::string question, std::string state) override;
    std::vector<std::string> searchStates(std::string question) override;
};

#endif // LINEARPROBINGHASHTABLE_H
