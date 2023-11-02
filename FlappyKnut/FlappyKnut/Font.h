#pragma once
#include <SDL_ttf.h>
#include <memory>

extern class Image;

class Font
{
	//The image we will load and show on screen
	TTF_Font* font{};
	bool success;
public:
	Font(const char* path, const int size);
	~Font();
	bool wasSuccessful() { return success; }
	TTF_Font* getResource() { return font; }
	Font& operator =(Font& other) = delete;
	Font& operator =(Font&& other) = default;
	std::unique_ptr<Image> createText(const char* text, SDL_Renderer* renderer);
};

