#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include "StateMachine.h"
#include "BinaryTree.h"


class GameMap {
public:
    GameMap(StateMachine *machine);

    ~GameMap();

    void generateMap(int width);

    void drawMap(float x, float y);

    int getWidth();

private:
    void clear();

    StateMachine *m_machine;
    sf::Texture *m_background_texture;
    int m_width;
    std::vector<sf::Texture*> m_houses_textures;
    std::vector<sf::Texture*> m_tile_textures;
    BinaryTree<sf::Sprite*> *m_tree;
    std::vector<sf::Sprite*> m_sprites;

};

#endif // GAMEMAP_H_INCLUDED
