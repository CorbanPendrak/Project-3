//
// Purpose: Create GUI Progress Bar
//

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <SFML/Graphics.hpp>

class ProgressBar : public sf::Drawable {
private:
    float progress, end;
    float padding, outlineThickness;
    sf::RectangleShape progressShape;
    sf::RectangleShape outlineShape;

public:
    ProgressBar(float end);

    void add();
    void add(int interval);
    void clear();

    float getProgress() const;

    void setSize(sf::Vector2f size);
    void setSize(float x, float y);
    void setColor(sf::Color color, sf::Color backgroundColor = sf::Color::Black);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //PROGRESSBAR_H
