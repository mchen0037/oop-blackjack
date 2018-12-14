#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Shapes/TexRect.h"


class App: public GlutApp {
    TexRect* background;
//    TexRect* card;
    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
