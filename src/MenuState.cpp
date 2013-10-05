#include "MenuState.h"
#include "StateMachine.h"

#include <cmath>

MenuState::MenuState(StateMachine *machine)
    :State(machine)
    ,m_font(getFont(Fonts::menu))
    ,m_start_button(new TextButton("Start Gry", m_font, 32))
    ,m_exit_button(new TextButton("Wyjscie", m_font, 32))
{
    m_start_button->setPosition(std::floor(400-(m_start_button->getGlobalBounds().width/2)),300);
    m_exit_button->setPosition(std::floor(400-(m_exit_button->getGlobalBounds().width/2)),340);
}

MenuState::~MenuState()
{
    delete m_start_button;
    std::cout << "usuwam MenuState" << std::endl;
}

void MenuState::readEvent(sf::Event event)
{
    if(event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if(m_start_button->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                getMachine()->changeState(States::Game);
            if(m_exit_button->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                getMachine()->getWindow()->close();
        }
    }
}

void MenuState::update(float deltaTime)
{
    m_start_button->update(*(getMachine()->getWindow()));
    m_exit_button->update(*(getMachine()->getWindow()));
}

void MenuState::drawState()
{
    sf::RenderWindow &window=*(getMachine()->getWindow());
    sf::Sprite background(*(getTexture(Textures::menu_background)));

    window.draw(background);
    window.draw(*m_start_button);
    window.draw(*m_exit_button);
}
