#pragma once
#include "IImageLoader.h"
class SDLImageLoader :
    public IImageLoader
{
public:
    std::unique_ptr<Image> loadImage(const char* path, SDL_Renderer* renderer) override;
};
