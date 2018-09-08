#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "centipede.h"
#include "player.h"
#include "laser.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"CentipedeGame");
    
//===================================================Oratile's member variables==========================================================================
    centipede theCentipede(1);
    
    
//=====================================================Tebogo's member variables================================================================
	Player player1;
	//set player initial position
	player1.setPosition(sf::Vector2f(window.getSize().x/2  , window.getSize().y-player1.GetPlayer().getScale().y*90 ));
	//bullets
	Laser bullet1;
	std::vector<Laser>bulletLoop;
	bool isFiring;
	std::vector<Laser>::const_iterator iter;
	//window.setFramerateLimit(30);
	//auto counter =0;
    
    
//===============================================================================================================================================
    while(window.isOpen())
    {
        //check that the window is not closed
        sf::Event event;
		while(window.pollEvent(event))
        {
			if(event.type == sf::Event::Closed){
					window.close();
				}
		}
//=============================================Oratile Goes here==================================================================
        auto sizeOfCentipede= theCentipede.getCentipedesize();
            
        for(int i=0; i< sizeOfCentipede; i++)
        {
            theCentipede.moveCentipedeRight(i);
            theCentipede.moveCentipedeDown(i);
            theCentipede.moveCentipedeLeft(i);
            theCentipede.moveCentipedeUP(i);
            
            window.draw(theCentipede.myCentipede.at(i));
        }

//====================================== Tebogo goes here======================================================================
		//handle bullet movements
		//shoot bullets
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
			isFiring = true; 
		}
		if(isFiring == true){
			bullet1.setPosition(sf::Vector2f(player1.GetPlayer().getPosition().x+13,player1.GetPlayer().getPosition().y));
			bulletLoop.push_back(bullet1);
			isFiring = false;
		}
		
		for(int i=0,kk=bulletLoop.size();i<kk;i++){
			bulletLoop[i].Shoot();
			bulletLoop[i].DrawBullet(window);
		}
		
		
		//delete bullets once they are out of the screen
		int counter=0;
		for(iter=bulletLoop.begin();iter<bulletLoop.end();iter++){
			if(bulletLoop[counter].GetLaser().getPosition().y<0){
				bulletLoop.erase(iter);
			}
			counter++;
			if(bulletLoop.size()<=2){
				counter=0;
				break;
			}
		}

		//draw the player and deal with movement
		player1.Draw(window);
		player1.handleKey();

//==============================================================================================================================

        window.display();
        window.clear();
        
    }
    
    return 0;
}

	
