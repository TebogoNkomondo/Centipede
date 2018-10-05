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
	//cout<< "size"<< bulletLoop1.size()<<endl;
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
	spider1.generateSpider();
}

tuple<bool,bool> screen::collisions(sf::RenderWindow& my_window){
	bool isAl = false;
	int k=0;
	auto kk = spiderBullet1.bulletSpider(spider1,bulletLoop1);
	
	isAl = get<0>(kk);
	if(isAl == true){
		k = get<1>(kk);
		bulletLoop1.at(k).deleteLaser();
	}
	isDead = spiderBullet1.playerSpider(spider1, playyer);
	
	auto numberOfCentipedeLeft = spiderBullet1.bulletCentipede(bulletLoop1,centipede );
	
	if(numberOfCentipedeLeft == 0){
		centipedeArrayEmpty = true;
	}
	
	if (spiderBullet1.getShotCentipedeIndex() > -1)
	{
		auto mushSize=mushroomsOnTheScreen.size();
		auto x= spiderBullet1.getShot_X();
		auto y= spiderBullet1.getShot_Y();
		
		mushroomsOnTheScreen.push_back(mushroom_);
		
		mushroomsOnTheScreen.at(mushSize -1).setPosition(x, y);
		my_window.draw(mushroomsOnTheScreen.at(mushSize -1));
		spiderBullet1.resetShotCentipedeIndex(-1);
	}
	
	cout<< mushroomsOnTheScreen.size() <<endl;
	return {isDead, centipedeArrayEmpty};
	
}

void screen::bullet_Mushroom_Collision(){
	for(size_t i=0;i<bulletLoop1.size();i++){
		for(size_t t=0;t<mushroomsOnTheScreen.size();t++){
			sf::FloatRect col1 = bulletLoop1.at(i).getBullet().getGlobalBounds();
			sf::FloatRect col2 = mushroomsOnTheScreen.at(t).getGlobalBounds();
			if(col1.intersects(col2)){
				mushroomsOnTheScreen.at(t).setScale(0,0);
				bulletLoop1.at(i).deleteLaser();
			}
		}
	}
}