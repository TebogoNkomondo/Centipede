#include "centipedeSegment.h"
#define screen_Width 800
#define screen_Height 600

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
            cout<< xPosition<<endl;
        }

    if(xPosition > (screen_Width-15) && sideBoundary)
        {
            for(int j=0; j<3; j++)
            {
                move(Direction::Down);
            }
            sideBoundary =false;
        }
    
        
    if(!sideBoundary)
            {
               move(Direction::Left);
            }
            
    if(xPosition < 0 && !sideBoundary)
        {
            for(int t=0; t<3; t++)
            {
                move (Direction::Down);
            }
            sideBoundary= true;
        }
}

double centipedeSegment::get_xCoordinate()
{
    return xPosition;
}

double centipedeSegment::get_yCoordinate()
{
    return yPosition;
}



