#ifndef MENU_OBJECT_H
#define MENU_OBJECT_H

#include "BaseObject.h"
#include "TextObject.h"

class MenuObject : public BaseObject
{
public:
    MenuObject();
    ~MenuObject();
    enum
    {
        PLAY = 1,
        EXIT = 2,
        QUIT = -1,
    };

    int ShowMenu(SDL_Renderer* screen, string path_1, string path_2, SDL_Event event );
    int Menu_end(SDL_Renderer* screen, string path_1, string path_2, TTF_Font *p_font, SDL_Event event, int &mark_ );
private:
 int x_mouse, y_mouse;
 BaseObject p_menu[2];

};
#endif // MENU_OBJECT_H
