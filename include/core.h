#ifndef ISO_CORE_H
#define ISO_CORE_H

#define TILE_H 32
#define TILE_W 32

#define TILE_H_FLOAT 32.0
#define TILE_W_FLOAT 32.0


#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2i  calculate_tiles(int i , int j )
{
    sf::Vector2i vret;
    vret.x = i*128;
    vret.y = j*128;
    return vret;


}
std::vector<sf::Sprite> v_sprite;

class iso_case{

public:
  iso_case(int i,int j) : i(i) , j(j)
  {

  }
  int i =2 ;
  int j =2 ;

};




sf::Vector2f cartesian_grid_to_iso_grid(const iso_case & iso_c)
{

                sf::Vector2f v;
                 v.x=iso_c.j*TILE_W +600;
                v.y=iso_c.i*TILE_H -100;

                 sf::Vector2f v_iso;
                 //sprite.setPosition(v);
                 v_iso.x = v.x - v.y ;
                 v_iso.y = (v.x + v.y)/2 ;

                 return v_iso;

}

#endif // ISO_CORE_H
