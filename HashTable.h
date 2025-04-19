//
// Created by Corban Pendrak on 18-04-2025.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "ProgressBar.h"
#include <atomic>

class HashTable {
public:
    ProgressBar* progressBar;

    HashTable() {
        this->progressBar = new ProgressBar(104273);
    }; // entries in Nutrition__Physical_Activity__and_Obesity_-_Behavioral_Risk_Factor_Surveillance_System.csv
    virtual ~HashTable() = default;

    virtual void load(std::atomic<int>& progress, std::string fileName) = 0;
    virtual void load(std::atomic<int>& progress, std::string fileName, int maxLoad) = 0;
    virtual std::vector<float> search(std::string question, std::string state) = 0;
    virtual std::vector<std::string> searchStates(std::string question) = 0;
};

#endif //HASHTABLE_H
