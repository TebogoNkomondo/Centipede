#include "screen.h"
#include "mushroomCollisionHandler.h"
#include<iostream>
using namespace std;

screen::screen()
{
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
	
	//set up the mushrooms
	mushroomCollisionHandler mushHandler;
	numberOfRandomMushrooms= mushHandler.getNumberOfmushrooms();
	if(!mush_.loadFromFile("resources/mushroom.png")){
		cout<<"falied to load mushroom file"<<endl;
	}
	mushroom_.setTexture(mush_);
	mushroom_.setScale(sf::Vector2f(0.28,0.28));
	
	for(int i=0; i< numberOfRandomMushrooms; i++)
    {
		singleMushroom oneMushroom;
		oneMushroom.setSingleMushroomPosition();
        mushrooms.push_back(oneMushroom);
		mushroomsOnTheScreen.push_back(mushroom_);
        mushroomsOnTheScreen.at(i).setPosition(mushrooms.at(i).getX_position(), mushrooms.at(i).getyPositition() );
    }
	
}

void screen::draw_Centipede(int segment_Index, double x_Position, double y_Position, sf::RenderWindow& my_window )
{
	centipede.at(segment_Index).setPosition(x_Position, y_Position);
	my_window.draw(centipede.at(segment_Index));
}

void screen::drawMushroom(sf::RenderWindow& my_window)
{
	for (int i=0; i<numberOfRandomMushrooms; i++)
	{
		my_window.draw(mushroomsOnTheScreen.at(i));
	}
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

