#include "collisionHandler.h"
using namespace std;

collisionHandler::collisionHandler(){
	
}

collisionHandler::~collisionHandler(){
	
}

void collisionHandler::bulletSpider(Spider& spider1, BulletContainer& bulletStorage){
	for(auto i = bulletStorage.getBulletVector().begin(); i<bulletStorage.getBulletVector().end();i++){
		sf::FloatRect collidingObject1 = (*i).getBullet().getGlobalBounds();
		sf::FloatRect collidingObject2 = spider1.getSpider().getGlobalBounds();
		if(collidingObject1.intersects(collidingObject2)){
			spider1.deleteSpider();
			(*i).deleteLaser();
		}
	}
}