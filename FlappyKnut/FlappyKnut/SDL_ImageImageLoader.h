#pragma once
#include "IImageLoader.h"
class SDL_ImageImageLoader :
    public IImageLoader
{
public:
    std::unique_ptr<Image> loadImage(const char* path, SDL_Renderer* renderer) override;
    SDL_ImageImageLoader();
};

