//
// Created by Corban Pendrak on 18-04-2025.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
public:
    virtual ~HashTable() = default;

    virtual void load(std::string fileName) = 0;
    virtual void load(std::string fileName, int maxLoad) = 0;
    virtual std::vector<float> search(std::string question, std::string state) = 0;
};

#endif //HASHTABLE_H
