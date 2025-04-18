#include <iostream>
#include <SFML/Graphics.hpp>
#include "BasicHashTable.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <thread>

std::string verifyOption(std::string name, const std::vector<std::string> &options, int cols = 1) {
    std::cout << "  " << name << std::endl
                 << "-------------\n";

    for (unsigned int i = 0; i < (options.size() ) / cols; i++) {
        std::cout << i+1 << ". " << options[i];
        for (unsigned int j = 1; j < cols; j++) {
            if (i + ((options.size() + 1) / (j + 1)) >= options.size()) {
                break;
            }
            std::cout << "\t" << i + ((options.size() + 1) / (j+1)) + 1 << ". " << options[i + ((options.size() + 1) / (j+1))] << "\t";
        }
        std::cout << std::endl;
    }
    if (cols > 1) {
        for (unsigned int i = 1; i < cols; i++) {
            std::cout << (options.size() + 1) / cols << ". " << options[(options.size() + 1) / cols - 1];
        }
        std::cout << std::endl;
    }
    std::cout << options.size() + 1 << ". Exit\n";

    std::cout << std::endl;
    std::string option = "";
    while (true) {
        std::cout << name << ": ";
        int optionNumber;
        if (!(std::cin >> optionNumber)) {
            std::cin.clear();
            std::cin.ignore();
        };

        // Starting at 1 with extra exit option
        if (optionNumber > 0 && optionNumber < options.size() + 2) {
            if (optionNumber == options.size() + 1) {
                // Break out of main loop
                return "";
            }
            option = options[optionNumber-1];
            break;
        }
        std::cout << "That is an invalid option, please choose 1-" << options.size() + 1 << "." << std::endl;
    }
    std::cout << std::endl;

    return option;
}

void printDataAnalysis(std::vector<float> data) {
    if (data.size() == 0) {
        std::cout << "There is no data for this query.\n";
        return;
    }

    float min = data[0];
    float max = data[0];
    float sum = 0;
    for (auto elem : data) {
        if (elem < min)
            min = elem;
        if (elem > max)
            max = elem;
        sum += elem;
    }

    std::cout << "\t\tMinimum value: " << std::fixed << std::setprecision(2) << min
        << "\n\t\tMaximum value: " << std::fixed << std::setprecision(2) << max
        << "\n\t\tAverage: " << std::fixed << std::setprecision(2) << sum / data.size()
        << "\n\t\tSample size: " << std::fixed << std::setprecision(2) << data.size() << std::endl;
}

int main() {
    std::string fileName = "Nutrition__Physical_Activity__and_Obesity_-_Behavioral_Risk_Factor_Surveillance_System.csv";
    std::cout << "*-------------------------------------------------------------------------*\n"
                 "| U.S. Department of Health & Human Services Nutritional Dataset Analysis |\n"
                 "*-------------------------------------------------------------------------*\n\n";

    // Load data
    std::vector<std::string> hashTables = {
        "Basic Hash Table",
    };
    std::string hashTableChoice = verifyOption("Hash Table", hashTables);

    HashTable* hashtable;
    if (hashTableChoice == "Basic Hash Table") {
        BasicHashTable basicHashTable;
        hashtable = &basicHashTable;
    } else {
        BasicHashTable basicHashTable;
        hashtable = &basicHashTable;
    }

    // Load data
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(170, 70)), "SFML Test Application");
    std::cout << window.setActive(false);
    //std::thread thread(&renderingThread, &window, &hashtable);
    std::atomic<int> progress(0);
    std::thread worker([&]() {hashtable->load(progress, fileName);});

    // activate the window's context
    std::cout << window.setActive(true);

    // the rendering loop
    hashtable->progressBar->setSize(150, 50);
    hashtable->progressBar->setPosition(10, 10);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        int currentProgress = progress.load();
        if (currentProgress == -1) {
            window.close();
        }

        window.clear();
        hashtable->progressBar->clear();
        hashtable->progressBar->add(currentProgress);
        window.draw(*hashtable->progressBar);
        window.display();
    }

    /*if (worker.joinable()) {
        worker.join();
    }*/

    // Query
    while (true) {
        std::vector<std::string> questions = {
            "Percent of adults who engage in no leisure-time physical activity",
            "Percent of adults who achieve at least 300 minutes a week of moderate-intensity aerobic physical activity or 150 minutes a week of vigorous-intensity aerobic activity (or an equivalent combination)",
            "Percent of adults who achieve at least 150 minutes a week of moderate-intensity aerobic physical activity or 75 minutes a week of vigorous-intensity aerobic activity (or an equivalent combination)",
            "Percent of adults who engage in muscle-strengthening activities on 2 or more days a week",
            "Percent of adults who achieve at least 150 minutes a week of moderate-intensity aerobic physical activity or 75 minutes a week of vigorous-intensity aerobic physical activity and engage in muscle-strengthening activities on 2 or more days a week",
            "Percent of adults aged 18 years and older who have an overweight classification",
            "Percent of adults aged 18 years and older who have obesity",
            "Percent of adults who report consuming fruit less than one time daily",
            "Percent of adults who report consuming vegetables less than one time daily",
            };

        std::string question = verifyOption("Question", questions);
        if (question.empty()) {
            break;
        }

        std::vector<std::string> states = hashtable->searchStates(question);
        std::sort(states.begin(), states.end());
        std::string state = verifyOption("State", states, 2);
        if (state.empty()) {
            continue;
        }
        std::vector<float> result = hashtable->search(question, state);

        // Print result
        std::cout << question << "\n\t" << state << "\n";
        /*
        for (unsigned int i = 0; i < result.size(); i++) {
            if (i == 0) {
                std::cout << std::fixed << std::setprecision(2) << result[i];
            } else if (i % 20 == 0) {
                std::cout << ",\n\t\t " << std::fixed << std::setprecision(2) <<  result[i];
            } else {
                std::cout << ", " << std::fixed << std::setprecision(2) << result[i];
            }
        }
        std::cout << ">" << "\n";
        */
        printDataAnalysis(result);
        std::cout << std::endl;
    }

    std::cout << "Goodbye!" << std::endl;

     return 0;
}


// Todo: add timing
// Todo: add tests