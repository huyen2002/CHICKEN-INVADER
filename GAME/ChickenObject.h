#ifndef CHICKEN_OBJECT_H
#define CHICKEN_OBJECT_H

#include"BaseObject.h"
#include"BulletObject.h"

const int WIDTH_CHICKEN = 55;
const int HEIGHT_CHICKEN = 55;
class ChickenObject : public BaseObject
{
public:
    ChickenObject();
    ~ChickenObject();
    void handleMove(const int &x_border, const int &y_border);
    void ResetChicken();
    void ResetBullet(BulletObject* p_bullet);
    void InitBullet(BulletObject* p_bullet, SDL_Renderer* screen);
    void RenderBullet(SDL_Renderer* screen, bool &pause);
    vector<BulletObject*> get_bullet_list() {return p_bullet_list_;}
private:
   vector<BulletObject*> p_bullet_list_;
};
#endif // CHICKEN_OBJECT_H
