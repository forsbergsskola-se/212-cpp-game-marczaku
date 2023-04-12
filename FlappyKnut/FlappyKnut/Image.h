#pragma once
#include <SDL.h>

class Image
{
	//The image we will load and show on screen
	SDL_Surface* imageSurface{};
	bool success;
public:
	int x, y, width, height;

	Image(SDL_Surface* surface);
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource() { return imageSurface; }
	Image& operator =(Image& other) = delete;
	Image& operator =(Image&& other) = default;

};

