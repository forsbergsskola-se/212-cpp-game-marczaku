#pragma once

#include <memory>

extern class Image;
extern struct SDL_Renderer;

class IImageLoader
{
public:
	virtual std::unique_ptr<Image> loadImage(const char* path, SDL_Renderer* renderer) = 0;
};
