#ifndef HEAD_FUNC_H
#define HEAD_FUNC_H

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<bits/stdc++.h>

using namespace std;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 700;
//color key
const int COLOR_R = 187;
const int COLOR_G = 211;
const int COLOR_B = 236;

static bool is_run = true;
static bool is_pause = false;

static int mark_count = 0;
static int number_die = 0;
static int select_menu = 0;

static int number_power = 3;
static int SPEED_PLANE = 20;
const int SPEED_CHICKEN = 1;
// font text
static TTF_Font* g_font_text = NULL;
// sound
static Mix_Chunk* g_sound_bullet = NULL;
static Mix_Chunk* g_sound_explosion = NULL;
static Mix_Chunk* g_sound_gift = NULL;
static Mix_Chunk* g_sound_mark = NULL;

const int NUMBER_CHICKEN = 4;
const int NUMBER_POWER = 3;

namespace HeadFunc
{
    bool checkCollision(SDL_Rect p_object_1, SDL_Rect p_object_2);
    bool checkMouse(const int &x, const int &y, SDL_Rect rect);
}
#endif //HEAD_FUNC_H
