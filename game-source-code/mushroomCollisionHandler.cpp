#include "mushroomCollisionHandler.h"
#include <math.h>

mushroomCollisionHandler::mushroomCollisionHandler()
{
	numberOfMushrooms =25;
}

bool mushroomCollisionHandler::isCollision (polyCentipede& centipedeTrain, screen& my_screen, int index)
{
	//reset the boolean
	collision= false;
	
	centipedeX=centipedeTrain.myCentipede2.at(index ).get_xCoordinate();
	centipedeY= centipedeTrain.myCentipede2.at(index ).get_yCoordinate();
	
	for(unsigned int j=0; j<my_screen.getVectorOfMushrooms().size(); j++ )
	{
		mushX=my_screen.getVectorOfMushrooms().at(j).getX_position();
		mushY= my_screen.getVectorOfMushrooms().at(j).getyPositition();
		centipedeCirc= sqrt(pow(centipedeX,2) + pow(centipedeY,2));
		mushCirc= sqrt(pow(mushX,2)+ pow(mushY,2));
		
		if(centipedeCirc+0.5<mushCirc || centipedeCirc-0.5 < mushCirc || centipedeCirc== mushCirc)
		{
			if(centipedeX == mushX)
			{
				for(int k=0; k<20; k+=5){
					if( (centipedeY+ k == mushY) || (centipedeY-k == mushY) )
					{
						collision= true;
						cout<< centipedeX <<"	"<<centipedeY<<endl;
						return collision;
					}
					
				}
			}
		}
	}
		
	return collision;
}

//void centipedeChangeDirection(polyCentipede& centipedeTrain, int index ,bool collision)
//{
//	if(collision)
//}

int mushroomCollisionHandler::getNumberOfmushrooms()
{
	return numberOfMushrooms;
}
