#ifndef INTROSTATE_H_INCLUDED
#define INTROSTATE_H_INCLUDED

#include "State.h"

class IntroState : public State {
public:

    IntroState(StateMachine *machine);

    ~IntroState();

    void readEvent(sf::Event event);

    void update(float deltaTime);

    void drawState();

private:

    sf::Texture* m_splashscrn_1_texture;
    sf::Texture* m_sfml_logo_texture;
    float m_time;
    float m_total_time;
    unsigned m_alpha;
    unsigned m_screen;
};



#endif // INTROSTATE_H_INCLUDED
