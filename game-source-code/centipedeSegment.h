#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "movableObject.h"
#include <iostream>
#define screen_Width 800
#define screen_Height 600


//A centipede segment is a movable object so inherit from movableObject class
class centipedeSegment: public movableObject
{
public:
    //centipede parameters
    centipedeSegment(double xCoordinate, double yCoordinate);
    //Function to move centipede in suitable direction
    void moveCentipedeSegment(bool mushroomCollision);
    
    //get x coordinate of centipedeSegment
    double get_xCoordinate();
    
    //get y coordinate of centipedeSegment
    double get_yCoordinate();
    
private:
    //A movable object should know when it is at the boundary of the screen
    bool sideBoundary;
	bool mushroomCollision;
};

#endif