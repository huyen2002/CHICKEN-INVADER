#include"TextObject.h"

TextObject::TextObject()
{
    color_text_.r = 0;
    color_text_.g = 0;
    color_text_.b = 0;
    texture_ = NULL;
}
TextObject::~TextObject()
{
    SDL_DestroyTexture(texture_);
    texture_ = NULL;
}
void TextObject::loadText(TTF_Font* p_font, SDL_Renderer* screen)
{
    SDL_Surface* surface = TTF_RenderText_Solid(p_font, name_.c_str(), color_text_);
    if(surface == NULL)
    {
        cout << "Error Load Text :" << SDL_GetError() << endl;
    }
    texture_ = SDL_CreateTextureFromSurface(screen, surface);
    if(texture_ != NULL)
    {
        rect_.w = surface->w;
        rect_.h = surface->h;
    }
    SDL_FreeSurface(surface);
    surface = NULL;
}
void TextObject::RenderText(SDL_Renderer* screen)
{
    SDL_Rect rect = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(screen, texture_, NULL, &rect);
}
string TextObject::convert_to_string(const int &x)
{
    ostringstream convert;
    convert << x;
    string s = convert.str();
    return s;
}
