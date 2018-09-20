//Create a vector of mushrooms:
//The mushroom collision handler calss should take in a centioede segment
//and constantly verify if this segment is in collision with a mushroom.
#include "singleMushroom.h"
#include "screen.h"
#include <vector>
class mushroomCollisionHandler
{
public:
	mushroomCollisionHandler();
	
	bool isCollision(polyCentipede& centipedeTrain, screen& my_screen, int index); 
	
	int getNumberOfmushrooms();
	
	void centipedeChangeDirection(polyCentipede& centipedeTrain, int index ,bool collision);
	
private:
	bool collision;
	int centipedeX;
	int centipedeY;
	int mushX;
	int mushY;
	int numberOfMushrooms;
	int centipedeCirc;
	int mushCirc;
	
};