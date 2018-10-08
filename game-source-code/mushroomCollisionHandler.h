//Create a vector of mushrooms:
//The mushroom collision handler calss should take in a centioede segment
//and constantly verify if this segment is in collision with a mushroom.
#include "singleMushroom.h"
#include "screen.h"
#include <vector>
class mushroomCollisionHandler
{
public:
///
///The constructor sets the number of mushrooms to display on the screen
///
	mushroomCollisionHandler();
	
	 /**
	  * @brief This function performs an algorith to detect if there is a collision between a centipede segment and a mushroom
	  * @param centipedeTrain The vector of centipede segments 
	  * @param my_screen the screen where the centipede is drawn
	  * @param index The centipede segment index within the vector of centipede segments for which mushroom collision tests are performed
	  * @return  A boolean is returned after the check algorithm for centipede mushroom collision is done.
	 * If true : A collision was detected
	 * If False : No collision detected
	  */
	bool isCollision(polyCentipede& centipedeTrain, screen& my_screen, int index); 
	
	/**
	 * @brief return the set number of mushrooms to generate. These mushrooms are generated in the screen class.
	 * @return : A number indicating how many mushrooms to be generated. 
	 */
	int getNumberOfmushrooms();
	
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