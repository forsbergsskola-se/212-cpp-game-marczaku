#pragma once
#include <SDL.h>

class Image
{
	//The image we will load and show on screen
	SDL_Texture* texture{};
	bool success;
public:
	int x, y, width, height;

	Image(SDL_Texture* texture);
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Texture* getResource() { return texture; }
	Image& operator =(Image& other) = delete;
	Image& operator =(Image&& other) = default;

};

