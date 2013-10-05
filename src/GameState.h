#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "State.h"
#include "Player.h"
#include "GameMap.h"

typedef std::vector<Entity*> VEntitiesPtr;

class GameState : public State {
public:
    GameState(StateMachine *machine);

    ~GameState();

    void readEvent(sf::Event event);

    void update(float deltaTime);

    void drawState();

private:
    void move_entities(float deltaTime);

    GameMap *m_map;
    Player *m_player;
    VEntitiesPtr m_entities;
    BulletCreator m_bullet_creator;
    bool m_shoot;
};


#endif // GAMESTATE_H_INCLUDED
