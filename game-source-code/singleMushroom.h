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
///
/// The constructor initializes all mushrooms out of the screen.
///
	singleMushroom();
	
	/**
	 * @brief This function generates random x and y coordinates withing the boundary of the screen to place a mushroom object
	 */
	void setSingleMushroomPosition();
	
	/**
	 * @brief Get a mushroom's x coordinate
	 * @return The x position of a mushroom on the screen 
	 */
	int getX_position();
	
	/**
	 * @brief Get a mushroom's y coordinate
	 * @return The y position of a mushroom on the screen 
	 */
	int getyPositition();
	
private:
	int xCoordinate;
	int yCoordinate;
};


#endif