#include "object.h"

int tile_map[8][10] = {
	{ 1, 0, 0, 0,0, 1, 0, 0,0,0 } ,   /*  initializers for row indexed by 0 */
	{ 1, 0, 0, 0,0, 1, 0, 0,0,0 } ,   /*  initializers for row indexed by 1 */
	{ 1, 0, 0, 0,0, 0, 0, 0,0,0 }  , /*  initializers for row indexed by 2 */
	{ 1, 0, 0, 0,0, 0, 0, 0,0,0 }  ,
	{ 1, 0, 0, 0,0, 0, 0, 0,0,0 }  ,
	{ 0, 0, 0, 0,0, 1, 0, 0,0,0 }  ,
	{ 0, 0, 0, 0,0, 1, 0, 0,0,0 } ,
	{ 0, 0, 0, 0,0, 1, 0, 0,0,0 }

};

#define WIN32
#ifdef WIN32
#include <iostream>
#include <Windows.h>
using namespace std;
void print_curent_dir()
{
	
	system("echo %cd%");
	cout << endl;
}
#endif

void hanlde_move(movable_obj &mv)
{

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
	//v_sprite[mv.get_case().i*mv.get_case().j] = sf::Sprite(texture_sol);
    mv.move('l');
	//tile_map[mv.get_case().i][mv.get_case().j];
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
    // left key is pressed: move our character
    mv.move('r');
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    // left key is pressed: move our character
      mv.move('u');
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
    // left key is pressed: move our character
     mv.move('d');
}

}



int main()
{
	print_curent_dir();
movable_obj perso_monster(iso_case(0,2));
sf::Texture skull;

        sf::RenderWindow window(sf::VideoMode(1024,768   ), "SFML works!");
  

	// if (!texture_sol.loadFromFile("D:\\mywork\\dungeon_heroes\\windows\\dungeon_heroes\\dungeon_heroes\\floor.png"))
//if (!texture_sol.loadFromFile("D:/mywork/dungeon_heroes/windows/dungeon_heroes/dungeon_heroes/floor.png"))
if (!texture_sol.loadFromFile("floor.png"))
{

	std::cout << "error" << " floor.png" << std::endl;
	//exit(0);
}

sf::Vector2i vpos =calculate_tiles(8,6);
std::cout << vpos.x  << " : "<<vpos.y  << std::endl ;
if (!skull.loadFromFile("./skeleton_1.png", sf::IntRect(vpos.x,vpos.y,128, 128)))
{
    std::cout << "error" << "skeleton_1.png" <<  std::endl;
    //exit(0);
    // erreur...
}


// chargement d'un sous-rectangle de 32x32 démarrant en (10, 10)
if (!texture_mur.loadFromFile("./iso_dungeon_walls_by_pfunked.png", sf::IntRect(32, 0,128, 128)))
{
	std::cout << "error" << " iso_dungeon_walls_by_pfunked.png" << std::endl;
//	exit(0);
}

  

 

perso_monster.sp.setTexture(skull);
//perso_monster.set_z_pos(-400);
  //   sprite_skull.setPosition(cartesian_grid_to_iso_grid(2,2));
  //      sf::Sprite sprite;




/*
if (!texture.loadFromFile("tile_comparison_iso_3d.png", sf::IntRect(10, 10, 32, 32)))
{
    // error...
}*/

//// CACULATE SPRITE POSITION .////


	for (int j = 0; j < 10; j++)
    {


		for (int i = 0; i < 8; i++)
         {              
                // 1 MUR
                 if(tile_map[i][j] == 1 )
                 {
                 
				  v_sprite.push_back(drawable_obj(texture_sol, iso_case(i, j)));
				  v_sprite.push_back(drawable_obj(texture_mur, iso_case(i, j, 74)));                

                }
                //1 SQUELETTE
               else if(tile_map[i][j] == 2 )
                {

				v_sprite.push_back(drawable_obj(skull, iso_case(i, j)));


                }
				 // 1 SOL
                else if(tile_map[i][j] == 0 )
                  {
					  v_sprite.push_back(drawable_obj(texture_sol, iso_case(i, j)));
                }
              



                //sf::sleep(1);
         }

    }


bool is_press=false;
/////////////////////////////////
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
          if (event.type == sf::Event::KeyPressed)
         {
                        if(!is_press)
                        {
                          is_press = true;
                          hanlde_move(perso_monster);
                        }
                    }

          if (event.type == sf::Event::KeyReleased)
                 is_press=false;

        }

        window.clear();
       // window.draw(shape);

sf::View view = window.getDefaultView();
//view.zoom(0.75f);
window.setView(view);
		
		int index = 0;
        for(auto &dw_obj : v_sprite )
        {
		//	window.clear();
			//we must when draw perso 
			//std::cout << perso_monster.iso_c.i*perso_monster.iso_c.j << " -- " << index << std::endl;
		
			
				/*if ((perso_monster.iso_c.i*perso_monster.iso_c.j) == index)
				{
					std::cout << perso_monster.iso_c.i*perso_monster.iso_c.j << " -- " << index << std::endl;
					window.draw(perso_monster.sp);
					
				}
				else */
					window.draw(dw_obj.sp);
				
			index++;
			//std::cin.get();
        }
		window.draw(perso_monster.sp);
		window.display();
       // window.display();
    }

    return 0;
}
