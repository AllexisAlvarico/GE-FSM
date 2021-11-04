#include "Game.h"

Game::Game() :
	m_gameIsRunning{ false }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow("FSM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1800, 1000, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image Error: %s\n", IMG_GetError());
	}
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	init();
}

Game::~Game()
{
	cleanUp();
}

void Game::run()
{
	AnimatedSprite player_animated_sprite(m_playerTex);

	Player player(player_animated_sprite);

	gpp::Events input;

	m_gameIsRunning = true;
	SDL_Event e{};

	while (m_gameIsRunning)
	{

		// process events
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				m_gameIsRunning = false;
			}


		// update
		player.update();

		// render
		SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(m_renderer);

		player.render(m_renderer);

		SDL_RenderPresent(m_renderer);
		}
	}

}
void Game::init()
{
	m_playerTex = utility::loadFromFile(PLAYER_SPRITES, m_renderer);
	if (m_playerTex == nullptr)
	{
		DEBUG_MSG("Failed to load file");
		m_playerTex = utility::loadFromFile(ERROR_SPRITES, m_renderer);
	}
}

void Game::cleanUp()
{
	std::cout << "Cleaning up" << std::endl;

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	m_renderer = nullptr;	
	IMG_Quit();
	SDL_Quit();
}
