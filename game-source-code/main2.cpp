//#include "screen.h"
#include "player.h"
#include "bulletContainer.h"
#include "bullet_Centipede_Collison_Handle.h"
#include "singleMushroom.h"
#include <SFML/Graphics.hpp>
#include "splashScreen.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//render the winow we are working on
	sf::RenderWindow window (sf::VideoMode(screen_Width, screen_Height),"The Centipede Game",sf::Style::Default);
	auto startTheGame= false;
	window.setFramerateLimit(30);
	srand(time(0));
	
	//make an object of the screen class to initialize its constructor variables
	screen my_screen;
	singleMushroom oneMushroom;
	oneMushroom.setSingleMushroomPosition();
	
	//===================================================================Oratile's member variables===========================================
	//Declare the centipede train and its size;   
	polyCentipede polyOne(length_of_centipede);
	bulletCentipeteCollision bullet_and_centipede;
	
	//===================================================================Tebogos's member variable=====================================================
	SplashScreen SPScreen;
	SPScreen.drawSplashScreen(window);

//===========================================================================================================================================
	while(window.isOpen())
    {
		// ckeck if the window is closed or the Enter has been pressed
        sf::Event event;
		while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
				window.close();
			}
			if(event.key.code == sf::Keyboard::Enter){
				startTheGame = true;
			}
		}
		
		if(startTheGame==false){
			SPScreen.drawSplashScreen(window);
		}

		//If the Enter button has been pressed: Proceed to play the game
		if (startTheGame){
//=================================================================Oratile goes here========================================================
		my_screen.drawMushroom(window);
		 for(int i=0; i< length_of_centipede; i++)
            {
                polyOne.myCentipede2.at(i).moveCentipedeSegment();
				my_screen.draw_Centipede(i, polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate(), window);
				
				//Assume there is a collision at the second segment
				bullet_and_centipede.setcentipedeSegmentScale_zero(my_screen.centipede, my_screen.centipede.size() - 2);
			}

//================================================================Tebogo goes here==========================================================
				my_screen.drawPlayer(window);
//==========================================================================================================================================
			
			window.display();
			window.clear();
		}
		else{
			SPScreen.drawSplashScreen(window);
			window.display();
			window.clear();
		}
	}

}