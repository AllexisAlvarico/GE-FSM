#pragma once
#include "Defines.h"
#include <iostream>
#include <SDL.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Player.h"
#include "Utility.h"
#include "Defines.h"
#include "AnimatedSprite.h"

#define GAME_H

class Game
{
public: 
	Game();
	~Game();
	void run();
    void cleanUp();
	void init();

private:
    bool m_gameIsRunning;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    SDL_Texture* m_playerTex;
};

