#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "movableObject.h"
#include <iostream>
#define screen_Width 800
#define screen_Height 600
#include <SFML/Graphics.hpp>


//A centipede segment is a movable object so inherit from movableObject class
class centipedeSegment: public movableObject
{
public:
    //centipede parameters
    centipedeSegment(double xCoordinate, double yCoordinate);
    //Function to move centipede in suitable direction
    void moveCentipedeSegment(bool mushroomCollision);
	
	//set x coordinates at particular position
	void set_xCoordinate(double x);
	
    void set_yCoordinate(double y);
    //get x coordinate of centipedeSegment
    double get_xCoordinate();
    
    //get y coordinate of centipedeSegment
    double get_yCoordinate();
	
	//get which boundary (left of right) the centipede is coming from
	bool getRightCollideBoundary();
	
	bool getLeftCollideBoundary();
    
private:
    //A movable object should know when it is at the boundary of the screen
    bool sideBoundary;
	bool mushroomCollision;
	bool bottomOfSCreenLeft;
	bool bottomOfScreenRight;
	bool mushroomCollisionTurnAndMoveRight;
	
	bool leftMushroom;
	bool rightMushroom;
	
	sf::Sprite centipedeSegment1;
	sf::Texture centipedeTexture1;
};

#endif