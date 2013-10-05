#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Entity.h"

struct BulletStats
{
    float speed;
    unsigned damage;
    float angle;
};

class Bullet : public Entity
{
public:
    Bullet(sf::Texture *texture, BulletStats stats);

    ~Bullet();

    unsigned getDamage();

    void update(float deltaTime);

    sf::FloatRect getGlobalBounds();

    void onCollision(Entity *entity);

    void onMove(float deltaTime);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture *m_icon;
    BulletStats m_stats;
    sf::Vector2f m_size;

};

#endif // BULLET_H_INCLUDED
