#include <SFML/Graphics.hpp>
#include "ProgressBar.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(200, 200)), "SFML Test Application");
    sf::Clock clock;
    ProgressBar progressBar(10);
    progressBar.setColor(sf::Color::Green);
    progressBar.setSize(200, 50);
    progressBar.setPosition(0, 75);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() >= 0.5) {
            clock.restart();
            progressBar.add();
            if (progressBar.getProgress() >= 1) {
                progressBar.clear();
            }
        }

        window.clear();
        window.draw(progressBar);
        window.display();
    }
}