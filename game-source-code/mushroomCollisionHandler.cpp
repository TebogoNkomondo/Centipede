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
	
	centipedeX=centipedeTrain.myCentipede2.at((length_of_centipede- 1) - index).get_xCoordinate();
	centipedeY= centipedeTrain.myCentipede2.at((length_of_centipede-1) -index).get_yCoordinate();
	
	for(unsigned int j=0; j<my_screen.getVectorOfMushrooms().size(); j++ )
	{
		mushX=my_screen.getVectorOfMushrooms().at(j).getX_position();
		mushY= my_screen.getVectorOfMushrooms().at(j).getyPositition();

		if(centipedeX== mushX)
		{
			if(centipedeY== mushY)
			{
				collision= true;
				cout<< centipedeX<<"	"<<centipedeY<<endl;
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