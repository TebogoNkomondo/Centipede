#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "centipede.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"CentipedeGame");
    
//===================================================Oratile's member variables==========================================================================
    centipede theCentipede(10);
    
    
//=====================================================Tebogo's member variables================================================================




//===============================================================================================================================================
    while(window.isOpen())
    {
        //check that the window is not closed
        sf::Event event;
		while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
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

        window.display();
        window.clear();
        
    }
    
    return 0;
}

	
