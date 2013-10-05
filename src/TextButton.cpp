#include "TextButton.h"

#include <SFML/Window/Mouse.hpp>

#include <iostream>

TextButton::TextButton(sf::String str, sf::Font* font, unsigned int character_size)
    :Button()
{
    m_text.setString(str);
    m_text.setFont(*font);
    m_text.setCharacterSize(character_size);
    m_text.setColor(sf::Color::Black);
}

TextButton::TextButton(sf::Text text)
    :m_text(text)
{
    m_text.setColor(sf::Color::Black);
}

TextButton::~TextButton()
{
    std::cout << "Usuwam textbutton" << std::endl;
}

sf::FloatRect TextButton::getGlobalBounds()
{
    return sf::FloatRect(getPosition(), sf::Vector2f(m_text.getLocalBounds().width, m_text.getLocalBounds().height));
}

void TextButton::update(sf::RenderWindow &window)
{
    m_text_shadow=m_text;
    sf::Vector2i pos=sf::Mouse::getPosition(window);
    if(getGlobalBounds().contains(pos.x, pos.y)) {
        m_text_shadow.move(2,2);
        m_text_shadow.setColor(sf::Color(50,50,50,150));
    } else {
        m_text_shadow.setColor(sf::Color::Transparent);
    }
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform*=getTransform();
    target.draw(m_text_shadow, states);
    target.draw(m_text, states);
}
