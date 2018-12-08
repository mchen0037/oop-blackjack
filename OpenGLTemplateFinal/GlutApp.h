#ifndef GlutApp_h
#define GlutApp_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class GlutApp {
    int width;
    int height;
    
    int interval;
    bool timerOn;
    const char* title;
    
    // Prevent derived classes from defining these constructors
    GlutApp(){} 
    GlutApp(const GlutApp&){}

    static void glutDisplayCB();
    
    static void glutKeyDownCB(unsigned char, int, int);
    static void glutKeyUpCB(unsigned char, int, int);
    static void glutSpecialKeyDownCB(int, int, int);
    static void glutSpecialKeyUpCB(int, int, int);
    
    static void glutMouseCB(int, int, int, int);
    static void glutMotionCB(int, int);
    
    static void glutResizeCB(int, int);
    
    static void glutIdleCB();
    
    static void glutTimerCB(int);
    
    friend void windowToScene(float&, float&);
    
protected:
    GlutApp(int, char**, int = 600, int = 600, const char* title = "GLUT Application");
    
public:
    void run();
    void redraw();
    
    void timerStart();
    void timerStop();
    void timerSetInterval(int mills);
    
    virtual void draw() = 0;
    
    virtual void keyDown(unsigned char, float, float){}
    virtual void keyUp(unsigned char, float, float){}
    
    virtual void specialKeyDown(int, float, float){}
    virtual void specialKeyUp(int, float, float){}
    
    virtual void leftMouseDown(float, float){}
    virtual void rightMouseDown(float, float){}
    virtual void leftMouseUp(float, float){}
    virtual void rightMouseUp(float, float){}
    
    virtual void drag(float, float){}
    
    virtual void idle(){}
    
    virtual void timer(){}
    
    virtual ~GlutApp(){}
};

#endif
