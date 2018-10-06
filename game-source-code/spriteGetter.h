#ifndef SPRITEGETTER_H
#define SPRITEGETTER_H
#include <SFML/Graphics.hpp>
#include <fstream>

class SpriteGetter{
public:
	SpriteGetter();
	~SpriteGetter();
	
	sf::Texture laserTexture();
	
	sf::Texture playerTexture();
	
	sf::Texture spiderTexture();
	
	sf::Texture centipedeTexture();
	
	sf::Texture mushroomTexture();
	
private:
	sf::Texture laser_;
	sf::Texture playerTexure_;
	sf::Texture spiderTexture_;
	sf::Texture mush_;
	sf::Texture centipedeTexture_;
	
};

#endif