#include "mushroomCollisionHandler.h"

mushroomCollisionHandler::mushroomCollisionHandler()
{
	numberOfMushrooms =10 + rand() % 7;
	//initialize the declare vector number of mushrooms
	for(int i=0; i< numberOfMushrooms;i++)
	{
		singleMushroom oneMushroom;
		mushrooms.push_back(oneMushroom);
	}
}

int mushroomCollisionHandler::getNumberOfmushrooms()
{
	return numberOfMushrooms;
}