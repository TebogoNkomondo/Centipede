#include "movableObject.h"
#include <iostream>


//A centipede segment is a movable object so inherit from movableObject class
class centipedeSegment: public movableObject
{
public:
    //centipede parameters
    centipedeSegment(double xCoordinate, double yCoordinate);
    //Function to move centipede in suitable direction
    void moveCentipedeSegment();
    
private:
    //A centepide segment should know when it is at the boundary of the screen
    bool sideBoundary;
};
