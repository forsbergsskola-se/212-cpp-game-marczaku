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
#include <vector>
#include "GameObject.h"
#include "Pikachu.h"
#include "Charmander.h"

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


	std::vector<GameObject*> gameObjects{};

	gameObjects.push_back(new Pikachu{&window});
	gameObjects.push_back(new Charmander{ &window, 200 });
	gameObjects.push_back(new Charmander{ &window, 400 });

	SDL_Event e; bool quit = false;

	unsigned int frameStartMs;

	
	bool patrollingDown{ true };
	int j = 0;

	// while the user doesn't want to quit
	while (quit == false)
	{
		// start the timer
		frameStartMs = SDL_GetTicks();

		for (auto gameObject : gameObjects) {
			gameObject->update();
		}

		//// pikachu patrol right
		//for (int i = 0; i < 100; i++) {
		//	image->x = i;
		//}

		//// pikachu patrol left
		//for (int i = 100; i > 0; i--) {
		//	image->x = i;
		//}


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

				} break;
			} 
		}
		
		// when done with all pending events, update the rendered screen
		window.clear(); // first clear
		
		for (auto gameObject : gameObjects) {
			gameObject->render(&window);
		}

		window.present(); // then present it

		// see, how long we should wait so we get 30FPS
		// Fixed Update
		unsigned int frameTimeMs = SDL_GetTicks() - frameStartMs;
		if (frameTimeMs < MS_PER_FRAME) {
			SDL_Delay(MS_PER_FRAME - frameTimeMs);
		}
	}

	return 0;
}