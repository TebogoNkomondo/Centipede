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

bool collisionHandler::playerSpider(Spider& spider1, Player& player1){
	if(spider1.getSpider().getGlobalBounds().intersects(player1.GetPlayer().getGlobalBounds())){
		spider1.deleteSpider();
		player1.deletePlayer();
		isPlayerDead = true;
	}
	return isPlayerDead;
}

/*bool collisionHandler::centipedePlayer(Player& player1, CentipedeTrain& centipede1){
	for(auto i = centipede1.getCentipedeVector().begin();i<centipede1.getCentipedeVector().end();i++){
		sf::FloatRect collidingObject1 = (*i).getCentipedeSegment().getGlobalBounds();
		sf::FloatRect collidingObject2 = player1.GetPlayer().getGlobalBounds();
		if(collidingObject1.intersects(collidingObject2)){
			isPlayerDead = true;
		}
	}
	return isPlayerDead;
}*/