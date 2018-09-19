#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){

	if(!real_.loadFromFile("resources/purple.png")){
		cout<<"falied to load player file"<<endl;
	}
	player_.setTexture(real_);
	player_.setScale(sf::Vector2f(0.35,0.35));
	player_.setPosition(sf::Vector2f(windowWidth/2,windowHeight-windowHeight/20));
	xPosition = player_.getPosition().x;
	yPosition = player_.getPosition().y;
}

Player::~Player(){
	
}

void Player::Draw(sf::RenderWindow &window){
	window.draw(player_);
}

sf::Sprite Player::GetPlayer(){
	return player_;
}

void Player::setPosition(sf::Vector2f newPos){
	player_.setPosition(newPos);
}

void Player::handleKey(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
		MoveRight();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
		MoveLeft();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
		MovePlayerDown();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
		MovePlayerUp();
	}
}

void Player::MoveRight(){
		if(xPosition >= windowWidth-windowWidth/23){
			player_.setPosition(xPosition,yPosition);
		}
		else{
			moveRight(Direction:: Right);
			player_.setPosition(xPosition,yPosition);
		}
}

void Player::MoveLeft(){
		if(xPosition <= xPosition/15){
			player_.setPosition(xPosition,yPosition);
		}
		else{
			moveLeft(Direction:: Left);
			player_.setPosition(xPosition,yPosition);
		}
}

void Player::MovePlayerDown(){
		if(yPosition >= windowHeight-yPosition/19){
			player_.setPosition(xPosition,yPosition);
		}
		else{
			moveDown(Direction:: Down);
			player_.setPosition(xPosition,yPosition);
		}
}

void Player::MovePlayerUp(){
		if(yPosition <= windowHeight-yPosition/5){
			player_.setPosition(xPosition,yPosition);
		}
		else{
			moveUp(Direction:: Up);
			player_.setPosition(xPosition,yPosition);
		}
}

float Player::getXPos(){
	return xPosition;
}

float Player::getYPos(){
	return yPosition;
}