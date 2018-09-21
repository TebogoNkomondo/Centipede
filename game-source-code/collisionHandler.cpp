#include "collisionHandler.h"

collisionHandler::collisionHandler(){
	a = 0;
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