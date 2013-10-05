#include "BulletCreator.h"

BulletCreator::BulletCreator(StateMachine *machine)
:m_machine(machine)
{

}

BulletCreator::~BulletCreator()
{

}

Entity* BulletCreator::createBullet(Bullets::ID id, float angle, sf::Vector2f position)
{
    Entity *bullet;
    BulletStats stats;
    switch(id) {
    case Bullets::test:
        stats.angle=angle;
        stats.damage=1;
        stats.speed=300;
        bullet = new Bullet(m_machine->getTexture(Textures::test_bullet), stats);
        bullet->setPosition(position);
        break;
    default:
        break;
    }
    return bullet;
}
