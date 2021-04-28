#include "MenuObject.h"

MenuObject::MenuObject()
{
    x_mouse = 0;
    y_mouse = 0;
}
MenuObject::~MenuObject()
{

}

int MenuObject::ShowMenu(SDL_Renderer* screen,string path_1, string path_2, SDL_Event mouse_event)
{
   loadImage("image/StartBkground.png", screen);
   p_menu[0].loadImage(path_1, screen);
   p_menu[0].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 100);

   p_menu[1].loadImage(path_2, screen);
   p_menu[1].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 170);

   while(true)
   {
      RenderImage(screen);
       p_menu[0].RenderImage(screen);

       p_menu[1].RenderImage(screen);

    while(SDL_PollEvent(&mouse_event))
     {
        switch(mouse_event.type)
        {
        case SDL_QUIT:
            {
                return -1;
            }
        case SDL_MOUSEMOTION:
            {
                x_mouse = mouse_event.motion.x;
                y_mouse = mouse_event.motion.y;
                for(int i = 0; i < 2; i++)
                {
                  bool test = HeadFunc::checkMouse(x_mouse, y_mouse, p_menu[i].getRect());
                  if(test)
                  {
                      if(i==0)
                     p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 95);
                     else
                     p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 165 );
                  }
                  else{
                        if(i==0)
                    p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 100);
                    else
                    p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 170);
                  }
                }
            }
        case SDL_MOUSEBUTTONDOWN:
            if(mouse_event.button.button == SDL_BUTTON_LEFT)
            {
                x_mouse = mouse_event.button.x;
                y_mouse = mouse_event.button.y;
                for(int i = 0; i < 2; i++)
                {
                  bool test = HeadFunc::checkMouse(x_mouse, y_mouse, p_menu[i].getRect());
                  if(test)
                  {
                      if(i==0)
                    p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 95);
                    else
                     p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 165);
                      return i+1;
                  }
                }
            }
        }

     }
    SDL_RenderPresent(screen);
   }
   return -1;
}
int MenuObject::Menu_end(SDL_Renderer* screen, string path_1, string path_2, TTF_Font *p_font, SDL_Event mouse_event, int &mark_)
{

 loadImage("image/StartBkground.png", screen);
  p_menu[0].loadImage(path_1, screen);
   p_menu[0].setRect(SCREEN_WIDTH/2 -120, SCREEN_HEIGHT /2 + 100);

   p_menu[1].loadImage(path_2, screen);
   p_menu[1].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 170);

 TextObject p_score;
      string s = "SCORE: ";
      string mark = p_score.convert_to_string(mark_);
      s += mark;
      p_score.set_name(s);
      p_score.loadText(p_font, screen);
      p_score.setRect(SCREEN_WIDTH/2 - 120 , SCREEN_HEIGHT/2 + 60);
   while(true)
   {
      SDL_RenderClear(screen);
      RenderImage(screen);
       p_menu[0].RenderImage(screen);

       p_menu[1].RenderImage(screen);

      p_score.RenderText(screen);
    while(SDL_PollEvent(&mouse_event))
     {
        switch(mouse_event.type)
        {
        case SDL_QUIT:
            {
                return -1;
            }
        case SDL_MOUSEMOTION:
            {
                x_mouse = mouse_event.motion.x;
                y_mouse = mouse_event.motion.y;
                for(int i = 0; i < 2; i++)
                {
                  bool test = HeadFunc::checkMouse(x_mouse, y_mouse, p_menu[i].getRect());
                  if(test)
                  {
                      if(i==0)
                     p_menu[i].setRect(SCREEN_WIDTH/2 -120, SCREEN_HEIGHT /2 + 95);
                     else
                     p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 165);
                  }
                  else{
                    if(i==0)
                    p_menu[i].setRect(SCREEN_WIDTH/2 -120, SCREEN_HEIGHT /2 + 100);
                    else
                    p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 170);
                  }
                }
            }
        case SDL_MOUSEBUTTONDOWN:
            if(mouse_event.button.button == SDL_BUTTON_LEFT)
            {
                x_mouse = mouse_event.button.x;
                y_mouse = mouse_event.button.y;
                for(int i = 0; i < 2; i++)
                {
                   bool test = HeadFunc::checkMouse(x_mouse, y_mouse, p_menu[i].getRect());
                  if(test)
                  {
                    if(i==0)
                    p_menu[i].setRect(SCREEN_WIDTH/2 -120, SCREEN_HEIGHT /2 + 95);
                    else
                    p_menu[i].setRect(SCREEN_WIDTH/2 -100, SCREEN_HEIGHT /2 + 165);
                    return i+1;
                  }
                }
            }
        }

     }
    SDL_RenderPresent(screen);
   }
   return -1;
}

