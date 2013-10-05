#include "Player.h"

Player::Player(StateMachine *machine)
    :Entity(machine, Entities::Player)
    ,m_actual_state(PlayerState::stay)
    ,m_speed(100.0f)
    ,m_actual_gun(0)
{
    load(machine);
}

Player::~Player()
{
    for(MAnimationPtr::iterator it=m_animations.begin(); it!=m_animations.end(); it++) {
        delete it->second;
    }
    for(VGunPtr::iterator it=m_guns.begin(); it!=m_guns.end(); it++) {
        delete *it;
    }
}

void Player::update(float delta_time)
{
    m_animations[m_actual_state]->update(delta_time);
    m_animations[m_actual_state]->setPosition(getPosition());
    m_guns[m_actual_gun]->update(delta_time);
}

float Player::getSpeed()
{
    return m_speed;
}

void Player::setState(PlayerState::ID state)
{
    m_actual_state=state;
}

PlayerState::ID Player::getState()
{
    return m_actual_state;
}

Gun* Player::getGun()
{
    return m_guns[m_actual_gun];
}

void Player::load(StateMachine *machine)
{
    m_animations.insert( PAnimationPtr(PlayerState::move_down, new Animation( machine->getTexture(Textures::player_move_down), 4, 0.2, true )) );
    m_animations.insert( PAnimationPtr(PlayerState::move_left, new Animation( machine->getTexture(Textures::player_move_left), 4, 0.2, true )) );
    m_animations.insert( PAnimationPtr(PlayerState::move_right, new Animation( machine->getTexture(Textures::player_move_right), 4, 0.2, true )) );
    m_animations.insert( PAnimationPtr(PlayerState::move_up, new Animation( machine->getTexture(Textures::player_move_up), 4, 0.2, true )) );
    m_animations.insert( PAnimationPtr(PlayerState::stay, new Animation( machine->getTexture(Textures::player_stay), 1, 0, false )) );

    GunStats stats;
    stats.actual_ammo = 10;
    stats.max_ammo = 10;
    stats.recoil_time = 0.1f;
    stats.reload_time = 1;
    m_guns.push_back( new Gun(stats, machine->getTexture(Textures::test_gun), Bullets::test) );
}

sf::FloatRect Player::getGlobalBounds()
{
    return m_animations[m_actual_state]->getGlobalBounds();
}

void Player::onCollision(Entity *entity)
{

}

void Player::onMove(float deltaTime)
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    Animation *anim = m_animations.at(m_actual_state);
    target.draw(*anim, states);
}
