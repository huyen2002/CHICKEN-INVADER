#include"BulletObject.h"

BulletObject:: BulletObject()
{
    is_move_ = true;
}

BulletObject::~BulletObject()
{

}
void BulletObject::handleMoveUp(bool is_pause)
{
    if(!is_pause)
      set_speed(5);
    else
      set_speed (0);

    rect_.y -= speed_;
    if(rect_.y <  - rect_.h)
    {
        is_move_ = false;
    }
}
void BulletObject::handleMoveDown(const int &x_border, const int &y_border)
{
    set_speed(2);
    rect_.y += speed_;
    if(rect_.y > y_border)
    {
        is_move_ = false;
    }
}
