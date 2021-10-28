#include "Game.h"

Game::Game() :
	m_gameIsRunning{ false }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow("SDL tutorial",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	TTF_Init();

	m_currentSurface = SDL_GetWindowSurface(m_window);
}

Game::~Game()
{
}

void Game::run()
{
}

void Game::processEvents(SDL_Event e)
{
}

void Game::update()
{
}

void Game::render()
{
}

void Game::surfaceDraw()
{
}

void Game::rendererDraw()
{
}
