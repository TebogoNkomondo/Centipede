#include "screen.h"
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
	//render the winow we are working on
	sf::RenderWindow window (sf::VideoMode(screen_Width, screen_Height),"The Centipede Game",sf::Style::Titlebar);
	auto startTheGame= false;
	window.setFramerateLimit(30);
	
	//make an object of the screen class to initialize its constructor variables
	screen my_srceen;
	
	//===================================================================Oratile's member variables===========================================
	//Declare the centipede train and its size;   
	polyCentipede polyOne(length_of_centipede);
	
	//===================================================================Tebogos's member variable=====================================================
	
	
	
	
	
//===========================================================================================================================================
	while(window.isOpen())
    {
		// ckeck if the window is closed or the Enter has been pressed
        sf::Event event;
		while(window.pollEvent(event))
        {
            switch(event.type)
            {
                //check that the window is not closed
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                //Check if the enter key has been presed. If it is set 'startTheGame' to true
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                        {
                        case sf::Keyboard::Enter:
                            startTheGame= true;
                            break;
                            
                        default:
                            break;
                        }
                default:
                    break;
            }

		}
		
		//If the Enter button has been pressed: Proceed to play the game
		if (startTheGame)
		{
//=================================================================Oratile goes here========================================================
		 for(int i=0; i< length_of_centipede; i++)
            {
                polyOne.myCentipede2.at(i).moveCentipedeSegment();
				my_srceen.draw_Centipede(i, polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate(), window);
			}
		
//================================================================Tebogo goes here==========================================================
		
			window.display();
			window.clear();
		}
		
//		else
//		{
//			my_srceen.draw_Splash_Screen_Message(window);
//			window.display();
//			window.clear();
//		}
		
	}

}