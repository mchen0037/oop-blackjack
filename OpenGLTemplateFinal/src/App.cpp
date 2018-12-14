#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
    background = new TexRect("assets/green_board.png", -1.5, 1.5, 3, 3);
    card1 = new TexRect("assets/cards/0c.png", -0.5, 0.5, 1, 1);
    card2 = new TexRect("assets/cards/0c.png", -0.4, 0.5, 1, 1);

}

void App::draw() {
    background->draw(0.0);
    card1->draw(0.10);
    card2->draw(0.20);

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }

    if (key == ' '){
//        draw();
    }
}


App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete background;
}
