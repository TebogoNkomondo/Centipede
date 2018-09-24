#include "spider.h"
#include <iostream>
using namespace std;

Spider::Spider(){
	if(!texture_.loadFromFile("resources/spider.png")){
		std::cout<<"falied to load spider file"<<endl;
	}
	spider_.setTexture(texture_);
	spider_.setScale(sf::Vector2f(0.12,0.07));
	spider_.setPosition(sf::Vector2f(50,650));
	xPosition = spider_.getPosition().x;
	yPosition = spider_.getPosition().y;
}

Spider::~Spider(){
	
}

void Spider::drawSpider(sf::RenderWindow& window){
	window.draw(spider_);
}

tuple<bool, int> Spider::moveSpiderRight(){
	if(spider_.getPosition().x < 766 && isRightBound == false){
		xDirection = 2;
		isRightBound = false;
	}
	else if(spider_.getPosition().x == 766){
		isRightBound = true;
		isLeftBound = false;
	}
	return {isRightBound, xDirection};
}

tuple<bool, int> Spider::moveSpiderLeft(){
	if(spider_.getPosition().x > 0 && isLeftBound == false){
		xDirection = -2;
		isLeftBound = false;
	}
	else if(spider_.getPosition().x == 0){
		isLeftBound = true;
		isRightBound = false;
	}
	return {isLeftBound, xDirection};
}

bool Spider::moveSpiderUp(int xMovement){
	if(spider_.getPosition().y >500 && isUpBound ==false){
		spider_.move(xMovement,-2);
		isUpBound = false;
	}
	else if(spider_.getPosition().y == 500){
		isUpBound = true;
		isLowBound = false;
	}
	return isUpBound;
}

bool Spider::moveSpiderDown(int xMovement){
	if(spider_.getPosition().y < 580 && isLowBound == false){
		spider_.move(xMovement,2);
		isUpBound =true;
	}
	else if(spider_.getPosition().y == 580){
		isLowBound = true;
		isUpBound = false;
	}
	return isLowBound;
}

void Spider::deleteSpider(){
	spider_.setScale(0,0);
}

sf::Sprite Spider::getSpider(){
	return spider_;
}

void Spider::setSpiderPosition(float x, float y){
	spider_.setPosition(x,y);
}