#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <thread>

#include <SFML/Graphics.hpp>

#include "BasicHashTable.h"
#include "LinearProbingHashTable.h"
#include "OrderedMapTable.h"


sf::Font font("MonaspaceXenon-Regular.otf");
sf::Color buttonColor = sf::Color(0, 119, 182);
sf::Color textColor = sf::Color(0, 180, 216);
sf::Color backgroundColor = sf::Color(202, 240, 248);


int chooseHashTable(HashTable*& hashtable, sf::RenderWindow& window) {
    window = sf::RenderWindow(sf::VideoMode(sf::Vector2u(320, 120)), "Choose Hash Table");

    // Basic Hash Table
    sf::Text basicHashTable(font, "Basic Hash Table", 24);
    basicHashTable.setFillColor(buttonColor);
    basicHashTable.setPosition(sf::Vector2f(20, 20));

    // Linear Probing Hash Table
    sf::Text linearProbingHashTable(font, "Linear Probing Hash Table", 24);
    linearProbingHashTable.setFillColor(buttonColor);
    linearProbingHashTable.setPosition(sf::Vector2f(20, 50));

    // Ordered Map Table
    sf::Text orderedMapTable(font, "Ordered Map Table", 24);
    orderedMapTable.setFillColor(buttonColor);
    orderedMapTable.setPosition(sf::Vector2f(20, 80));

    sf::Clock timer;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return 1;
            }
            if (isButtonPressed(sf::Mouse::Button::Left)) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (basicHashTable.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    hashtable = new BasicHashTable();
                    window.close();
                } else if (linearProbingHashTable.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    hashtable = new LinearProbingHashTable();
                    window.close();
                } else if (orderedMapTable.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    hashtable = new OrderedMapTable();
                    window.close();
                }
            }
        }

        window.clear(backgroundColor);
        window.draw(basicHashTable);
        window.draw(linearProbingHashTable);
        window.draw(orderedMapTable);
        window.display();
    }
    std::cout << "It took you " << std::fixed << std::setprecision(5) << timer.getElapsedTime().asSeconds() << " seconds to decide on a hash table.\n";
    return 0;
}

int loadDataset(HashTable*& hashtable, sf::RenderWindow& window) {
        std::string fileName = "Nutrition__Physical_Activity__and_Obesity_-_Behavioral_Risk_Factor_Surveillance_System.csv";
        // Load Dataset
        window = sf::RenderWindow(sf::VideoMode(sf::Vector2u(230, 120)), "Load dataset");

        sf::Clock timer;

        // Buttons
        sf::Text loadButton(font, "Load Database", 24);
        loadButton.setFillColor(buttonColor);
        loadButton.setPosition(sf::Vector2f(20, 20));
        sf::Clock loadedClock;
        loadedClock.stop();
        bool displayProgress = true;

        // Progress bar
        std::atomic<int> progress(0);
        bool loadedDataset = false;
        hashtable->progressBar->setSize(150, 50);
        hashtable->progressBar->setPosition(40, 60);
        hashtable->progressBar->setColor(textColor, backgroundColor);

        // the rendering loop
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                    return 1;
                }
                if (isButtonPressed(sf::Mouse::Button::Left)) {
                    /// get the local mouse position (relative to a window)
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    if (!loadedDataset && loadButton.getGlobalBounds().contains(sf::Vector2f(localPosition))) {
                        // Run load function
                        timer.restart();
                        std::thread worker([&]() {hashtable->load(progress, fileName);});
                        worker.detach();
                        loadedDataset = true;
                        loadButton.setFillColor(textColor);
                    }
                }
            }

            window.clear(backgroundColor);

            // Display progress bar
            if (loadedClock.getElapsedTime().asSeconds() >= 1) {
                displayProgress = false;
                loadedClock.stop();
                window.close();
            }
            if (displayProgress) {
                int currentProgress = progress.load();
                if (currentProgress == -1) {
                    std::cout << "Loaded dataset in " << std::fixed << std::setprecision(5) << timer.getElapsedTime().asSeconds() << " seconds.\n";
                    loadedClock.start();
                    progress = 104273;
                } else {
                    hashtable->progressBar->clear();
                    hashtable->progressBar->add(currentProgress);
                }
                window.draw(*hashtable->progressBar);
            }

            window.draw(loadButton);

            window.display();
        }
    return 0;
}

int main() {
    std::string fileName = "Nutrition__Physical_Activity__and_Obesity_-_Behavioral_Risk_Factor_Surveillance_System.csv";
    bool devMode = true;

    HashTable* hashtable = nullptr;
    sf::RenderWindow window;
    if (devMode) {
        if (chooseHashTable(hashtable, window) != 0) {
            return 1;
        }
        if (loadDataset(hashtable, window) != 0) {
            return 1;
        };
    } else {
        hashtable = new BasicHashTable();
        std::atomic<int> progress(0);
        hashtable->load(progress, fileName);
    }

    // Display questions
    std::vector<std::pair<std::string, std::string>> questions = {
        {"% adults with no fun physical activity", "Percent of adults who engage in no leisure-time physical activity"},
        {"% adults >300 min/week moderate aerobic or equivalent", "Percent of adults who achieve at least 300 minutes a week of moderate-intensity aerobic physical activity or 150 minutes a week of vigorous-intensity aerobic activity (or an equivalent combination)"},
        {"% adults >150 min/week moderate aerobic or equivalent", "Percent of adults who achieve at least 150 minutes a week of moderate-intensity aerobic physical activity or 75 minutes a week of vigorous-intensity aerobic activity (or an equivalent combination)"},
        {"% adults 2+ day/week strength activities", "Percent of adults who engage in muscle-strengthening activities on 2 or more days a week"},
        {"% adults >150 min/week and 2+ strength activities or equivalent", "Percent of adults who achieve at least 150 minutes a week of moderate-intensity aerobic physical activity or 75 minutes a week of vigorous-intensity aerobic physical activity and engage in muscle-strengthening activities on 2 or more days a week"},
        {"% overweight adults", "Percent of adults aged 18 years and older who have an overweight classification"},
        {"% adults with obesity", "Percent of adults aged 18 years and older who have obesity"},
        {"% adults eat fruit < 1/day ", "Percent of adults who report consuming fruit less than one time daily"},
        {"% adults eat vegetables < 1/day", "Percent of adults who report consuming vegetables less than one time daily"},
        };
    std::vector<sf::Text> questionTexts;
    float j = 0;
    for (const auto& questionPair : questions) {
        sf::Text question(font, questionPair.first, 16);
        question.setPosition(sf::Vector2f(20.f, 20.f + (22.f * j)));
        question.setFillColor(buttonColor);
        questionTexts.push_back(question);
        j++;
    }
    bool questionsVisible = true;
    std::string chosenQuestion = "";
    std::string chosenQuestionNice = "";

    // Display States
    std::vector<std::string> states;
    std::vector<sf::Text> stateTexts;
    bool statesVisible = false;
    std::string chosenState = "";

    // Display Results
    std::vector<sf::Text> results;
    bool resultsVisible = false;

    // Restart query
    sf::Text restart(font, "Search again", 16);
    restart.setFillColor(buttonColor);
    restart.setPosition(sf::Vector2(20.f, 160.f));

    // Timer
    sf::Clock timer;

    window = sf::RenderWindow(sf::VideoMode(sf::Vector2u(700, 240)), "General Nutritional Biases");

    // the rendering loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (isButtonPressed(sf::Mouse::Button::Left)) {
                /// get the local mouse position (relative to a window)
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if (questionsVisible) {
                    for (int i = 0; i < static_cast<int>(questionTexts.size()); i++) {
                        if (questionTexts[i].getGlobalBounds().contains(sf::Vector2<float>(localPosition))) {
                            questionsVisible = false;
                            chosenQuestion = questions[i].second;
                            chosenQuestionNice = questions[i].first;

                            // Display states
                            timer.restart();
                            states.clear();
                            stateTexts.clear();
                            statesVisible = true;
                            states = hashtable->searchStates(chosenQuestion);
                            std::sort(states.begin(), states.end());
                            for (int i = 0; i < states.size(); i++) {
                                sf::Text state(font, states[i], 16);
                                state.setPosition(sf::Vector2f(20.f + (50.f * static_cast<float>(i % 10)), 20.f + (35.f * static_cast<float>(i / 10))));
                                state.setFillColor(buttonColor);
                                stateTexts.push_back(state);
                            }
                            std::cout << "Found states in " << std::fixed << std::setprecision(5) << timer.getElapsedTime().asSeconds() << " seconds.\n";
                        }
                    }
                } else if (statesVisible) {
                    for (int i = 0; i < static_cast<int>(states.size()); i++) {
                        if (stateTexts[i].getGlobalBounds().contains(sf::Vector2f(localPosition))) {
                            statesVisible = false;
                            chosenState = states[i];

                            // Display results
                            timer.restart();
                            results.clear();
                            resultsVisible = true;
                            std::vector<float> data = hashtable->search(chosenQuestion, chosenState);
                            if (data.empty()) {
                                std::cout << "There is no data for this query.\n";
                                break;
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

                            sf::Text question(font, chosenQuestionNice, 16);
                            question.setPosition(sf::Vector2(20.f, 20.f));
                            question.setFillColor(textColor);
                            results.push_back(question);

                            sf::Text state(font, chosenState, 16);
                            state.setPosition(sf::Vector2(20.f, 40.f));
                            state.setFillColor(textColor);
                            results.push_back(state);

                            std::stringstream ss;
                            ss << "Average: " << std::fixed << std::setprecision(2) << sum / data.size();
                            sf::Text average(font, ss.str(), 16);
                            average.setPosition(sf::Vector2(20.f, 80.f));
                            average.setFillColor(textColor);
                            results.push_back(average);

                            ss = std::stringstream();
                            ss << "Minimum value: " << std::fixed << std::setprecision(2) << min;
                            sf::Text minimum(font, ss.str(), 16);
                            minimum.setPosition(sf::Vector2(20.f, 100.f));
                            minimum.setFillColor(textColor);
                            results.push_back(minimum);

                            ss = std::stringstream();
                            ss << "Maximum value: " << std::fixed << std::setprecision(2) << max;
                            sf::Text maximum(font, ss.str(), 16);
                            maximum.setPosition(sf::Vector2(20.f, 120.f));
                            maximum.setFillColor(textColor);
                            results.push_back(maximum);

                            ss = std::stringstream();
                            ss << "Sample size: " << std::fixed << std::setprecision(2) << data.size();
                            sf::Text sampleSize(font, ss.str(), 16);
                            sampleSize.setPosition(sf::Vector2(20.f, 140.f));
                            sampleSize.setFillColor(textColor);
                            results.push_back(sampleSize);

                            std::cout << "Found results in " << std::fixed << std::setprecision(5) << timer.getElapsedTime().asSeconds() << " seconds.\n";
                        }
                    }
                } else if (resultsVisible) {
                    if (restart.getGlobalBounds().contains(sf::Vector2f(localPosition))) {
                        // Display questions
                        resultsVisible = false;
                        questionsVisible = true;
                    }
                }
            }
        }

        window.clear(backgroundColor);

        if (questionsVisible) {
            for (const auto& question : questionTexts) {
                window.draw(question);
            }
        } else if (statesVisible) {
            for (const auto& state : stateTexts) {
                window.draw(state);
            }
        } else if (resultsVisible) {
            for (const auto& result : results) {
                window.draw(result);
            }
            window.draw(restart);
        }

        window.display();
    }

    std::cout << "Goodbye!" << std::endl;

    delete hashtable;

    return 0;
}


// Todo: add tests
// Todo: add other hashtables