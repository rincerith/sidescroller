#include "StateMachine.h"

#include <string>
#include <iostream>


int main()
{
    try {
        StateMachine game(States::Game);
        game.runMachine();
    } catch(std::string str) {
        std::cout << "\n\n\n\nBLAD:\n" << str << std::endl;
        system("PAUSE");
    }
    return 0;
}
