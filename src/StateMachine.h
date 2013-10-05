#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED

#include "State.h"
#include "ResourceId.h"
#include "ResourceManager.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <map>

typedef std::map<States::ID, State*> StateMap;
typedef std::pair<States::ID, State*> StatePair;

class StateMachine : sf::NonCopyable {
public:
    StateMachine(States::ID state);

    ~StateMachine();

    void runMachine();

    sf::RenderWindow* getWindow();

    sf::Texture* getTexture(Textures::ID id);

    sf::Font* getFont(Fonts::ID id);

    void changeState(States::ID state);

    void loadResources();

private:
    sf::RenderWindow* m_window;
    StateMap m_statemap;
    TextureManager m_texture;
    FontManager m_font;
    States::ID m_actualState;
};

#endif // STATEMACHINE_H_INCLUDED
