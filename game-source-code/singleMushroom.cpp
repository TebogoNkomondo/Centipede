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
	//Make both x and y coordinates of mushroom multiples of 5;
	do{
		xCoordinate= rand()%750 + 30;
	}while(xCoordinate % 5 !=0);
	
	do{
		yCoordinate= rand()%550 +30;
	}while(yCoordinate %5 !=0);
	
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
