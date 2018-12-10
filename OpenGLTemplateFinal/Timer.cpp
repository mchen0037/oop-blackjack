#include "Timer.h"

void Timer::repeat(Timer* self){
    while (self->running){
        int delay = self->interval;
        self->action();
        std::this_thread::sleep_for (std::chrono::milliseconds(delay));
    }
}

Timer::Timer() {
    interval = 1000;
    running = false;
    
}

Timer::~Timer(){
    if (running) timerThread.detach();
}

void Timer::stop(){
    running = false;
}

void Timer::setRate(int mills){
    interval = mills;
}

void Timer::start(){
    running = true;
    timerThread = std::thread(repeat, this);
}
