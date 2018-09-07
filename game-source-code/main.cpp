#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "centipede.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"CentipedeGame");
    centipede theCentipede(20);
    
    while(window.isOpen())
    {
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

	
