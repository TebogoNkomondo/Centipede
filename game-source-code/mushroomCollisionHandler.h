//Create a vector of mushrooms:
//The mushroom collision handler calss should take in a centioede segment
//and constantly verify if this segment is in collision with a mushroom.
#include "singleMushroom.h"
#include "polyCentipede.h"
#include <vector>
class mushroomCollisionHandler
{
public:
	mushroomCollisionHandler();
	
	bool isCollision( polyCentipede& centipedeTrain); 
	
	int getNumberOfmushrooms();
	
private:
	bool isCollison();
	vector<singleMushroom> mushrooms;
	int numberOfMushrooms;
	
};