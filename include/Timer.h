#pragma once
#include <SDL.h>
#include <iostream>

class Timer{

public:
    Timer()
    {
        reset();
    };
    void reset(){
        m_timer = 0;
    };
    void startTimer(){
        m_timer = SDL_GetTicks();
    };
    float getTimer()
    {
        return getTicks() / 100.0;
    };

    uint32_t getTicks() {return SDL_GetTicks() - m_timer;}
private:
    Uint32 m_timer;
};