/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include "SDL_ImageImageLoader.h"
#include <map>
#include <memory>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// std::map is a STL Container
// STDL stands for Standard Template Library
// The container is the same as a C# Dictionary
// We need to provide Template Type Arguments
// Same as for Generic Classes in C#
std::map<SDL_KeyCode, const char*> surfaceMap = {
	{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"},
};

const char* pikachuImagePath{ "img/pikachu.png" };

const unsigned int FPS = 30;
const unsigned int MS_PER_FRAME = 1000 / FPS;

int main(int argc, char* args[])
{
	// We decide for now to use the SDL Image Loader (which only supports BMP):
	IImageLoader* imageLoader = new SDL_ImageImageLoader{};
	// We pass that ImageLoader on to the Window, so the Window can use it
	// to load the image
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT, imageLoader };
	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}


	//Load media
	//auto image{ std::make_unique<Image>(fallbackSurface, window.getPixelFormat()) };
	auto image{window.loadImage(pikachuImagePath)};
	if (!image->wasSuccessful())
	{
		// TODO: Replace with Exceptions
		printf("Failed to load media!\n");
		return -1;
	}

	auto pikachuBot{ window.loadImage(pikachuImagePath) };
	if (!pikachuBot->wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}
	pikachuBot->y = SCREEN_HEIGHT - 100;


	SDL_Event e; bool quit = false;

	bool goingRight = true, botGoingRight = true;
	unsigned int frameStartMs;
	// while the user doesn't want to quit
	while (quit == false)
	{
		// start the timer
		frameStartMs = SDL_GetTicks();

		// update pikachu
		if (goingRight)
			image->x+=5;
		else
			image->x-=5;

		if (image->x > 500 || image->x < 1) {
			goingRight = !goingRight;
		}

		if (botGoingRight)
			pikachuBot->x+=0;
		else
			pikachuBot->x-=0;

		if (pikachuBot->x > 500 || pikachuBot->x < 1) {
			botGoingRight = !botGoingRight;
		}

		// loop through all pending events from Windows (OS)
		while (SDL_PollEvent(&e))
		{
			// check, if it's an event we want to react to:
			switch (e.type) {
				case SDL_QUIT: {
					quit = true;
				} break;
				case SDL_KEYDOWN: {
					const char* imgPath = pikachuImagePath;
					if (auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end()) {
						imgPath = result->second;
					}

					//image = std::make_unique<Image>(imgPath, window.getPixelFormat());
					image = window.loadImage(imgPath);
					if (!image->wasSuccessful())
					{
						printf("Failed to load media!\n");
						return -1;
					}
				} break;
			} 
		}
		// when done with all pending events, update the rendered screen
		// first clear
		window.clear();

		// then draw everything
		window.render(image.get());
		window.render(pikachuBot.get());

		// then present it
		window.present();

		// see, how long we should wait so we get 30FPS
		// Fixed Update
		unsigned int frameTimeMs = SDL_GetTicks() - frameStartMs;
		if (frameTimeMs < MS_PER_FRAME) {
			SDL_Delay(MS_PER_FRAME - frameTimeMs);
		}
	}

	return 0;
}