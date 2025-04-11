#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(200, 200)), "SFML Test Application");
    sf::Clock clock;
    sf::CircleShape shape;
    shape.setPosition(sf::Vector2f(0.f, 50.f));
    shape.setRadius(50.f);
    shape.setFillColor(sf::Color::Cyan);
    sf::CircleShape shape2;
    shape2.setPosition(sf::Vector2f(150.f, 50.f));
    shape2.setRadius(50.f);
    shape2.setFillColor(sf::Color::Cyan);
    sf::CircleShape shape3;
    shape3.setPosition(sf::Vector2f(50.f, 50.f));
    shape3.setRadius(50.f);
    shape3.setFillColor(sf::Color::Green);
    sf::CircleShape shape4;
    shape4.setPosition(sf::Vector2f(50.f, 200.f));
    shape4.setRadius(50.f);
    shape4.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        float speed = 100.f;
        shape.move(sf::Vector2f(speed * deltaTime, 0.f));
        shape2.move(sf::Vector2f(speed * deltaTime, 0.f));
        shape3.move(sf::Vector2f(0.f, speed * deltaTime));
        shape4.move(sf::Vector2f(0.f, speed * deltaTime));

        if (shape.getPosition().x > window.getSize().x) {
            shape.setPosition(sf::Vector2f(-shape.getRadius() * 2, shape.getPosition().y));
        }
        if (shape2.getPosition().x > window.getSize().x) {
            shape2.setPosition(sf::Vector2f(-shape2.getRadius() * 2, shape2.getPosition().y));
        }
        if (shape3.getPosition().y > window.getSize().y) {
            shape3.setPosition(sf::Vector2f(shape3.getPosition().x, -shape3.getRadius() * 2));
        }
        if (shape4.getPosition().y > window.getSize().y) {
            shape4.setPosition(sf::Vector2f(shape4.getPosition().x, -shape4.getRadius() * 2));
        }

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(shape3);
        window.draw(shape4);
        window.display();
    }
}