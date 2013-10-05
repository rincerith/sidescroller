#include "Bullet.h"
#include "Utils.h"

#include <cmath>

Bullet::Bullet(sf::Texture *texture, BulletStats stats)
:Entity(NULL, Entities::Bullet)
,m_icon(texture)
,m_stats(stats)
,m_size(texture->getSize().x, texture->getSize().y)
{

}

Bullet::~Bullet()
{

}

unsigned Bullet::getDamage()
{
    return m_stats.damage;
}

void Bullet::update(float deltaTime)
{

}

sf::FloatRect Bullet::getGlobalBounds()
{
    sf::Transform rotation;
    rotation.rotate(Utils::toDegree(m_stats.angle), getPosition());
    return rotation.transformRect(sf::FloatRect(getPosition(), m_size));
}

void Bullet::onCollision(Entity *entity)
{

}

void Bullet::onMove(float deltaTime)
{
    float x = cos(m_stats.angle) * m_stats.speed * deltaTime;
    float y = sin(m_stats.angle) * m_stats.speed * deltaTime;
    move(x, y);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    sf::Sprite sprite(*m_icon);
    sprite.setRotation(Utils::toDegree(m_stats.angle));
    target.draw(sprite, states);

}
