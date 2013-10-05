#include "Animation.h"

#include <iostream>

Animation::Animation(sf::Texture *texture, unsigned frame_number, float time_per_frame, bool repeat)
    :m_texture(texture)
    ,m_frame_number(frame_number)
    ,m_actual_frame(0)
    ,m_time_per_frame(time_per_frame)
    ,m_delta_time(0)
    ,m_repeat(repeat)
{
    sf::Vector2u siz = m_texture->getSize();
    m_frame_width = siz.x/m_frame_number;
    m_frame_height = siz.y;
    setOrigin(m_frame_width/2.0f, m_frame_height/2.0f);
}

Animation::~Animation()
{
    std::cout << "Usuwam animacje" << std::endl;
}

void Animation::update(float delta_time)
{
    m_delta_time+=delta_time;
    if(m_delta_time >= m_time_per_frame) {
        m_delta_time = 0;
        if(m_actual_frame == m_frame_number-1) {
            if(m_repeat) m_actual_frame=0;
        } else {
            m_actual_frame++;
        }
    }
}

sf::FloatRect Animation::getGlobalBounds()
{
    sf::FloatRect rect;

    sf::Vector2f pos = getPosition();
    rect.left=pos.x;
    rect.top=pos.y;
    rect.width=m_frame_width;
    rect.height=m_frame_height;

    return rect;
}

bool Animation::getRepeat()
{
    if(m_repeat || m_actual_frame < m_frame_number-1) return true;
    return false;
}

void Animation::restartAnimation()
{
    m_actual_frame=0;
    m_delta_time=0;
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::VertexArray vertices(sf::Quads, 4);
    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(m_frame_width, 0);
    vertices[2].position = sf::Vector2f(m_frame_width, m_frame_height);
    vertices[3].position = sf::Vector2f(0, m_frame_height);

    vertices[0].texCoords = sf::Vector2f(m_frame_width*m_actual_frame, 0);
    vertices[1].texCoords = sf::Vector2f(m_frame_width*(m_actual_frame+1), 0);
    vertices[2].texCoords = sf::Vector2f(m_frame_width*(m_actual_frame+1), m_frame_height);
    vertices[3].texCoords = sf::Vector2f(m_frame_width*m_actual_frame, m_frame_height);

    states.transform = getTransform();
    states.texture = m_texture;
    target.draw(vertices, states);
}
