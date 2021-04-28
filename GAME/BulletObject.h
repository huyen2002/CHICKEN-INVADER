#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include"BaseObject.h"

class BulletObject : public BaseObject
{
public:
    BulletObject();
    ~BulletObject();
    void handleMoveUp(bool is_pause);
    void handleMoveDown(const int &x_border, const int &y_border);
    void set_speed(const int &speed) {speed_ = speed;}
    void set_is_move(const bool &is_move) {is_move_ = is_move;}
    bool get_is_move() {return is_move_;}
private:
    int speed_;
    bool is_move_;

};
#endif
