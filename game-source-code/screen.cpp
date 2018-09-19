#include "screen.h"
#include<iostream>
using namespace std;

screen::screen()
{
	//Declare the splash screen message
    




	
	//set up the centipede segment sprite
    if(!centipedeTexture.loadFromFile("resources/soccerBall.png"))
    {
        cout<< "Load centipede texture failed"<<endl;
    }
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	
	//now we load the vector of centipede with centipede sprites
	polyCentipede polyOne(length_of_centipede);
	for(int i=0; i<length_of_centipede; i++)
    {
        centipede.push_back(centipedeSegment);
        centipede.at(i).setPosition(polyOne.myCentipede2.at(i).get_xCoordinate(), polyOne.myCentipede2.at(i).get_yCoordinate() );
    }
	
}

void screen::draw_Splash_Screen_Message(sf::RenderWindow& my_window)
{
	my_window.draw(splash_Message);        
}

void screen::draw_Centipede(int segment_Index, double x_Position, double y_Position, sf::RenderWindow& my_window )
{
	centipede.at(segment_Index).setPosition(x_Position, y_Position);
	my_window.draw(centipede.at(segment_Index));
}

void screen::drawPlayer(sf::RenderWindow& window){
	playyer.handleKey();
	auto x = BulletContainer::getXPos();
	auto y = BulletContainer::getYPos();
	playyer.Draw(window);
	BulletContainer::shootKey();
	BulletContainer::addBullet(x,y);
	BulletContainer::handleKey();
	BulletContainer::DrawBullets(window);
	BulletContainer::deleteBullets();
	
}

