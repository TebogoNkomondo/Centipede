//#include "screen.h"
#include "player.h"
#include "bulletContainer.h"
#include "bullet_Centipede_Collison_Handle.h"
#include "mushroomCollisionHandler.h"
#include "singleMushroom.h"
#include <SFML/Graphics.hpp>
#include "splashScreen.h"
#include <ctime>
#include <cstdlib>
#include "collisionHandler.h"
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
	bulletCentipeteCollision bullet_and_centipede;
	bool collided;
	
	//===================================================================Tebogos's member variable=====================================================
	SplashScreen SPScreen;
	bool healthStatus = false;
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
		//If the Enter button has been pressed: Proceed to play the game
		if (startTheGame){
//=================================================================Oratile goes here========================================================
		 for(int i= length_of_centipede-1; i> -1; i--)
            {
				collided= handleMushroomCollisions.isCollision(polyOne, my_screen, i );
				my_screen.draw_Centipede(i, polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate(), window);
                polyOne.myCentipede2.at(i).moveCentipedeSegment(collided);
				
				//detect bullet and centipede collisions
//				if(bullet_and_centipede.isCollision(my_screen.vector<sf::Sprite>& centipedeTrain, ___class object_______ std::vector<Laser>& bulletLoop))
//				{
//					bullet_and_centipede.setcentipedeSegmentScale_zero( vector <sf::Sprite>& centipede);
//				}
			}
			
			
			
			my_screen.drawMushroom(window);
//================================================================Tebogo goes here==========================================================
				my_screen.drawPlayer(window);
				my_screen.drawSpider(window);
				healthStatus = my_screen.collisions();
				//my_screen.bulletCentipede1();
				//my_screen.drawCentipede1(window);
		
		if(healthStatus == true){
			window.clear();
			SPScreen.deadStatus(window);
		}
//==========================================================================================================================================
			
			//Game termination stage:
//			if( polyOne.myCentipede2.at(i).get_xCoordinate() == playerXCoordinate )
//				if(polyOne.myCentipede2.at(i).get_xCoordinate() == playerYCoordinate )
//					break;
			
			window.display();
			window.clear();
		}
		else{
			SPScreen.drawSplashScreen(window);
			window.display();
			window.clear();
		}
	}
	//Display Game Over message
	//Close the window
	window.close();
}