#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include "ResourceId.h"

#include <SFML/Graphics.hpp>

#include <iostream>

class StateMachine;

class State {
public:
    State(StateMachine *machine);

    virtual ~State();

    virtual void readEvent(sf::Event event);

    virtual void update(float deltaTime);

    virtual void drawState();

    StateMachine* getMachine();

    sf::Texture* getTexture(Textures::ID id);

    sf::Font* getFont(Fonts::ID id);

private:
    StateMachine *m_machine;

};

#endif // STATE_H_INCLUDED
