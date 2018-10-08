#ifndef COLLISSIONHANDLER_H
#define COLLISSIONHANDLER_H
#include "bulletContainer.h"
#include "spider.h"
#include "laser.h"
#include "polyCentipede.h"
#include "player.h"
#include "scoreTracker.h"

class collisionHandler  {
public:
	collisionHandler();
	~collisionHandler();
	
	/**
	 * @brief handles collisions between spider and bullets. If a spider is hit by a bullet it dies
	 * @param spider1 : the spider object is passed in as a parameter into this function
	 * @param bulletStorage : vector containing bullets is also by in as parameter
	 * @return : returns true and the index of the bullet that has collided with spider if collision occurs
	 */
	tuple<bool,int> bulletSpider(Spider& spider1, std::vector<Laser>& bulletStorage);
	/**
	 * @brief handles colissions between the player and spider. If spider and player collide then the player gets killed.
	 * @param spider1 : this is the spider object
	 * @param player1 : this is the player object
	 * @return : returns true if the player is dead and false if the player is alive
	 */
	bool playerSpider(Spider& spider1, Player& player1);
	/**
	 * @brief handles colissions between the bullet and the centipede segments. A centipede segment that has collided with a bullet dies
	 * @param bulletStorage1 : vector containing bullets
	 * @param centipedeStorage : vector containing centipede segments in the centipede train.
	 * @return : returns the number of centipede segments in the train that are still alive.
	 */
	int bulletCentipede(std::vector<Laser>& bulletStorage1, std::vector<sf::Sprite>& centipedeStorage);
	/**
	 * @brief handles player and centipede colissions. The player dies if it collides with any of the centipede segments in the centipede train
	 * @param player1 : this is the player object
	 * @param centipedeStorage : vector containing the centipede segments that are still alive.
	 * @return : returns true if the player is dead and false if the player is alive.
	 */
	bool playerCentipede(Player& player1, std::vector<sf::Sprite>& centipedeStorage);
	/**
	 * @brief handles bullet and Mushroom collisions. Mushrooms which are hit by bullets die.
	 * @param bulletLoop1 : vector containing the bullets that have been fired
	 * @param mushroomsOnTheScreen : vector containing the mushrooms on the screen
	 */
	void bullet_Mushroom_Collision(std::vector<Laser>& bulletLoop1, std::vector<sf::Sprite>& mushroomsOnTheScreen );
	
protected:
	/**
	*scoreTracker is by composition an object that is created so that it the game scores can be updated in the scoreTracker class
	*/
	ScoreTracker myscore;
private:
	bool isPlayerDead = false;
	int centipedesLeft =length_of_centipede;
	bool playerStatus = false;
	
};

#endif