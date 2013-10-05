#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <SFML/System/Vector2.hpp>

namespace Utils
{
    float getAngle(sf::Vector2f pos1, sf::Vector2f pos2);

    float toDegree(float radian);

    float toRadian(float degree);
}

#endif // UTILS_H_INCLUDED
