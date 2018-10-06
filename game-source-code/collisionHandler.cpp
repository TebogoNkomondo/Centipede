#include "collisionHandler.h"
#include <iostream>
using namespace std;

collisionHandler::collisionHandler(){}

collisionHandler::~collisionHandler(){
	
}

tuple<bool, int> collisionHandler::bulletSpider(Spider& spider1, std::vector<Laser>& bulletStorage){
	bool isBullet = false;
	int bulletIndex=0;
	for(auto i = bulletStorage.begin(); i<bulletStorage.end();i++,bulletIndex++){
		sf::FloatRect collidingObject1 = (*i).getBullet().getGlobalBounds();
		sf::FloatRect collidingObject2 = spider1.getSpider().getGlobalBounds();
		isBullet = false;
		if(collidingObject1.intersects(collidingObject2)){
			spider1.deleteSpider();
			isBullet = true;
			bulletStorage.erase(i);
			myscore.updateCurrentScore();
			myscore.updateHighScore();
			return {isBullet, bulletIndex};
		}
	}
	return {false, 0};
}

bool collisionHandler::playerSpider(Spider& spider1, Player& player1){
	if(spider1.getSpider().getGlobalBounds().intersects(player1.GetPlayer().getGlobalBounds())){
		spider1.deleteSpider();
		player1.deletePlayer();
		isPlayerDead = true;
	}
	return isPlayerDead;
}

int collisionHandler::bulletCentipede(std::vector<Laser>& bulletStorage1, std::vector<sf::Sprite>& centipedeStorage){
	
	for(size_t i=0;i<bulletStorage1.size();i++){
		for(size_t t=0;t<centipedeStorage.size();t++){
			sf::FloatRect collidingObject1 = bulletStorage1.at(i).getBullet().getGlobalBounds();
			sf::FloatRect collidingObject2 = centipedeStorage.at(t).getGlobalBounds();
			if(collidingObject1.intersects(collidingObject2)){
				bulletStorage1.at(i).deleteLaser();
				centipedeStorage.at(t).setScale(0,0);
				myscore.updateCurrentScore();
				myscore.updateHighScore();
			}
			
		}
	}
	return centipedesLeft;
}


bool collisionHandler::playerCentipede(Player& player1, std::vector<sf::Sprite>& centipedeStorage){
		bool playerStatus = false;
		for(auto i = centipedeStorage.begin();i<centipedeStorage.end();i++){
			sf::FloatRect collidingObject1 = player1.GetPlayer().getGlobalBounds();
			sf::FloatRect collidingObject2 = (*i).getGlobalBounds();
			if(collidingObject1.intersects(collidingObject2)){
				playerStatus = true;
			}
		}
	return playerStatus;
}

void collisionHandler::bullet_Mushroom_Collision(std::vector<Laser>& bulletLoop1, std::vector<sf::Sprite>& mushroomsOnTheScreen ){
	for(auto i= bulletLoop1.begin(); i< bulletLoop1.end() ;i++){
		for(auto t=mushroomsOnTheScreen.begin(); t<mushroomsOnTheScreen.end();t++){
			sf::FloatRect col1 = (*i).getBullet().getGlobalBounds();  
			sf::FloatRect col2 = (*t).getGlobalBounds(); 
			if(col1.intersects(col2)){
				(*t).setScale(0,0); 
				(*i).deleteLaser();
				myscore.updateCurrentScore();
				myscore.updateHighScore();
			}
		}
	}
}
