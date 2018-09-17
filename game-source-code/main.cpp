#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "laser.h"
#include "polyCentipede.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"CentipedeGame");
    auto startTheGame =false;
    
    // Set up text to display on splash screen
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the splash message
    sf::Text splashMessage;
    splashMessage.setFont(font);
    splashMessage.setCharacterSize(40);
    splashMessage.setPosition(170.f, 150.f);
    splashMessage.setFillColor(sf::Color::Green);
    splashMessage.setString("Welcome to the Centipede Game!\n\nInstructions:\nPress Space bar to shoot\nPress Right to move Right\nPress Left to move Left\nPress Down to move Down\nPress Up to move UP\n\nPress Enter to start the Game!!");
    
//===================================================Oratile's member variables================================================================================================
    int numOfcentipedes= length_of_centipede;
    polyCentipede polyOne(numOfcentipedes);
    
    sf::Sprite centipedeSegment;
    sf::Texture centipedeTexture;
    
    //set the centipede sprite
    if(!centipedeTexture.loadFromFile("resources/soccerBall.png"))
    {
        cout<< "Load texture failed"<<endl;
    }
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
    
    vector <sf::Sprite> centipede (numOfcentipedes);
    for(int i=0; i<numOfcentipedes; i++)
    {
        centipede.at(i)= centipedeSegment;
        centipede.at(i).setPosition(polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate() );
    }
    
    
//=====================================================Tebogo's member variables===============================================================================================
	Player player1;
	//set player initial position
	player1.setPosition(sf::Vector2f(window.getSize().x/2  , window.getSize().y-player1.GetPlayer().getScale().y*90 ));
	//bullets
	Laser bullet1;
	std::vector<Laser>bulletLoop;
	bool isFiring;
	std::vector<Laser>::const_iterator iter;
	window.setFramerateLimit(30);
	//auto counter =0;
    
    
//===============================================================================================================================================
    while(window.isOpen())
    {
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
        
        //If the Enter button has been pressed
        if (startTheGame)
        {
//=============================================Oratile Goes here==================================================================
            //auto sizeOfCentipede= theCentipede.getCentipedesize();
                
            for(int i=0; i< numOfcentipedes; i++)
            {
                polyOne.myCentipede2.at(i).moveCentipedeSegment();
                centipede.at(i).setPosition(polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate() );
                
                window.draw(centipede.at(i));
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

            window.display();
            window.clear();
       }
        
        //If Enter button has not been pressed
        else
        {
             window.draw(splashMessage);
             window.display();
             window.clear();
        }
    }
    
    return 0;
}

	
