#ifndef POWER_PLANE_H
#define POWER_PLANE_H

#include"BaseObject.h"

class PowerPlane : public BaseObject
{
public:
    PowerPlane();
    ~PowerPlane();
    void InitPowerPos();
    void RenderPower(SDL_Renderer* screen, int &number_power);
    void DecreasePower(int &number_power);
private:
    vector<int> power_pos_list_;
};
#endif // POWER_PLANE_H
