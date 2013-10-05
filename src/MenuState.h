#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include "State.h"
#include "TextButton.h"

class StateMachine;

class MenuState : public State {
public:
    MenuState(StateMachine *machine);

    ~MenuState();

    void readEvent(sf::Event event);

    void update(float deltaTime);

    void drawState();

private:
    sf::Font* m_font;
    TextButton* m_start_button;
    TextButton* m_exit_button;
};


#endif // MENUSTATE_H_INCLUDED
