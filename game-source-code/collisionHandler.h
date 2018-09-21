#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "screen.h"


class collisionHandler : public BulletContainer, public screen{
public:
	collisionHandler();
	~collisionHandler();
	
	void bulletMushroom();
	void deleteM();
private:
	int a;
};

#endif