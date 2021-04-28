#include"PlaneObject.h"

PlaneObject::PlaneObject()
{

}
PlaneObject::~PlaneObject()
{

}
void PlaneObject::handleEvent(SDL_Event event, SDL_Renderer* screen, Mix_Chunk *p_sound)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_RIGHT: rect_.x += SPEED_PLANE; break;
            case SDLK_LEFT: rect_.x -= SPEED_PLANE; break;
            case SDLK_DOWN: rect_.y += SPEED_PLANE; break;
            case SDLK_UP: rect_.y -=  SPEED_PLANE; break;
            case SDLK_RETURN:
                {
                    BulletObject* p_bullet = new BulletObject();
                    p_bullet->loadImage("image/bullet.png", screen);
                    p_bullet->setRect(rect_.x + WIDTH_PLANE/2 - 10, rect_.y - HEIGHT_PLANE);
                    Mix_PlayChannel(-1, p_sound, 0);
                    p_bullet->set_is_move(true);

                    p_bullet_list_.push_back(p_bullet);
                 }
                break;

        }
    }

}
void PlaneObject::handleMove(const int &x_border, const int &y_border)
{
    if(rect_.x < 0)
      rect_.x += SPEED_PLANE;
    else if(rect_.x > x_border - WIDTH_PLANE)
        rect_.x -= SPEED_PLANE;

    if(rect_.y < 0)
      rect_.y += SPEED_PLANE;
    else if(rect_.y > y_border - HEIGHT_PLANE)
        rect_.y -= SPEED_PLANE;
}
void PlaneObject::RenderBullet(SDL_Renderer* screen, bool is_pause)
{
    for(int i = 0; i < p_bullet_list_.size(); i++)
    {
        BulletObject* p_bullet = p_bullet_list_.at(i);
        if(p_bullet != NULL)
        {
            if(p_bullet->get_is_move())
            {
                 p_bullet->RenderImage(screen);
                 p_bullet->handleMoveUp(is_pause);
                 Mix_PlayChannel(-1, g_sound_bullet, 0);
            }
            else{
               p_bullet_list_.erase(p_bullet_list_.begin() + i);
               delete p_bullet;
               p_bullet = NULL;
            }
        }
    }
}
void PlaneObject::DeleteBullet(const int &index)
{
    BulletObject* p_bullet = p_bullet_list_.at(index);
    if(p_bullet != NULL)
    {
        p_bullet_list_.erase(p_bullet_list_.begin() + index);
        delete p_bullet;
        p_bullet = NULL;
    }
}
