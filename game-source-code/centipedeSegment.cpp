#include "centipedeSegment.h"

centipedeSegment::centipedeSegment(double xCoordinate, double yCoordinate )
{
    //set the initial cordinates of a centipede segment.
    xPosition = xCoordinate;
    yPosition = yCoordinate;
	mushroomCollision= false;

    sideBoundary= true;
	bottomOfSCreenLeft= false;
	bottomOfScreenRight= false;
	mushroomCollisionTurnAndMoveRight= false; 
}

//This will move a centipede once in the fitting direction according to the if statements
void centipedeSegment::moveCentipedeSegment(bool mushroomCollision)
{
    
    if( ( (xPosition <screen_Width) && sideBoundary ) || mushroomCollisionTurnAndMoveRight || bottomOfScreenRight )
        {
            moveRight(Direction::Right);
        }

    if( (xPosition > (screen_Width-15) && sideBoundary ) || mushroomCollision)
        {
            for(int j=0; j<3; j++)
            {
                moveDown(Direction:: Down);
            }
            sideBoundary =false;
        }
    
        
    if( (!sideBoundary) || (mushroomCollision) || bottomOfSCreenLeft )
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
		
	if( (xPosition< 0 && yPosition >screen_Height-15 ) || (xPosition >screen_Width-20 && yPosition> screen_Height-25) ) 
	{
		for(int i=0; i< 20; i++)
		{
			moveUp(Direction::Up);
		}
		
		if(xPosition <0 && yPosition> screen_Height-15)
			bottomOfScreenRight=true;

		if(xPosition> screen_Width-20 && yPosition> screen_Height-25)
			bottomOfSCreenLeft= true;
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

void centipedeSegment::set_xCoordinate(double x)
{
	xPosition= x;
}

void centipedeSegment::set_yCoordinate(double y)
{
	yPosition= y;
}



