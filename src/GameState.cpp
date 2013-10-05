#include "GameMap.h"
#include "GameState.h"
#include "Utils.h"

GameState::GameState(StateMachine *machine)
    :State(machine)
    ,m_player(new Player(machine))
    ,m_bullet_creator(machine)
    ,m_shoot(true)
{
    m_map = new GameMap(machine);
    //m_map->generateMap(3456);
    m_map->generateMap(960);
    m_player->setPosition(400, 300);
}

GameState::~GameState()
{
    delete m_map;
    for(VEntitiesPtr::iterator it=m_entities.begin(); it!=m_entities.end(); it++) {
        delete *it;
    }
    delete m_player;
    std::cout << "Usuwam GameState" << std::endl;
}

void GameState::readEvent(sf::Event event)
{
    if(event.type == sf::Event::MouseButtonReleased) {
        if(event.mouseButton.button == sf::Mouse::Left) m_shoot = true;
    }
}

void GameState::update(float deltaTime)
{
    sf::RenderWindow &window = *(getMachine()->getWindow());
    sf::Vector2f mouse_pos = static_cast<sf::Vector2f>(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
    sf::View view = window.getView();
    float factor = deltaTime*m_player->getSpeed();
    m_player->setState(PlayerState::stay);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(view.getCenter().x < (m_map->getWidth()-400) and m_player->getPosition().x > view.getCenter().x) view.move(factor, 0);
        m_player->move(factor, 0);
        m_player->setState(PlayerState::move_right);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(view.getCenter().x > 400 and m_player->getPosition().x < view.getCenter().x) view.move(-factor, 0);
        m_player->move(-factor, 0);
        m_player->setState(PlayerState::move_left);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_player->move(0, -factor);
        m_player->setState(PlayerState::move_up);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_player->move(0, factor);
        m_player->setState(PlayerState::move_down);
    };

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) and m_shoot) {
        m_shoot = false;
        Gun *gun = m_player->getGun();
        if(gun->canShoot()) {
            gun->shoot();
            m_entities.push_back(m_bullet_creator.createBullet(gun->getBulletId(), Utils::getAngle(mouse_pos, m_player->getPosition()), m_player->getPosition()));
        }
    }

    move_entities(deltaTime);

    window.setView(view);
    for(VEntitiesPtr::iterator it=m_entities.begin(); it!=m_entities.end(); it++) {
        if((**it).isActive()) (*it)->update(deltaTime);
    }
    m_player->update(deltaTime);
}

void GameState::drawState()
{
    sf::RenderWindow &window=*(getMachine()->getWindow());
    sf::Vector2f pos = window.getView().getCenter();
    m_map->drawMap(pos.x-400, 400+pos.x);
    for(VEntitiesPtr::iterator it=m_entities.begin(); it!=m_entities.end(); it++) {
        if((**it).isActive()) window.draw(**it);
    }
    window.draw(*m_player);
}


void GameState::move_entities(float deltaTime)
{
    float delta = deltaTime/10.0f;
    for(int i=0; i<10; i++) {
        for(VEntitiesPtr::iterator it=m_entities.begin(); it!=m_entities.end(); it++) {
            (*it)->onMove(delta);
            if((*it)->isActive()) {
                for(VEntitiesPtr::iterator it2=it; it2!=m_entities.end(); it2++) {
                    if( (*it2)->isActive() and (*it)->getGlobalBounds().intersects((*it2)->getGlobalBounds())) {
                            (*it)->onCollision(*it2);
                            (*it2)->onCollision(*it);
                    }
                }
            }
        }
    }
}
