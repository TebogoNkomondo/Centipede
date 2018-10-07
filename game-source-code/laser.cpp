#include "laser.h"
#include "player.h"
#include <vector>
#include <iostream>
using namespace std;
/*
	Constructor initialises laser dimensions
 */
Laser::Laser(){
	laser_ = laser1.laserTexture();
	bullet_.setTexture(laser_);
	bullet_.setScale(sf::Vector2f(0.2,0.2));
}

Laser::~Laser(){}

void Laser::DrawBullet(sf::RenderWindow &window){
	window.draw(bullet_);
}

void Laser::Shoot(){
	bullet_.move(0,-10);
}


void Laser::setPosition(float x,float y){
	bullet_.setPosition(x,y);
}

sf::Sprite Laser::getBullet(){
	return bullet_;
}

void Laser::deleteLaser(){
	bullet_.setScale(0,0);
}

