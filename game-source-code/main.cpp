#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "centipede.h"
#include "player.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"CentipedeGame");
    
//===================================================Oratile's member variables==========================================================================
    centipede theCentipede(10);
    
    
//=====================================================Tebogo's member variables================================================================
	Player player1;
	//set player initial position
	player1.setPosition(sf::Vector2f(window.getSize().x/2  , window.getSize().y-player1.GetPlayer().getScale().y*90 ));



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
			player1.Draw(window);
			player1.handleKey();

//==============================================================================================================================

        window.display();
        window.clear();
        
    }
    
    return 0;
}

	
