#ifndef BULLETCONTAINER_H
#define BULLETCONTAINER_H
#include "laser.h"

class BulletContainer : public Player {
public:
	BulletContainer();
	~BulletContainer();
	
	void shootKey();
	void addBullet(float x, float y);
	void DrawBullets(sf::RenderWindow& window);
	void deleteBullets();
	
protected:
	Laser bullet1;
	std::vector<Laser>bulletLoop;
	std::vector<Laser>::const_iterator iter;
	bool isFiring;
	Player player1;
};

#endif