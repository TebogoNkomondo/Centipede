#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "movableObject.h"
#include "spriteGetter.h"

class Player : public movableObject {
public:
	/*
	 * Player texture is fetched from spriteGetter in the constructor 
	 * Player sprite properties are set in the constructor
	 */
	Player();
	/**
	*default destructor
	 */
	~Player();
	/**
	 * @brief draws the player sprite onto the window
	 * @param window : player sprit is drawn here
	 */
	void Draw(sf::RenderWindow &window);
	/**
	 * @brief used for checking user input for player directions, then calls one of the diretion functions from above.
	 */
	void handleKey();
	/**
	 * @brief if called moves the player up 
	 * uses inherited characteristics from movableObject onject class to move the player
	 */
	void MovePlayerUp();
		/**
	 * @brief if called moves the player down 
	 * uses inherited characteristics from movableObject onject class to move the player
	 */
	void MovePlayerDown();
	/**
	 * @brief if called moves the player left 
	 * uses inherited characteristics from movableObject onject class to move the player
	 */
	void MoveLeft();
	/**
	 * @brief if called moves the player right 
	 * uses inherited characteristics from movableObject onject class to move the player
	 */
	void MoveRight();
	/**
	 * @brief returns x position(co-ordinate) of player on screen
	 * @return : player x position
	 */
	float getXPos();
	/**
	 * @brief returns y position(co-ordinate) of player on screen
	 * @return : player y position
	 */
	float getYPos();
	/**
	 * @brief returns player sprite properties to be used for checking collisions with other game objects
	 * @return : player sprite properties
	 */
	sf::Sprite GetPlayer();
	/**
	 * @brief sets player position to specified co-ordinates in newPos(x,y)
	 * @param newPos : vector containing x and y co-ordinates for the player sprite to be set
	 */
	void setPosition(sf::Vector2f newPos);
	/**
	 * @brief sets player sprite scale to (0,0), hence deleting player from screen
	 */
	void deletePlayer();
	
protected:
	/**
	 * real1_ stores player texture that is to be fecthed from spriteGetter class
	 * player_ stores player sprite
	 * real_ object to store player texture that is fetched from the spriteGetter class
	 */
	sf::Texture real1_;
	sf::Sprite player_;
	SpriteGetter real_;
private:
	int windowWidth = 800;
	int windowHeight = 600;
	
};

#endif