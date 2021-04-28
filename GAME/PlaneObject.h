#ifndef PLANE_OBJECT_H
#define PLANE_OBJECT_H

#include"BaseObject.h"
#include"BulletObject.h"

const int WIDTH_PLANE = 61;
const int HEIGHT_PLANE = 60;
class PlaneObject : public BaseObject
{
public:
    PlaneObject();
    ~PlaneObject();
    void handleMove(const int &x_border, const int &y_border);
    void handleEvent(SDL_Event event, SDL_Renderer* screen, Mix_Chunk *p_sound);
    vector<BulletObject*> get_p_bullet_list() {return p_bullet_list_;}
    void RenderBullet(SDL_Renderer* screen, bool is_pause);
    void DeleteBullet(const int &index);
private:
    vector<BulletObject*> p_bullet_list_;
};

#endif // PLANE_OBJECT_h

