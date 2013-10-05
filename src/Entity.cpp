#include "Entity.h"

Entity::Entity(StateMachine *machine, Entities::ID type)
    :m_machine(machine)
    ,m_active(true)
    ,m_type(type)
{

}

Entity::~Entity()
{

}

void Entity::update(float delta_time)
{

}

StateMachine* Entity::getMachine()
{
    return m_machine;
}

void Entity::setActive(bool active)
{
    m_active=active;
}

bool Entity::isActive()
{
    return m_active;
}

Entities::ID Entity::getType()
{
    return m_type;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
