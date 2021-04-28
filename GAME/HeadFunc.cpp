#include"HeadFunc.h"

bool HeadFunc::checkCollision(SDL_Rect p_object_1, SDL_Rect p_object_2)
{
    int left_1 = p_object_1.x + 5;
    int right_1 = p_object_1.x + p_object_1.w - 5;
    int top_1 = p_object_1.y + 5;
    int buttom_1 = p_object_1.y + p_object_1.h - 5;

    int left_2 = p_object_2.x + 5;
    int right_2 = p_object_2.x + p_object_2.w - 5;
    int top_2 = p_object_2.y +5;
    int buttom_2 = p_object_2.y + p_object_2.h -5;

  if(left_2 < right_1 && right_1 < right_2)
  {
      if((top_1 < top_2 && top_2 < buttom_1) || (top_1 < buttom_2 && buttom_2 < buttom_1))
      return true;
  }
  else if(left_1 < right_2 && right_2 < right_1)
  {
      if((top_1 < top_2 && top_2 < buttom_1) || (top_1 < buttom_2 && buttom_2 < buttom_1))
        return true;
  }

 else if(left_1 < right_2 && right_2 < right_1)
  {
      if((top_2 < top_1 && top_1 < buttom_2) || (top_2 < buttom_1 && buttom_1 < buttom_2))
      return true;
  }
  else if(left_2 < right_1 && right_1 < right_2)
  {
      if((top_2 < top_1 && top_1 < buttom_2) || (top_2 < buttom_1 && buttom_1 < buttom_2))
        return true;
  }
  else if(right_1 == right_2 && (left_1 == left_2 && (top_1 == top_2 && buttom_1 == buttom_2)))
    return true;

  return false;

}
bool HeadFunc::checkMouse(const int &x, const int &y, SDL_Rect rect)
{
        if(x >= rect.x && x <= rect.x + rect.w)
        {
            if(y >= rect.y && y <= rect.y + rect.h)
                return true;
        }

    return false;
}
