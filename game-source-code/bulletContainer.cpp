#include "bulletContainer.h"
#include <iostream>


BulletContainer::BulletContainer(){
	isFiring = false;
}

BulletContainer::~BulletContainer(){
	
}

void BulletContainer::shootKey(){
/*	int shootTimer =0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootTimer<5){
		shootTimer++;
	}*/
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ){
		isFiring = true; 
		//shootTimer=0;
	}
}

void BulletContainer::addBullet(float x, float y){
	auto bulletPositionAdjuctFactor(13);
	if(isFiring == true && bulletLoop.size()<15){
		bullet1.setPosition(x+bulletPositionAdjuctFactor,y);
		bulletLoop.push_back(bullet1);
		isFiring = false;
	}
}

void BulletContainer::DrawBullets(sf::RenderWindow& window){
	for(int i=0,kk=bulletLoop.size();i<kk;i++){
		bulletLoop[i].Shoot();
		bulletLoop[i].DrawBullet(window);
	}
}

void BulletContainer::deleteBullets(){
	int counter=0;
	for(iter=bulletLoop.begin();iter<bulletLoop.end();iter++){
		if(bulletLoop[counter].getBullet().getPosition().y<0){
			bulletLoop.erase(iter);
		}
	counter++;
	}
}

Laser BulletContainer::bulletVector(int i){
	return bulletLoop.at(i);
}

std::vector<Laser> BulletContainer::getBulletVector(){
	return bulletLoop;
}

void BulletContainer::deleteCollidedBullets(int i){
	bulletLoop.at(i).deleteLaser();
}