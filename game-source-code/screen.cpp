#include "screen.h"
#include "mushroomCollisionHandler.h"
#include<iostream>
using namespace std;

screen::screen()
{
	centipedeTexture = spriteGetter_.centipedeTexture();
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

	mush_ = spriteGetter_.mushroomTexture();
	mushroom_.setTexture(mush_);
	mushroom_.setScale(sf::Vector2f(0.2,0.2));
	
	for(int i=0; i< numberOfRandomMushrooms; i++)
    {
		singleMushroom oneMushroom;
		oneMushroom.setSingleMushroomPosition();
        mushrooms.push_back(oneMushroom);
		mushroomsOnTheScreen.push_back(mushroom_);
        mushroomsOnTheScreen.at(i).setPosition(mushrooms.at(i).getX_position(), mushrooms.at(i).getyPositition() );
    }
}

vector<singleMushroom> screen::getVectorOfMushrooms()
{
	return mushrooms;
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
	auto x = bulletVectorr.getXPos();
	auto y = bulletVectorr.getYPos();
	playyer.Draw(window);
	bulletVectorr.shootKey();
	bulletVectorr.addBullet(x,y, bulletLoop1);
	bulletVectorr.handleKey();
	bulletVectorr.DrawBullets(window, bulletLoop1);
	if(bulletLoop1.size() > 2){
		bulletVectorr.deleteBullets(bulletLoop1);
	}
}


void screen::drawSpider(sf::RenderWindow& window){
	spider1.drawSpider(window);
	auto rightMovemnt = spider1.moveSpiderRight();
	auto ifLeft_ = get<0>(rightMovemnt);

	auto horizontalDirection = 0;
	horizontalDirection  = get<1>(rightMovemnt);
	
	if(ifLeft_ == true){
		auto leftMovement = spider1.moveSpiderLeft();
		horizontalDirection = get<1>(leftMovement);
	}
				
	auto upMovement= spider1.moveSpiderUp(horizontalDirection);
	
	if(upMovement == true){
		spider1.moveSpiderDown(horizontalDirection);
	}
	spider1.regenerateSpider();
}

tuple<bool,bool> screen::collisions(sf::RenderWindow& my_window){
	bool isbulletSpiderCollission = false;
	int bulletLocation=0;
	auto bulletLifeStatus = collissionHandle.bulletSpider(spider1,bulletLoop1);
	
	isbulletSpiderCollission = get<0>(bulletLifeStatus);
	if(isbulletSpiderCollission == true){
		bulletLocation = get<1>(bulletLifeStatus);
		bulletLoop1.at(bulletLocation).deleteLaser();
	}
	isDead = collissionHandle.playerSpider(spider1, playyer);
	
	int numberOfCentipedeLeft = 12;
	numberOfCentipedeLeft = collissionHandle.bulletCentipede(bulletLoop1,centipede);
	
	if(numberOfCentipedeLeft == 0){
		centipedeArrayEmpty = true;
	}
	
	if(isDead == false){
		isDead = collissionHandle.playerCentipede(playyer, centipede);
	}
	return {isDead, centipedeArrayEmpty};
	
}

void screen::bullet_Mushroom_Collision(){
	collissionHandle.bullet_Mushroom_Collision(bulletLoop1, mushroomsOnTheScreen);
}