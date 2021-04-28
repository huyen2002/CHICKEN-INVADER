#include"PowerPlane.h"

PowerPlane::PowerPlane()
{

}
PowerPlane::~PowerPlane()
{

}
void PowerPlane::InitPowerPos()
{
    for(int i = 0; i < NUMBER_POWER; i++)
    {
        power_pos_list_.push_back(5);
        power_pos_list_.push_back(45);
        power_pos_list_.push_back(85);
    }
}
void PowerPlane::RenderPower(SDL_Renderer* screen, int &number_power)
{
    for(int i = 0; i < number_power; i++)
    {
        setRect(power_pos_list_[i], 0);
        RenderImage(screen);
    }
}
void PowerPlane::DecreasePower(int &number_power)
{
    power_pos_list_.pop_back();
    number_power --;
}
