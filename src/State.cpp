#include "State.h"
#include "StateMachine.h"
#include "ResourceId.h"

State::State(StateMachine *machine)
    :m_machine(machine)
{

};

State::~State()
{
    std::cout << "Usuwam State" << std::endl;
};

void State::readEvent(sf::Event event)
{

}

void State::update(float deltaTime)
{

}

void State::drawState()
{

}

StateMachine* State::getMachine()
{
    return m_machine;
}

sf::Texture* State::getTexture(Textures::ID id)
{
    return getMachine()->getTexture(id);
}

sf::Font* State::getFont(Fonts::ID id)
{
    return getMachine()->getFont(id);
}
