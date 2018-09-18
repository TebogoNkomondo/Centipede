#include "bulletContainer.h"
#include <iostream>


BulletContainer::BulletContainer(): isFiring(false){}

BulletContainer::~BulletContainer(){
	
}

void BulletContainer::shootKey(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
		isFiring = true; 
	}
}

void BulletContainer::addBullet(float x, float y){
	auto bulletPositionAdjuctFactor(13);
	if(isFiring == true){
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
/*		if(bulletLoop.size()<=2){
			counter=0;
			break;
		}*/
	}
	cout<<bulletLoop.size()<<std::endl;
}


