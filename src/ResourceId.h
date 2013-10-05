#ifndef RESOURCEID_H_INCLUDED
#define RESOURCEID_H_INCLUDED

namespace sf {
class Texture;
class Font;
}

namespace Textures {
enum ID {
    space,
    menu_background,
    splashscr_1,
    sfml_logo,
    house_1,
    house_2,
    tile_1,
    tile_2,
    anim_test,
    player_move_down,
    player_move_left,
    player_move_right,
    player_move_up,
    player_stay,
    test_bullet,
    test_gun
};
}

namespace Fonts {
enum ID {
    menu
};
}

namespace States {
enum ID {
    Intro,
    Menu,
    Game
};
}

template <typename Resource, typename Identifier>
class ResourceManager;

typedef ResourceManager<sf::Texture, Textures::ID> TextureManager;
typedef ResourceManager<sf::Font, Fonts::ID> FontManager;

#endif // RESOURCEID_H_INCLUDED
