#ifndef SPRITEGETTER_H
#define SPRITEGETTER_H
#include <SFML/Graphics.hpp>
#include <fstream>

class SpriteGetter{
public:
	SpriteGetter();
	~SpriteGetter();
	/**
	 * @brief loads the laser texture 
	 * @return returns the laser texture from the resources folder
	 */
	sf::Texture laserTexture();
	/**
	 * @brief loads the player texture 
	 * @return returns the player texture from the resources folder
	 */
	sf::Texture playerTexture();
	/**
	 * @brief loads the spider texture 
	 * @return returns the spider texture from the resources folder
	 */
	sf::Texture spiderTexture();
	/**
	 * @brief loads the centipede segment texture 
	 * @return returns the centipede segment texture from the resources folder
	 */
	sf::Texture centipedeTexture();
	/**
	 * @brief loads the mushroom texture 
	 * @return returns the mushroom texture from the resources folder
	 */
	sf::Texture mushroomTexture();
	
private:
	sf::Texture laser_;
	sf::Texture playerTexure_;
	sf::Texture spiderTexture_;
	sf::Texture mush_;
	sf::Texture centipedeTexture_;
	
};

#endif