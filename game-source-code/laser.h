#ifndef LASER_H
#define LASER_H

#include "player.h"
#include "spriteGetter.h"

class Laser {
public:
	Laser();
	~Laser();
	
	void DrawBullet(sf::RenderWindow &window);
	void Shoot();
	void setPosition(float x, float y);
	void deleteLaser();
	sf::Sprite getBullet();

private: 
	sf::Texture laser_;
	sf::Sprite bullet_;
	SpriteGetter laser1;
};


#endif