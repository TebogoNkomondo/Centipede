#include "screen.h"
//This class will be responsibke for handing collisions
//between the bullet and the centipede.

class bulletCentipeteCollision
{
public:
	bulletCentipeteCollision();
	//Basic:functionality- the centipede segment that collided wit the bullet dissapers from the screen
	//centipede continues to move its projected direction
	void setcentipedeSegmentScale_zero(vector <sf::Sprite>& centipede, int index);
	//Run condition to test if a collision is met
	bool isCollisionMet();
	//get the index of where the collison occured;
	int getCollisonIndex();
	
private:
	bool isCollison;
	int collisionIndex;

};