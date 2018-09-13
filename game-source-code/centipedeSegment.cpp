#include "centipedeSegment.h"

centipedeSegment::centipedeSegment(double xCoordinate, double yCoordinate )
{
    //set the initial cordinates of a centipede segment.
    xPosition = xCoordinate;
    yPosition = yCoordinate;

    sideBoundary= true;
}

//This will move a centipede once in the fitting direction according to the if statements
void centipedeSegment::moveCentipedeSegment()
{
    
    if(xPosition <screen_Width && sideBoundary )
        {
            moveRight(Direction:: Right);
        }

    if(xPosition > (screen_Width-15) && sideBoundary)
        {
            for(int j=0; j<3; j++)
            {
                moveDown(Direction::Down);
            }
            sideBoundary =false;
        }
    
        
    if(!sideBoundary)
            {
               moveLeft(Direction::Left);
            }
            
    if(xPosition < 0 && !sideBoundary)
        {
            for(int t=0; t<3; t++)
            {
                moveDown(Direction::Down);
            }
            sideBoundary= true;
        }
        
    //Implement moving up functionality when at the botoom of the screen
}

double centipedeSegment::get_xCoordinate()
{
    return xPosition;
}

double centipedeSegment::get_yCoordinate()
{
    return yPosition;
}



