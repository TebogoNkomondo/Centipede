#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "spider.h"
#include "laser.h"
#include "polyCentipede.h"
#include "player.h"



class collisionHandler  {
public:
	collisionHandler();
	~collisionHandler();
	
	void bulletMushroom();
	
	tuple<bool,int> bulletSpider(Spider& spider1, std::vector<Laser>& bulletStorage);
	
	bool playerSpider(Spider& spider1, Player& player1);
	
	int bulletCentipede(std::vector<Laser>& bulletStorage1, std::vector<sf::Sprite>& centipedeStorage);
	
	bool playerCentipede(Player& player1, std::vector<sf::Sprite>& centipedeStorage);
	
	int getShotCentipedeIndex();
	int getShot_X();
	int getShot_Y();
	
	void resetShotCentipedeIndex(int negativeNumber);
	
private:
	bool isPlayerDead = false;
	vector<Laser> bulletVec_;
	int centipedesLeft =length_of_centipede;
	int shotCentipedeIndex;
	int shotSegmentX_position;
	int shotSegmentY_position;
	
};

#endif