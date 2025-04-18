//
// Purpose: Create GUI Progress Bar
//

#include "ProgressBar.h"
#include <iostream>

/*
 * Purpose: Initialize ProgressBar class
 * Input: End size for progress bar
 */
ProgressBar::ProgressBar(float end) {
    this->end = end;
    this->progress = 0;
    this->outlineThickness = 5.f;
    this->padding = 5.f;

    this->outlineShape = sf::RectangleShape();
    this->outlineShape.setOutlineThickness(outlineThickness);
    this->progressShape = sf::RectangleShape();

    // Set Defaults
    setSize(100, 50);
    setColor(sf::Color::Green, sf::Color::Black);
    setPosition(10, 10);
}

/*
 * Purpose: Override draw for easy drawing to window
 * Input: draw with `target.draw(<sprite>, states);`
 */
void ProgressBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // Draw border
    target.draw(outlineShape);
    target.draw(progressShape);
}

/*
 * Purpose: Change color
 * Input: sf::Color
 */
void ProgressBar::setColor(sf::Color color, sf::Color backgroundColor) {
    this->outlineShape.setOutlineColor(color);
    this->outlineShape.setFillColor(backgroundColor);
    this->progressShape.setFillColor(color);
}

/*
 * Purpose: Set size
 * Input: sf::Vector2f
 */
void ProgressBar::setSize(sf::Vector2f size) {
    this->outlineShape.setSize(size - sf::Vector2f(outlineThickness * 2, outlineThickness * 2));
}

/*
 * Purpose: alternative setSize
 * Input: Two floats for position
 */
void ProgressBar::setSize(float x, float y) {
    setSize(sf::Vector2f(x, y));
}

/*
 * Purpose: Increase progress
 */
void ProgressBar::add(int interval) {
    this->progress += interval;

    float scale = static_cast<float>(this->progress) / this->end;
    this->progressShape.setSize(
        sf::Vector2f(
            (this->outlineShape.getSize().x  - padding * 2) * scale,
            this->outlineShape.getSize().y - padding * 2));
}


/*
 * Purpose: Increase progress
 */
void ProgressBar::add() {
    add(1);
}

/*
 * Purpose: Clear progress
 */
void ProgressBar::clear() {
    this->progress = 0;
    this->progressShape.setSize(sf::Vector2f(0, 0));
}

/*
 * Purpose: Change end
 */
void ProgressBar::changeEnd(float end) {
    this->end = end;
    // Recalculate interval
    add(0);
}

/*
 * Purpose: Get progress
 */
float ProgressBar::getProgress() const {
    return progress / end;
}

/*
 * Purpose: Get end
 */
float ProgressBar::getEnd() const {
    return end;
}

/*
 * Purpose: Set position
 */
void ProgressBar::setPosition(sf::Vector2f position) {
    this->outlineShape.setPosition(position + sf::Vector2f(outlineThickness, outlineThickness));
    this->progressShape.setPosition(outlineShape.getPosition() + sf::Vector2f(padding, padding));
}

/*
 * Purpose: Easier method to set position
 */
void ProgressBar::setPosition(float x, float y) {
    setPosition(sf::Vector2f(x, y));
}