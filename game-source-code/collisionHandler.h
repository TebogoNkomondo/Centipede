#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "screen.h"
#include "laser.h"
//#include <vector>


class collisionHandler: public BulletContainer, public Spider, public Laser {
public:
	collisionHandler();
	~collisionHandler();
	
	void bulletMushroom();
	void bulletSpider(sf::RenderWindow& window);
	
	void deleteM();
private:
	int a;
	vector<Laser> bulletVec_;
	Laser oneTh;
};

#endif