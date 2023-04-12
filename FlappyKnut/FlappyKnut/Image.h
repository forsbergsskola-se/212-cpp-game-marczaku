#pragma once
#include <SDL.h>

class Image
{
	//The image we will load and show on screen
	SDL_Surface* imageSurface{};
	bool success;
public:
	Image(const char* path, const SDL_PixelFormat* pixelFormat);
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource() { return imageSurface; }
	Image& operator =(Image& other) = delete;
	Image& operator =(Image&& other) = default;
};

