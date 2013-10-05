#ifndef TEXTBUTTON_H_INCLUDED
#define TEXTBUTTON_H_INCLUDED

#include "Button.h"

class TextButton : public Button {
public:
    TextButton(sf::String str, sf::Font* font, unsigned int character_size);

    TextButton(sf::Text text);

    ~TextButton();

    sf::FloatRect getGlobalBounds();

    void update(sf::RenderWindow &window);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Text m_text;
    sf::Text m_text_shadow;
};

#endif // TEXTBUTTON_H_INCLUDED
