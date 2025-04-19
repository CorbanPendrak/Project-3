//
// Created by Adan Alter on 4/19/25
//

#ifndef ORDEREDMAPTABLE_H
#define ORDEREDMAPTABLE_H

#include <string>
#include <vector>
#include <map>

class OrderedMapTable {
private:
    // Map sorted by question and state
    std::map<std::string, std::map<std::string, std::vector<float>>> data;

public:
    // Load entry into the ordered map
    void insert(std::string question, std::string state, float value);

    // Load all data from CSV
    void load(std::string fileName);

    // Load limited number of rows from CSV
    void load(std::string fileName, int maxLoad);

    // Search by question and state
    std::vector<float> search(std::string question, std::string state) ;

    // Search all states for a given question
    std::vector<std::string> searchStates(std::string question) ;

    // optional debugging or GUI display
    std::vector<std::string> getOrderedQuestions() ;
};

#endif // ORDEREDMAPTABLE_H
