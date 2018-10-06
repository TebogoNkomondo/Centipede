#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "movableObject.h"
#include "spriteGetter.h"

class Player : public movableObject {
public:
	Player();
	~Player();
	
	void Draw(sf::RenderWindow &window);
	//movement functions
	void handleKey();
	void MovePlayerUp();
	void MovePlayerDown();
	void MoveLeft();
	void MoveRight();
	float getXPos();
	float getYPos();
	sf::Sprite GetPlayer();
	void setPosition(sf::Vector2f newPos);
	void deletePlayer();
	
protected:
	sf::Texture real1_;
	sf::Sprite player_;
	SpriteGetter real_;
private:
	int windowWidth = 800;
	int windowHeight = 600;
	
};

#endif