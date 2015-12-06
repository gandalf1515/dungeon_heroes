#ifndef ISO_OBJECT_H
#define ISO_OBJECT_H
#include "core.h"

class drawable_obj
{


};


class movable_obj : public drawable_obj
{
    public:
    movable_obj(sf::Texture  &text,iso_case is) : iso_c(is)
    {
            sp.setTexture(text);
            sp.setPosition(cartesian_grid_to_iso_grid(is));
    }

    movable_obj(iso_case is) : iso_c(is)
    {

            sp.setPosition(cartesian_grid_to_iso_grid(is));
    }
    void move(char direction)
{
    sf::Vector2f pos =  sp.getPosition();
  switch (direction)
    {
       case 'l' : iso_c.i+=1;break;
        case'r' : iso_c.i-=1;break;
        case'd' : iso_c.j+=1;break;
        case'u' : iso_c.j-=1;break;
    }
    sp.setPosition(cartesian_grid_to_iso_grid(iso_c));
}


    iso_case iso_c;
    sf::Sprite sp;


};






#endif
