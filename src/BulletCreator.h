#ifndef BULLETCREATOR_H_INCLUDED
#define BULLETCREATOR_H_INCLUDED

#include "Bullet.h"

class StateMachine;
class Entity;

namespace Bullets {
enum ID {
    test
};
}

class BulletCreator
{
public:
    BulletCreator(StateMachine *machine);

    ~BulletCreator();

    Entity* createBullet(Bullets::ID id, float angle, sf::Vector2f position);

private:
    StateMachine *m_machine;
};



#endif // BULLETCREATOR_H_INCLUDED
