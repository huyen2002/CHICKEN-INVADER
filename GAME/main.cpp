#include"HeadFunc.h"
#include"BaseObject.h"
#include"PlaneObject.h"
#include"ChickenObject.h"
#include"PowerPlane.h"
#include"TextObject.h"
#include"MenuObject.h"
#include<Windows.h>

BaseObject g_background;
PlaneObject g_plane;
ChickenObject* g_chicken_list = NULL;
ChickenObject g_gift;
PowerPlane g_power;
TextObject g_mark;
TextObject g_text;
MenuObject g_menu;
BaseObject g_pause;
void InitFunc()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Init Error: " << SDL_GetError() << endl;
    }
    g_window = SDL_CreateWindow("Nguyen Thi Thanh Huyen 20020420 - CHICKEN INVADER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(g_window == NULL)
    {
        cout << "Window Error: " << SDL_GetError() << endl;
    }
    g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);

    int img_flag =  IMG_INIT_PNG;
    if(!(IMG_Init(img_flag) && img_flag))
    {
        cout << "IMG Error: " << SDL_GetError() << endl;
    }
    if(TTF_Init() == -1)
    {
        cout << "TTF Error: " << SDL_GetError() << endl;
    }
    g_font_text = TTF_OpenFont("Font_3D.ttf", 25);
    if(g_font_text == NULL)
    {
        cout << "don't open file TTF: " << SDL_GetError() << endl;
    }
   g_font_text = TTF_OpenFont("Font_3D.ttf", 30);
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        cout << "Mixer Error: " << SDL_GetError() << endl;
    }
    g_sound_bullet = Mix_LoadWAV("sound/Bullet.wav");
    g_sound_explosion = Mix_LoadWAV("sound/Explosion.wav");
    g_sound_mark = Mix_LoadWAV("sound/mark.wav");
    g_sound_gift = Mix_LoadWAV("sound/Gift.wav");
    if(g_sound_bullet == NULL || g_sound_explosion == NULL || g_sound_gift == NULL|| g_sound_mark == NULL)
    {
        cout << "Error: Don't load File Sound" << endl;
    }
}
void Free()
{
    TTF_CloseFont(g_font_text);
    Mix_CloseAudio();
    g_background.~BaseObject();
    g_pause.~BaseObject();

    g_mark.~TextObject();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();
}
void InitMain()
{
    bool ret = g_background.loadImage("image/background.png", g_screen);
    if(!ret)
    {
        cout << "couldn't load background" << endl;
    }
    g_pause.loadImage("image/unpause.png", g_screen);
    g_pause.setRect(SCREEN_WIDTH - 250, 0);
    // load plane
    g_plane.loadImage("image/plane.png", g_screen);
    g_plane.setRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - HEIGHT_PLANE);
    //load Chicken
    g_chicken_list = new ChickenObject[NUMBER_CHICKEN];
    for(int i = 0 ; i < NUMBER_CHICKEN; i++)
    {
        ChickenObject* p_chicken = g_chicken_list + i;
        int rand_chicken = rand()%3 + 1;
        switch(rand_chicken)
           {
            case 1: p_chicken->loadImage("image/chickenRed.png", g_screen); break;
            case 2: p_chicken->loadImage("image/chickenGreen.png", g_screen); break;
            case 3: p_chicken->loadImage("image/chickenYellow.png", g_screen); break;
           }
      int rand_x = rand() % (SCREEN_WIDTH - WIDTH_CHICKEN);
      p_chicken->setRect(rand_x, -i*100);
      BulletObject* p_bullet = new BulletObject();
      p_chicken->InitBullet(p_bullet, g_screen);
    }
    // load gift
    g_gift.loadImage("image/gift.png", g_screen);
    int rand_x = rand() % (SCREEN_WIDTH - g_gift.rect_.w);
    g_gift.setRect(rand_x, 0);
    // load power
    number_die = 0;
    number_power = 3;
    g_power.loadImage("image/power.png", g_screen);
    g_power.InitPowerPos();
    // load mark text
    mark_count = 0;

    //init menu game
    select_menu = 0;
    g_menu.loadImage("image/StartBkground.png", g_screen);

}

int main(int argc, char* argv[])
{
    InitFunc();
    InitMain();
  select_menu =  g_menu.ShowMenu(g_screen,"image/play.png", "image/exit.png", g_event);
  if(select_menu == MenuObject::EXIT || select_menu == MenuObject::QUIT)
  {
      is_run = false;
  }
  while(is_run)
    {
      if( g_event.type == SDL_QUIT)
        {
            is_run = false;
        }

    while(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
            {
             is_run = false;
            }
           else if(g_event.type == SDL_MOUSEBUTTONDOWN)
            {

                if(g_event.button.button == SDL_BUTTON_LEFT)
                 {
                     if(!is_pause)
                        {
                            g_pause.loadImage("image/pause.png", g_screen);
                            int x_mouse = g_event.button.x;
                            int y_mouse = g_event.button.y;
                            if(HeadFunc::checkMouse(x_mouse, y_mouse, g_pause.getRect()))
                            is_pause = true;
                        }
                      else
                        {
                            g_pause.loadImage("image/unpause.png", g_screen);
                            g_pause.setRect(SCREEN_WIDTH- 250, 0);
                            int x_mouse = g_event.button.x;
                            int y_mouse = g_event.button.y;
                            if(HeadFunc::checkMouse(x_mouse, y_mouse, g_pause.getRect()))
                            is_pause = false;
                        }
                }

            }
            if(!is_pause)
            g_plane.handleEvent(g_event, g_screen, g_sound_bullet);
        }

        SDL_RenderClear(g_screen);
        //render background
        g_background.RenderImage(g_screen);
        g_pause.RenderImage(g_screen);
        // render plane
        g_plane.RenderImage(g_screen);
        g_plane.handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        g_plane.RenderBullet(g_screen, is_pause);

        // render gift
        if(!is_pause)
        g_gift.handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        g_gift.RenderImage(g_screen);

        // render chicken
        for(int i = 0; i < NUMBER_CHICKEN; i++)
        {
            ChickenObject* p_chicken = g_chicken_list + i;
            if(p_chicken != NULL)
            {
                p_chicken->RenderImage(g_screen);
                if(!is_pause)
                p_chicken->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                p_chicken->RenderBullet(g_screen, is_pause);
            }
            // check Collision Chicken and Plane
            bool check_1 = HeadFunc::checkCollision(p_chicken->getRect(), g_plane.getRect());
            if(check_1)
            {
                number_die++;
                SPEED_PLANE -= 2;
                p_chicken->ResetChicken();
                Mix_PlayChannel(-1, g_sound_explosion, 0);
                g_plane.setRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - HEIGHT_PLANE);
                g_power.DecreasePower(number_power);
            }
            // check Collision Egg and Plane
            vector<BulletObject*> p_egg_list = p_chicken->get_bullet_list();
            for(int i = 0; i < p_egg_list.size(); i++)
            {
                BulletObject* p_egg = p_egg_list.at(i);
                bool check_2 = HeadFunc::checkCollision(p_egg->getRect(), g_plane.getRect());
                if(check_2)
                {
                    number_die++;
                    SPEED_PLANE -= 2;
                    Mix_PlayChannel(-1, g_sound_explosion, 0);
                    p_chicken->ResetBullet(p_egg);
                    g_plane.setRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - HEIGHT_PLANE);
                    g_power.DecreasePower(number_power);
                }

            }
            //check Collision Chicken and Bullet
            vector<BulletObject*> p_bullet_list = g_plane.get_p_bullet_list();
            for(int t= 0; t < p_bullet_list.size(); t++)
            {
                BulletObject* p_bullet = p_bullet_list.at(t);
                bool check_3 = HeadFunc::checkCollision(p_chicken->getRect(), p_bullet->getRect());
                if(check_3)
              {
                mark_count++;
                Mix_PlayChannel(-1, g_sound_mark, 0);
                g_plane.DeleteBullet(t);
                p_chicken->ResetChicken();
              }
            }
        }
        // check Plane and Gift
        bool check_4 = HeadFunc::checkCollision(g_plane.getRect(), g_gift.getRect());
        if(check_4)
        {
            mark_count += 5;
            SPEED_PLANE += 10;
            g_gift.ResetChicken();
            Mix_PlayChannel(-1, g_sound_gift, 0);
        }

        // render power
        g_power.RenderPower(g_screen, number_power);

        // render mark
        string mark = g_mark.convert_to_string(mark_count);
        string s = "Mark: " + mark;
        g_mark.set_name(s);
        g_mark.loadText(g_font_text, g_screen);
        g_mark.setRect(SCREEN_WIDTH - 150, 0);
        g_mark.RenderText(g_screen);

        if(number_die >= 3)
        {
            Sleep(1000);
            is_run = false;
            select_menu = g_menu.Menu_end(g_screen, "image/play again.png", "image/exit.png", g_font_text, g_event, mark_count);
            if(select_menu != MenuObject::EXIT && select_menu != MenuObject::QUIT)
            {
                delete[] g_chicken_list;
                InitMain();
                is_run = true;
            }
            else
                is_run = false;
        }

        SDL_RenderPresent(g_screen);
        SDL_Delay(10);
    }
    delete[] g_chicken_list;
    Free();
    return 0;
}
