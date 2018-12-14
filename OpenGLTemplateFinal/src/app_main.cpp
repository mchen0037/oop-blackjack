#include "App.h"
#include "BjGame.hpp"
#include <iostream>

int main(int argc, char** argv) {
    GlutApp* app = new BjGame(argc, argv);

    char c = 'Y';
//    while (c == 'Y' || c == 'y') {
//      BjGame* game = new BjGame();
////      game->init();
////      game->printState();
//      game->play();
//      std::cout << "Play Again? (Y/N): " << std::endl;
//      std::cin >> c;
//      delete game;
//    }
  
    app->run();
}
