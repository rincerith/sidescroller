#include "BinaryTree.h"
#include "GameMap.h"



GameMap::GameMap(StateMachine *machine)
    :m_machine(machine)
    ,m_background_texture(NULL)
    ,m_tree(NULL)
{
    //house
    m_houses_textures.push_back(m_machine->getTexture(Textures::house_1));
    m_houses_textures.push_back(m_machine->getTexture(Textures::house_2));

    //tile
    m_tile_textures.push_back(m_machine->getTexture(Textures::tile_1));
    m_tile_textures.push_back(m_machine->getTexture(Textures::tile_2));
}

GameMap::~GameMap()
{
    delete m_background_texture;
    delete m_tree;
    clear();
    std::cout << "Usuwam map" << std::endl;
}

void GameMap::generateMap(int width)
{
    if(width%96 != 0) {
        std::string error = "Zly rozmiar mapy";
        throw error;
    }
    m_width=width;

    clear();
    delete m_tree;
    m_tree = new BinaryTree<sf::Sprite*>(0,0,m_width, 600, 0, 5); // TODO ustalic jakos maxlevel

    //house
    for(int i=0; i<m_width/96; i++) {
        sf::Sprite *sprite = new sf::Sprite(*m_houses_textures[rand()%2]); // TODO : zmienic ilosc textur
        sprite->setPosition(i*96, 56);
        m_sprites.push_back(sprite);
    }

    //tile
    for(int i=0; i<(m_width/32); i++) {
        for(int j=0; j<14; j++) {
            sf::Sprite *sprite = new sf::Sprite(*m_tile_textures[rand()%2]); // TODO : zmienic ilosc textur
            sprite->setPosition(i*32, 152+32*j);
            m_sprites.push_back(sprite);
        }
    }

    for(std::vector<sf::Sprite*>::iterator it=m_sprites.begin(); it!=m_sprites.end(); it++) {
        m_tree->AddObject(*it);
    }


}

void GameMap::drawMap(float x, float y)
{
    sf::RenderWindow &window = *(m_machine->getWindow());
    std::vector<sf::Sprite*> vec = m_tree->GetObjectsAt(x, y);
    for(std::vector<sf::Sprite*>::iterator it=vec.begin(); it!=vec.end(); it++) {
        window.draw(**it);
    }
}

void GameMap::clear()
{
    for(std::vector<sf::Sprite*>::iterator it=m_sprites.begin(); it!=m_sprites.end(); it++) {
        delete *it;
    }
}

int GameMap::getWidth()
{
    return m_width;
}
