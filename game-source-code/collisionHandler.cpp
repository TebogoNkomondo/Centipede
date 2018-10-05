#include "collisionHandler.h"
using namespace std;

collisionHandler::collisionHandler(){
	shotCentipedeIndex = -1;
}

collisionHandler::~collisionHandler(){
	
}

tuple<bool, int> collisionHandler::bulletSpider(Spider& spider1, std::vector<Laser>& bulletStorage){
	bool isBullet = false;
	int ii=0;
	for(auto i = bulletStorage.begin(); i<bulletStorage.end();i++,ii++){
		sf::FloatRect collidingObject1 = (*i).getBullet().getGlobalBounds();
		sf::FloatRect collidingObject2 = spider1.getSpider().getGlobalBounds();
		isBullet = false;
		if(collidingObject1.intersects(collidingObject2)){
			spider1.deleteSpider();
			isBullet = true;
			bulletStorage.erase(i);
			return {isBullet, ii};
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
				centipedeStorage.at(t).setScale(0,0);
				bulletStorage1.at(i).deleteLaser();
				centipedesLeft-=1;
				shotCentipedeIndex= t;
			}
			
		}
	}
	return centipedesLeft;
}

int collisionHandler::getShotCentipedeIndex()
{
	return shotCentipedeIndex;
}

void collisionHandler::resetShotCentipedeIndex(int negativeNumber)
{
	shotCentipedeIndex= negativeNumber;
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