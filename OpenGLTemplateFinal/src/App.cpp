#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
    background = new TexRect("assets/green_board.png", -1.5, 1.5, 3, 3);

}

void App::draw() {
    background->draw(0.15);
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }

    if (key == ' '){
        draw();
    }
}


App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete background;
}
