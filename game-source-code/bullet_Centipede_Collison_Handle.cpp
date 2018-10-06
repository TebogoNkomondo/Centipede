#include "bullet_Centipede_Collison_Handle.h"

//There is nothing to initialize in the constructor
bulletCentipeteCollision::bulletCentipeteCollision()
{
	isCollison= false;
	centipedeCollisionIndex=-1;
}

void bulletCentipeteCollision::setcentipedeSegmentScale_zero( vector <sf::Sprite>& centipede)
{
	if(isCollison)
	{
		centipede.at(centipedeCollisionIndex).setScale(sf::Vector2f(0.0,0.0));
	}
}

//bool bulletCentipeteCollision::isCollisionMet(vector <sf::Sprite>& centipedeTrain, std::vector<Laser>& bulletLoop)
//{
//	//uterlize the get global bound whatever thingy to see that a collision is met
//	for(int j=my_screen.centipede.size()-1; j> -1; j--)
//	{
//		int i=0;
//		do
//		{
//			if(centipedeTrain[j].getGlobalBounds() == bulletLoop[i].getGlobalBounds() )
//			{
//				centipedeCollisionIndex=j;
//				isCollison= true;
//			} 
//			
//			i+=1;
//		}while((centipedeTrain[j].getGlobalBounds() != bulletLoop[i].getGlobalBounds()));
//	}
//		
//	return isCollison;
//}

int bulletCentipeteCollision::getCollisonIndex()
{
	return centipedeCollisionIndex;
}
