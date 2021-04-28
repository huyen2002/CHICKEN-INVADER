#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include"HeadFunc.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    bool loadImage(string path, SDL_Renderer* screen);
    void RenderImage(SDL_Renderer* screen);
    void setRect(const int &x, const int &y) {rect_.x = x; rect_.y = y;}
    SDL_Rect getRect() {return rect_;}
    SDL_Rect rect_;

private:
    SDL_Texture* p_object;
};
#endif // BASE_OBJECT_H
