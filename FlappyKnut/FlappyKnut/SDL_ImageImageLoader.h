#pragma once
#include "IImageLoader.h"
class SDL_ImageImageLoader :
    public IImageLoader
{
public:
    std::unique_ptr<Image> loadImage(const char* path, const SDL_PixelFormat* pixelFormat) override;
    SDL_ImageImageLoader();
};

