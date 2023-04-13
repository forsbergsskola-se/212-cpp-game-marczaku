#include "SDLImageLoader.h"
#include "Image.h"
#include <SDL.h>

std::unique_ptr<Image> SDLImageLoader::loadImage(const char* path, SDL_Renderer* renderer)
{
	//Load splash image
	auto tmpSurface = SDL_LoadBMP(path);
	if (!tmpSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return std::make_unique<Image>(nullptr);
	}

	auto texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	if (!texture)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		return std::make_unique<Image>(nullptr);
	}

    return std::make_unique<Image>(texture);
}
