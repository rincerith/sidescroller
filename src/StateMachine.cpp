#include "StateMachine.h"
#include "MenuState.h"
#include "IntroState.h"
#include "GameState.h"

StateMachine::StateMachine(States::ID state)
    :m_actualState(state)
{
    m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SIDE SCROLLER");  // TODO: Zmienic tytul
    m_window->setVerticalSyncEnabled(true);
    loadResources();

};

StateMachine::~StateMachine()
{
    for(StateMap::iterator it=m_statemap.begin(); it != m_statemap.end(); it++) {
        delete it->second;
    }
    std::cout << "Usuwam okno" << std::endl;
    delete m_window;
};


void StateMachine::runMachine()
{
    sf::Clock clock;
    while(m_window->isOpen()) {
        float deltaTime=clock.restart().asSeconds();
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
            m_statemap[m_actualState]->readEvent(event);
        }

        m_statemap[m_actualState]->update(deltaTime);

        m_window->clear();
        m_statemap[m_actualState]->drawState();
        m_window->display();
    }
};


sf::RenderWindow* StateMachine::getWindow()
{
    return m_window;
};

sf::Texture* StateMachine::getTexture(Textures::ID id)
{
    return m_texture.getResource(id);
}

sf::Font* StateMachine::getFont(Fonts::ID id)
{
    return m_font.getResource(id);
}

void StateMachine::changeState(States::ID state)
{
    if(m_statemap.find(state)==m_statemap.end()) {
        std::string error = "Nie znaleziono podanego State - ";
        error+=m_actualState;
        throw error;
    }
    m_actualState=state;
}

void StateMachine::loadResources()
{
    //TEXTURES
    m_texture.loadResource("res//Texture//space.png", Textures::space); // Textura testowa
    m_texture.loadResource("res//Texture//menu_background.png", Textures::menu_background); // Tlo do menu
    m_texture.loadResource("res//Texture//splashscr_1.png", Textures::splashscr_1); // Testowy splash screen do intra
    m_texture.loadResource("res//Texture//sfml-logo-small.png", Textures::sfml_logo); // sfml logo
    //HOUSE
    m_texture.loadResource("res//Texture//house//house_1.png", Textures::house_1);
    m_texture.loadResource("res//Texture//house//house_2.png", Textures::house_2);
    //TILE
    m_texture.loadResource("res//Texture//tile//tile_1.png", Textures::tile_1);
    m_texture.loadResource("res//Texture//tile//tile_2.png", Textures::tile_2);
    //ANIMATION
    m_texture.loadResource("res//Texture//animations//anim_test.png", Textures::anim_test);
    /* player */ {
        m_texture.loadResource("res//Texture//animations//player//player_move_down.png", Textures::player_move_down);
        m_texture.loadResource("res//Texture//animations//player//player_move_left.png", Textures::player_move_left);
        m_texture.loadResource("res//Texture//animations//player//player_move_right.png", Textures::player_move_right);
        m_texture.loadResource("res//Texture//animations//player//player_move_up.png", Textures::player_move_up);
        m_texture.loadResource("res//Texture//animations//player//player_stay.png", Textures::player_stay);
    }
    //ICONS
    /* bullets */ {
        m_texture.loadResource("res//Texture//icons//bullets//test_bullet.png", Textures::test_bullet);
    }
    /* guns */ {
        m_texture.loadResource("res//Texture//icons//guns//test_gun.png", Textures::test_gun);
    }

    //FONT
    m_font.loadResource("res//Font//arial.ttf", Fonts::menu); //Czcionka  glowna

    //STATE
    m_statemap.insert(StatePair(States::Menu, new MenuState(this))); //Menu
    m_statemap.insert(StatePair(States::Intro, new IntroState(this)));
    m_statemap.insert(StatePair(States::Game, new GameState(this)));
}
