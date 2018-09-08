#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){

	if(!real_.loadFromFile("resources/purple.png")){
		cout<<"falied to load player file"<<endl;
	}
	player_.setTexture(real_);
	player_.setScale(sf::Vector2f(0.35,0.35));
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
		MoveDown();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
		MoveUp();
	}
	
}

void Player::MoveRight(){
		if(player_.getPosition().x >= windowWidth-player_.getScale().x*90){
			player_.move(0,0);
		}
		else{
			player_.move(5,0);
		}
}

void Player::MoveLeft(){
		if(player_.getPosition().x <= player_.getScale().x*15){
			player_.move(0,0);
		}
		else{
			player_.move(-5,0);
		}
}

void Player::MoveDown(){
		if(player_.getPosition().y >= windowHeight-player_.getScale().y*90){
			player_.move(0,0);
		}
		else{
			player_.move(0,5);
		}
}

void Player::MoveUp(){
		if(player_.getPosition().y <= windowHeight - player_.getScale().y*300){
			player_.move(0,0);
		}
		else{
			player_.move(0,-5);
		}
}