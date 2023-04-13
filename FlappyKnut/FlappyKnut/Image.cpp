#include "Image.h"
#include <SDL.h>
#include <cstdio>

Image::Image(SDL_Texture* texture) :
	texture{ texture },
	success{ texture != nullptr},
	x{},
	y{},
	width{ 100 },
	height{ 100 } { }

Image::~Image() {
	//Dealloacate surface
	SDL_DestroyTexture(texture);
	texture = nullptr;
}