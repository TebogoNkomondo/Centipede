#include "mushroomCollisionHandler.h"
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
	window.setFramerateLimit(35);
	srand(time(0));
	
	//make an object of the screen class to initialize its constructor variables
	screen my_screen;
	mushroomCollisionHandler handleMushroomCollisions;
	//===================================================================Oratile's member variables===========================================
	//Declare the centipede train and its size;   
	polyCentipede polyOne(length_of_centipede);
	bool collided;
	//===================================================================Tebogos's member variable=====================================================
	SplashScreen SPScreen;
	SpriteGetter score1;
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
		///
		///If the Enter button has been pressed: Proceed to play the game
		///
		if (startTheGame){
			
//=================================================================Oratile goes here========================================================
		 for(int i= length_of_centipede-1; i> -1; i--)
            {
				my_screen.drawMushroom(window);
				collided= handleMushroomCollisions.isCollision(polyOne, my_screen, i );
				my_screen.draw_Centipede(i, polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate(), window);
                polyOne.myCentipede2.at(i).moveCentipedeSegment(collided);
			}
//================================================================Tebogo goes here==========================================================
				my_screen.drawPlayer(window);
				my_screen.drawSpider(window);
				
				my_screen.bullet_Mushroom_Collision();
				auto healthStatus = my_screen.collisions(window);
				
				auto isSpiderPlayerColission = get<0>(healthStatus);
				auto isCentipedeContainerEmpty = get<1>(healthStatus);
				
				/**
				 * @brief game ends if the player collids with a spider or centipede
				 */
				if(isSpiderPlayerColission == true){
					window.clear();
					SPScreen.deadStatus(window);
				}
				/**
				 * @brief game ends if all centipedes have been killed
				 */
				if(isCentipedeContainerEmpty == true){
					window.clear();
					SPScreen.winStatus(window);
				}
//==========================================================================================================================================
			window.display();
			window.clear();
		}
		/**
		 * display the screen at the start of the game
		 */
		else{
			SPScreen.drawSplashScreen(window);
			window.display();
			window.clear();
		}
	}
	window.close();
}