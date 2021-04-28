#include"ChickenObject.h"

ChickenObject::ChickenObject()
{

}
ChickenObject::~ChickenObject()
{
   for(int i = 0; i < p_bullet_list_.size(); i++)
   {
       BulletObject * p_bullet = p_bullet_list_.at(i);
       if(p_bullet != NULL)
       {
           delete p_bullet;
           p_bullet = NULL;
       }
   }
}
void ChickenObject::handleMove(const int &x_border, const int &y_border)
{
    rect_.y += SPEED_CHICKEN;
    if(rect_.y > y_border)
    {
        int rand_x = rand() % (SCREEN_WIDTH - WIDTH_CHICKEN);
        setRect(rand_x, 0);
    }
}
void ChickenObject::InitBullet(BulletObject* p_bullet, SDL_Renderer* screen)
{
    if(p_bullet != NULL)
    {
        p_bullet->loadImage("image/egg.png", screen);
        p_bullet->setRect(rect_.x + WIDTH_CHICKEN/2 -10, rect_.y + HEIGHT_CHICKEN);
        p_bullet->set_is_move(true);
        p_bullet_list_.push_back(p_bullet);
    }
}
void ChickenObject::RenderBullet(SDL_Renderer* screen, bool &pause)
{
    for(int i = 0; i < p_bullet_list_.size(); i++)
    {
        BulletObject* p_bullet = p_bullet_list_.at(i);
        if(p_bullet != NULL && rect_.y < SCREEN_HEIGHT - 200)
        {
            if(p_bullet->get_is_move())
            {
                p_bullet->RenderImage(screen);
                if(!pause)
                 p_bullet->handleMoveDown(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            else{
                p_bullet->setRect(rect_.x + WIDTH_CHICKEN/2 -10, rect_.y + HEIGHT_CHICKEN);
                p_bullet->set_is_move(true);
            }

        }
    }
}
void ChickenObject::ResetChicken()
{
   int rand_x = rand() % (SCREEN_WIDTH - WIDTH_CHICKEN);
    setRect(rand_x, 0);
    for(int i = 0; i < p_bullet_list_.size(); i++)
    {
        BulletObject* p_bullet = p_bullet_list_[i];
        if(p_bullet == NULL)
        {
            ResetBullet(p_bullet);
        }
    }
}
void ChickenObject::ResetBullet(BulletObject* p_bullet)
{
     p_bullet->setRect(rect_.x + WIDTH_CHICKEN/2 -10, rect_.y + HEIGHT_CHICKEN);
}
