#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "spider.h"
#include "laser.h"
#include "polyCentipede.h"
#include "player.h"
#include "scoreTracker.h"

class collisionHandler  {
public:
	collisionHandler();
	~collisionHandler();
	
	void bulletMushroom();
	
	tuple<bool,int> bulletSpider(Spider& spider1, std::vector<Laser>& bulletStorage);
	
	bool playerSpider(Spider& spider1, Player& player1);
	
	int bulletCentipede(std::vector<Laser>& bulletStorage1, std::vector<sf::Sprite>& centipedeStorage);
	
	bool playerCentipede(Player& player1, std::vector<sf::Sprite>& centipedeStorage);
	
	void bullet_Mushroom_Collision(std::vector<Laser>& bulletLoop1, std::vector<sf::Sprite>& mushroomsOnTheScreen );
	
protected:
	ScoreTracker myscore;
private:
	bool isPlayerDead = false;
	vector<Laser> bulletVec_;
	int centipedesLeft =length_of_centipede;
	bool playerStatus = false;
	
};

#endif