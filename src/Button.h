#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Button : public sf::Drawable, public sf::Transformable {
public:
    Button();

    ~Button();

    virtual sf::FloatRect getGlobalBounds();

    virtual void update(sf::RenderWindow &window);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // BUTTON_H_INCLUDED
