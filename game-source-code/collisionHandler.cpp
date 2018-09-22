#include "collisionHandler.h"
using namespace std;

collisionHandler::collisionHandler(){
	a = 0;
	for(size_t i =0;bulletLoop.size();i++){
		bulletVec_.push_back(bulletLoop.at(i));	
	}
}

collisionHandler::~collisionHandler(){
	
}


/*void collisionHandler::bulletMushroom(){
	for(size_t i=0;i<BulletContainer::bulletLoop.size();i++){
		for( size_t k=0;k<mushroomsOnTheScreen.size();k++){
			if(bulletLoop[i].GetLaser().getGlobalBounds().intersects(mushroomsOnTheScreen[k].getMushroom().getGlobalBounds())){
				mushroomsOnTheScreen[k].deleteM();
				//bulletLoop[i].deleteM();
			}
		}
	}
}

void collisionHandler::deleteM(){
	mushroom_.setScale(0,0);
}*/

void collisionHandler::bulletSpider(sf::RenderWindow& window){
	//auto kk = bulletVector(i);
	for(size_t i= 0;bulletLoop.size();i++){
		if( bulletLoop.at(i).getBullet().getGlobalBounds() == spider_.getGlobalBounds()){
			spider_.setScale(0,0);
			//bulletLoop[i].getBullet().getGlobalBounds();
			//Spider::deleteSpider();
			window.draw(spider_);
		}
	}
	
	
}