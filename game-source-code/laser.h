#ifndef LASER_H
#define LASER_H

#include "player.h"


class Laser{
public:
	friend class Player;
	Laser(sf::Vector2u size);
	~Laser();
	
	void DrawBullet(sf::RenderWindow &window);
	void Shoot();
	void setPosition(sf::Vector2f newPos);
	sf::Sprite GetLaser();
	void deleteBullet();

private: 
	sf::Texture laser_;
	sf::Sprite bullet_;
};


#endif