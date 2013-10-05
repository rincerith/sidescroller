#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "StateMachine.h"

namespace Entities
{
    enum ID
    {
        Player,
        Bullet
    };
}


class Entity : public sf::Drawable, public sf::Transformable {
public:
    Entity(StateMachine *machine, Entities::ID type);

    ~Entity();

    virtual void update(float delta_time);

    StateMachine* getMachine();

    void setActive(bool active);

    bool isActive();

    virtual sf::FloatRect getGlobalBounds() = 0;

    virtual void onCollision(Entity *entity) = 0;

    Entities::ID getType();

    virtual void onMove(float deltaTime) = 0;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    StateMachine *m_machine;
    bool m_active;
    Entities::ID m_type;
};



#endif // ENTITY_H_INCLUDED

