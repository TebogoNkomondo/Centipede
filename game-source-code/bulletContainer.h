#ifndef BULLETCONTAINER_H
#define BULLETCONTAINER_H
#include "laser.h"
#include <vector>

class BulletContainer : public Player {
public:
	BulletContainer();
	~BulletContainer();
	/**
	 * @brief checks if the space bar key has been pressed
	 */
	void shootKey();
	/**
	 * @brief if the space bar button has been pressed, this functions loads bullets into the bullet containing vector bulletL,
	 * also sets the bullet position at the position of the player at the time a bullet is fired
	 * @param x : current x co-ordinate of player
	 * @param y : current y- co-ordinate of player
	 * @param bulletL : vector storing bulletss
	 */
	void addBullet(float x, float y, std::vector<Laser>& bulletL);
	/**
	 * @brief draws bullets onto the screen
	 * @param window : window on which bullets are drawn
	 * @param bulletL : vector containing bullets to be drawn
	 */
	void DrawBullets(sf::RenderWindow& window, std::vector<Laser>& bulletL);
	/**
	 * @brief deletes a bullet that has collided with another object by setting its scale to (0,0)
	 * @param bulletL : vector containing bullets
	 */
	void deleteBullets(std::vector<Laser>& bulletL);
	
protected:
	Laser bullet1;
	std::vector<Laser>::const_iterator iter;
	bool isFiring;
	Player player1;
};

#endif