#include "IntroState.h"
#include "StateMachine.h"

IntroState::IntroState(StateMachine *machine)
    :State(machine)
    ,m_splashscrn_1_texture(getTexture(Textures::splashscr_1))
    ,m_sfml_logo_texture(getTexture(Textures::sfml_logo))
    ,m_time(0.0f)
    ,m_total_time(0.0f)
    ,m_alpha(5)
    ,m_screen(0)
{

}

IntroState::~IntroState()
{
    std::cout << "usuwam IntroState" << std::endl;
}

void IntroState::readEvent(sf::Event event)
{

}

void IntroState::update(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        getMachine()->changeState(States::Menu);


    m_time+=deltaTime;
    m_total_time+=deltaTime;


    if(m_total_time >= 3.0f)
        getMachine()->changeState(States::Menu);


    if(m_total_time <= 1.0f) {
        if(m_time >= 0.0038f) {
            if(m_alpha != 255)
                m_alpha+=5;
            m_time = 0;
        }
    } else if(m_total_time > 2.0f && m_total_time < 3.0f) {
        if(m_time >= 0.0038f) {
            if(m_alpha != 0)
                m_alpha-=5;
            m_time = 0;
        }
    }
}

void IntroState::drawState()
{
    sf::RenderWindow &window=*(getMachine()->getWindow());
    sf::Sprite splashscrn_1(*m_splashscrn_1_texture);
    splashscrn_1.setColor(sf::Color(255,255,255,m_alpha));

    window.draw(splashscrn_1);
}
