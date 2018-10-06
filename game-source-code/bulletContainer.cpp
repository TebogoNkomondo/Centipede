#include "bulletContainer.h"
#include <iostream>


BulletContainer::BulletContainer(){
	isFiring = false;
}

BulletContainer::~BulletContainer(){}

void BulletContainer::shootKey(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ){
		isFiring = true; 
	}
}

void BulletContainer::addBullet(float x, float y,std::vector<Laser>& bulletL){
	auto bulletPositionAdjuctFactor(13);
	if(isFiring == true){
		bullet1.setPosition(x+bulletPositionAdjuctFactor,y);
		bulletL.push_back(bullet1);
		isFiring = false;
	}
}

void BulletContainer::DrawBullets(sf::RenderWindow& window, std::vector<Laser>& bulletL){
	for(int i=0,kk=bulletL.size();i<kk;i++){
		bulletL[i].Shoot();
		bulletL[i].DrawBullet(window);
	}
}

void BulletContainer::deleteBullets(std::vector<Laser>& bulletL){
	int counter=0;
	for(iter=bulletL.begin();iter<bulletL.end();iter++){
		if(bulletL[counter].getBullet().getPosition().y<0){
			bulletL.erase(iter);
		}
		counter++;
	}
}


