#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "spider.h"
#include "laser.h"
//#include <vector>


class collisionHandler {
public:
	collisionHandler();
	~collisionHandler();
	
	void bulletMushroom();
	
	void bulletSpider(Spider& spider1, BulletContainer& bulletStorage);
	
	void deleteM();
private:
	vector<Laser> bulletVec_;
};

#endif