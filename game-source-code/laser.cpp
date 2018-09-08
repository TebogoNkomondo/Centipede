#include "laser.h"
#include "player.h"
#include <vector>
#include <iostream>
using namespace std;



Laser::Laser(){
	if(!laser_.loadFromFile("resources/bullet.png")){
		cout<<"falied to load laser file"<<endl;
	}
	bullet_.setTexture(laser_);
	bullet_.setScale(sf::Vector2f(0.2,0.2));
}

Laser::~Laser(){
	
}

void Laser::DrawBullet(sf::RenderWindow &window){
	window.draw(bullet_);
	
}

void Laser::Shoot(){
		bullet_.move(0,-10);
}

sf::Sprite Laser::GetLaser(){
	return bullet_;
}

void Laser::setPosition(sf::Vector2f newPos){
	bullet_.setPosition(newPos);
}

void Laser::deleteBullet(){
	bullet_.setScale(sf::Vector2f(0,0));
}




