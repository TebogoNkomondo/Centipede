#include "bullet_Centipede_Collison_Handle.h"

//There is nothing to initialize in the constructor
bulletCentipeteCollision::bulletCentipeteCollision()
{
	isCollison= false;
	collisionIndex=0;
}

void bulletCentipeteCollision::setcentipedeSegmentScale_zero(vector <sf::Sprite>& centipede, int index)
{
	centipede.at(index).setScale(sf::Vector2f(0.0,0.0));
}

bool bulletCentipeteCollision::isCollisionMet()
{
	//uterlize the get global bound whatever thingy to see that a collision is met 
	return isCollison;
}

int bulletCentipeteCollision::getCollisonIndex()
{
	//
	return collisionIndex;
}
