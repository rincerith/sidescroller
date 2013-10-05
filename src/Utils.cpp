#include "Utils.h"

#include <cmath>

float Utils::getAngle(sf::Vector2f pos1, sf::Vector2f pos2)
{
    float angle = atan2((pos1.y-pos2.y), (pos1.x-pos2.x));
    return angle;
}

float Utils::toDegree(float radian)
{
	return 180.f / M_PI * radian;
}

float Utils::toRadian(float degree)
{
	return M_PI / 180.f * degree;
}
