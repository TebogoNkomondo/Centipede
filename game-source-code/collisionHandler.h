#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "spider.h"
#include "laser.h"
//#include "centipedeTrain.h"
#include "player.h"



class collisionHandler  {
public:
	collisionHandler();
	~collisionHandler();
	
	void bulletMushroom();
	
	void bulletSpider(Spider& spider1, BulletContainer& bulletStorage);
	
	bool playerSpider(Spider& spider1, Player& player1);
	
	//bool centipedePlayer(Player& player1, CentipedeTrain& centipede1);
private:
	bool isPlayerDead = false;
	vector<Laser> bulletVec_;
};

#endif