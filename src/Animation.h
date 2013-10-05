#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

//Textura animacji tylko w orientacji poziomej

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

class Animation : public sf::Drawable, public sf::Transformable {
public:
    Animation(sf::Texture *texture, unsigned frame_number, float time_per_frame, bool repeat);

    ~Animation();

    void update(float delta_time);

    sf::FloatRect getGlobalBounds();

    bool getRepeat(); // jesli animacja nie jest powtarzalna to zwraca false dopiero po zakonczeniu animacji

    void restartAnimation();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture *m_texture;

    unsigned m_frame_number;
    unsigned m_actual_frame;
    unsigned m_frame_width;
    unsigned m_frame_height;

    float m_time_per_frame;
    float m_delta_time;

    bool m_repeat;
};

#endif // ANIMATION_H_INCLUDED
