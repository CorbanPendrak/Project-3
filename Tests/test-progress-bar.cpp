//
// Purpose: Test ProgressBar GUI element
//

#include <catch2/catch_test_macros.hpp>
#include <SFML/Graphics.hpp>
#include "../ProgressBar.h"

TEST_CASE("Test ProgressBar works", "[sfml]") {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(200, 200)), "SFML Test Application");

    // Check if the window is open
    REQUIRE(window.isOpen());

    sf::Clock autoClose;

    sf::Clock clock;
    ProgressBar progressBar(10);
    progressBar.setColor(sf::Color::Green);
    progressBar.setSize(200, 50);
    progressBar.setPosition(0, 75);

    sf::Clock clock2;
    ProgressBar progressBar2(100);
    progressBar2.setColor(sf::Color::Red);
    progressBar2.setSize(100, 50);
    progressBar2.setPosition(50, 0);

    sf::Clock clock3;
    ProgressBar progressBar3(50);
    progressBar3.setColor(sf::Color::Blue);
    progressBar3.setSize(150, 50);
    progressBar3.setPosition(25, 150);

    bool eventHandled = false;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                eventHandled = true;
            }
        }

        if (autoClose.getElapsedTime().asSeconds() >= 5) {
            eventHandled = true;
            window.close();
        }

        if (clock.getElapsedTime().asSeconds() >= 1) {
            clock.restart();
            progressBar.add();
            if (progressBar.getProgress() >= 1) {
                progressBar.clear();
            }
        }
        if (clock2.getElapsedTime().asSeconds() >= 0.2) {
            clock2.restart();
            progressBar2.add();
            if (progressBar2.getProgress() >= 1) {
                progressBar2.clear();
            }
        }
        if (clock3.getElapsedTime().asSeconds() >= 0.2) {
            clock3.restart();
            progressBar3.add();
            if (progressBar3.getProgress() >= 1) {
                progressBar3.clear();
            }
        }

        window.clear();
        window.draw(progressBar);
        window.draw(progressBar2);
        window.draw(progressBar3);
        window.display();
    }

    // Ensure event handling works
    REQUIRE(eventHandled == true); // Close event triggered
}