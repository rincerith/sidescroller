#include "Button.h"

#include <iostream>

Button::Button()
{
}

Button::~Button()
{
    std::cout << "Usuwam button" << std::endl;
}

sf::FloatRect Button::getGlobalBounds()
{
    return sf::FloatRect(0,0,0,0);
}

void Button::update(sf::RenderWindow &window)
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
