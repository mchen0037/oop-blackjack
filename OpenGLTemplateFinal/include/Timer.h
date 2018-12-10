#ifndef Timer_h
#define Timer_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <thread>
#include <chrono>

class Timer {
    int interval;
    bool running;
    std::thread timerThread;
    
    static void repeat(Timer*);
public:
    Timer();
    
    void start();
    
    void setRate(int);
    
    void stop();
    
    ~Timer();
    
    virtual void action() = 0;
};


#endif
