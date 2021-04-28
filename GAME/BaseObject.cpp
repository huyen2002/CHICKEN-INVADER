#include"BaseObject.h"

BaseObject::BaseObject()
{
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
    p_object = NULL;
}
BaseObject::~BaseObject()
{
    SDL_DestroyTexture(p_object);
    p_object = NULL;
    rect_.w = 0;
    rect_.h = 0;
}
bool BaseObject::loadImage(string path, SDL_Renderer* screen)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == NULL)
    {
        return false;
    }
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, COLOR_R, COLOR_G, COLOR_B));

    p_object = SDL_CreateTextureFromSurface(screen, surface);

    if(p_object != NULL)
    {
        rect_.w = surface->w;
        rect_.h = surface->h;
    }
    SDL_FreeSurface(surface);
    surface = NULL;

    return p_object != NULL;
}
void BaseObject::RenderImage(SDL_Renderer* screen)
{
    SDL_Rect rect = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(screen, p_object, NULL, &rect);
}
