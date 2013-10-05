#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED

#include "BulletCreator.h"

struct GunStats {
    unsigned max_ammo;
    unsigned actual_ammo;
    float recoil_time;
    float reload_time;
};

class Gun {
public:
    Gun(GunStats stats, sf::Texture* icon, Bullets::ID bullet_id);

    ~Gun();

    void update(float delta_time);

    bool canShoot();

    void shoot();

    GunStats getStats();

    Bullets::ID getBulletId();

    sf::Texture* getIcon();

private:
    GunStats m_stats;
    sf::Texture *m_icon;
    Bullets::ID m_bullet_id;
    float m_delta_time;
};

#endif // GUN_H_INCLUDED
