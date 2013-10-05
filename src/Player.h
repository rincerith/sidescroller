#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Entity.h"
#include "Animation.h"
#include "Gun.h"

namespace PlayerState {
enum ID {
    move_up,
    move_left,
    move_right,
    move_down,
    stay
};
}

typedef std::map<PlayerState::ID, Animation*> MAnimationPtr;
typedef std::pair<PlayerState::ID, Animation*> PAnimationPtr;
typedef std::vector<Gun*> VGunPtr;

class Player : public Entity {
public:
    Player(StateMachine *machine);

    ~Player();

    void update(float delta_time);

    float getSpeed();

    void setState(PlayerState::ID state);

    PlayerState::ID getState();

    Gun* getGun();

    sf::FloatRect getGlobalBounds();

    void onCollision(Entity *entity);

    void onMove(float deltaTime);

private:
    void load(StateMachine *machine);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    MAnimationPtr m_animations;
    PlayerState::ID m_actual_state;
    float m_speed;
    VGunPtr m_guns;
    int m_actual_gun;
};

#endif // PLAYER_H_INCLUDED
