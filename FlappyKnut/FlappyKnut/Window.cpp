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
	
	// Create Window and Renderer
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

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
	SDL_RenderCopy(renderer, image->getResource(), nullptr, &targetRectangle);
}

std::unique_ptr<Image> Window::loadImage(const char* path) {
	return imageLoader->loadImage(path, renderer);
}

void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Window::present() {
	SDL_RenderPresent(renderer);
}