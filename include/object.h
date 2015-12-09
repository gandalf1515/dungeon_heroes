#ifndef ISO_OBJECT_H
#define ISO_OBJECT_H
#include "core.h"

class drawable_obj
{

	//sprite
	public:
		drawable_obj(){}
		drawable_obj(sf::Texture & text, iso_case & iso_ca)
		{
			sp.setTexture(text);
			//conserve grid position
			iso_c = iso_ca;
			//caculate sprite iso position
			sp.setPosition(cartesian_grid_to_iso_grid(iso_ca));
		}
		void set_iso_position()
		{

			//sp.setPosition()

		}
		void set_texture(sf::Texture & text)
		{
			sp.setTexture(text);
		}
		sf::Sprite sp;
		//case courante
		iso_case get_case() { return iso_c;}
		iso_case iso_c;

};


class movable_obj : public drawable_obj
{
    public:
    movable_obj(sf::Texture  &text,iso_case is)
    {
		this->iso_c = is;
            sp.setTexture(text);
            sp.setPosition(cartesian_grid_to_iso_grid(is));
    }

    movable_obj(iso_case is) 
    {
		this->iso_c = is;
         sp.setPosition(cartesian_grid_to_iso_grid(is));
    }
    void move(char direction)
{
    sf::Vector2f pos =  sp.getPosition();
  switch (direction)
    {
        case 'l': iso_c.i+=1;break;
        case'r' : iso_c.i-=1;break;
        case'd' : iso_c.j+=1;break;
        case'u' : iso_c.j-=1;break;
    }


  //   iso_c.y += z_inc;
 // iso_c.z = 64;
	 sf::Vector2f iso_pos = cartesian_grid_to_iso_grid(iso_c);
	 std::cout << iso_pos.x << "-" << iso_pos.y << std::endl;
	
    sp.setPosition(iso_pos);
}

	


};
///////////  GLOBAL OBJECT
std::vector<drawable_obj> v_sprite_layer0;
std::vector<drawable_obj> v_sprite_layer1;
sf::Texture texture_sol;
sf::Texture texture_mur;
////////////////////





#endif
