#ifndef LASER_H
#define LASER_H

#include "player.h"
#include "spriteGetter.h"

class Laser {
public:
	/**
	 * Laser dimensions are initialised
	 * SpriteGetter is called to provide player texture
	 */
	Laser();
	/**
	 * Default destructor
	 */
	~Laser();
	/**
	 * @brief draws the laser sprite on the screen
	 * @param window : window where bullet will be drawn
	 */
	void DrawBullet(sf::RenderWindow &window);
	/**
	 * move the bullet object in the screen
	 */
	void Shoot();
	/**
	 * @brief this function sets the laser sprite at co-ordinates (x,y)
	 * @param x : x co-ordinate of laser
	 * @param y : y co-ordinate of laser
	 */
	void setPosition(float x, float y);
	/**
	 * @brief sets the laser scale to (0,0), hence deleting the laser from the screen.
	 */
	void deleteLaser();
	
	/**
	 * @brief returns the proporties of the laser sprite so that its properties can be accessed for collisions.
	 * @return : laser sprite is returned.
	 */
	sf::Sprite getBullet();

private: 
	/**
	*laser_ stores laser texture that is fetched from spriteGetter class
	* bullet_ stores laser sprite
	* laser1 is the object by composition that is used for fecthing laser textures from spriteGetter.
	*/
	sf::Texture laser_;
	sf::Sprite bullet_;
	SpriteGetter laser1;
};


#endif