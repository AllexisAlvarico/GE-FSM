#pragma once
#include <Defines.h>
#include <iostream>
#include <SDL.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define GAME_H

class Game
{
public: 
	Game();
	~Game();
	void run();


private:

	bool m_gameIsRunning;

	void processEvents(SDL_Event e);
	void update();
	void render();
	void surfaceDraw();
	void rendererDraw();

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	SDL_Texture* m_textureIMG{ nullptr };
	SDL_Surface* m_currentSurface{ nullptr };
	SDL_Surface* m_surfaceBMP{ nullptr };
	const int WINDOW_WIDTH{ 640 };
	const int WINDOW_HEIGHT{ 480 };
};

