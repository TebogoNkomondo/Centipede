//now we crete a singleMushroom class to display our mushroom
//we want to draw these mushrooms at random defined positions
//A mushroom is always aware of its current position.
#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "centipedeSegment.h"
#include <vector>

class singleMushroom
{
public:
	singleMushroom();
	
	void setSingleMushroomPosition();
	
	int getX_position();
	
	int getyPositition();
	
private:
	int xCoordinate;
	int yCoordinate;
};


#endif