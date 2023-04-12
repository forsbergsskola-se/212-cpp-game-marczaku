#include "Window.h"
#include <cstdio>
#include <SDL.h>
#include "IImageLoader.h"

Window::Window(int width, int height, IImageLoader* imageLoader)
	: success{}, imageLoader{ imageLoader } {

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);
	success = true;

}

Window::~Window() {
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystem
	SDL_Quit();
}

void Window::render(Image* image) {
	SDL_Rect targetRectangle{ 
		image->x,
		image->y,
		image->width,
		image->height
	};
	//Apply image
	SDL_BlitScaled(image->getResource(), nullptr, screenSurface, &targetRectangle);
	//Update the surface
	SDL_UpdateWindowSurface(window);
}

std::unique_ptr<Image> Window::loadImage(const char* path) {
	return imageLoader->loadImage(path, screenSurface->format);
}