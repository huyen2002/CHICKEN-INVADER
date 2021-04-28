#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include"BaseObject.h"

class TextObject : public BaseObject
{
public:
    TextObject();
    ~TextObject();

    void set_name(const string &s) {name_ = s;}
    void loadText(TTF_Font* p_font, SDL_Renderer* screen);
    void RenderText(SDL_Renderer* screen);
    string convert_to_string(const int &x);
private:
    string name_;
    SDL_Color color_text_;
    SDL_Texture* texture_;
};
#endif // TEXT_OBJECT_H
