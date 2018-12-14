#include "BjGame.hpp"
#include <iostream>

int main(int argc, char** argv) {
    GlutApp* app = new BjGame(argc, argv);

    app->run();
}
