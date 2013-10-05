#include "Gun.h"

Gun::Gun(GunStats stats, sf::Texture* icon, Bullets::ID bullet_id)
:m_stats(stats)
,m_icon(icon)
,m_bullet_id(bullet_id)
,m_delta_time(0)
{

}

Gun::~Gun()
{

}

void Gun::update(float delta_time)
{
    m_delta_time+=delta_time;
    if(m_stats.actual_ammo == 0 and m_delta_time >= m_stats.reload_time) {
        m_delta_time=0;
        m_stats.actual_ammo=m_stats.max_ammo;
    }
}

bool Gun::canShoot()
{
    return (m_stats.actual_ammo > 0 and m_delta_time >= m_stats.recoil_time);
}

void Gun::shoot()
{
    m_stats.actual_ammo--;
    m_delta_time=0;
}

GunStats Gun::getStats()
{
    return m_stats;
}

Bullets::ID Gun::getBulletId()
{
    return m_bullet_id;
}

sf::Texture* Gun::getIcon()
{
    return m_icon;
}
