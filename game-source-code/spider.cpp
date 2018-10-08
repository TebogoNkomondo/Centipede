#include "spider.h"
#include <iostream>
using namespace std;

Spider::Spider(){
	texture_ = spiderTexture_.spiderTexture();
	spider_.setTexture(texture_);
	spider_.setScale(sf::Vector2f(0.12,0.07));
	spider_.setPosition(sf::Vector2f(50,650));
}

Spider::~Spider(){}

void Spider::drawSpider(sf::RenderWindow& window){
	window.draw(spider_);
}

tuple<bool, int> Spider::moveSpiderRight(){
	auto rightBound = 766;
	if(spider_.getPosition().x < rightBound && isRightBound == false){
		xDirection = 2;
		isRightBound = false;
	}
	else if(spider_.getPosition().x == rightBound){
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
	auto playerMovementUpperBound = 500;
	if(spider_.getPosition().y >playerMovementUpperBound && isUpBound ==false){
		spider_.move(xMovement,-2);
		isUpBound = false;
	}
	else if(spider_.getPosition().y == playerMovementUpperBound){
		isUpBound = true;
		isLowBound = false;
	}
	return isUpBound;
}

bool Spider::moveSpiderDown(int xMovement){
	auto playerMovementLowerBound =580;
	if(spider_.getPosition().y < playerMovementLowerBound && isLowBound == false){
		spider_.move(xMovement,2);
		isUpBound =true;
	}
	else if(spider_.getPosition().y == playerMovementLowerBound){
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

void Spider::regenerateSpider(){
	if(period<500){
		period++;
	}
	else{
		spider_.setScale(sf::Vector2f(0.12,0.07));
		period =0;
	}
}

void Spider::setSpiderPosition(float x, float y){
	spider_.setPosition(x,y);
}