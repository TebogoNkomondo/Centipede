#include "singleMushroom.h"
#include <iostream>
using namespace std;

singleMushroom::singleMushroom()
{
	//initially set the position of the mushroom outside the screen
	xCoordinate= screen_Width + 150;
	yCoordinate= screen_Height +150;
}

void singleMushroom::setSingleMushroomPosition()
{
	xCoordinate= rand()%750 + 30;
	yCoordinate= rand()%550 +30;
	
	cout<<xCoordinate<< " "<<yCoordinate<<endl;
}

int singleMushroom::getX_position()
{
	return xCoordinate;
}

int singleMushroom::getyPositition()
{
	return yCoordinate;
}
