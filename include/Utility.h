#ifndef UTILITY_H
#define UTILITY_H

namespace utility
{
	inline SDL_Texture* loadFromFile(const char* const path, SDL_Renderer* renderer)
	{
		SDL_Texture* newTexture{ NULL };

		SDL_Surface* loadedSurface = IMG_Load(path);
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
			}

			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}
}
#endif // !UTILITY_H