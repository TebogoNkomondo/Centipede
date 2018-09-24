#ifndef PLAYER_H
#define PLAYER_H

#include "movableObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

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
	sf::Texture real_;
	sf::Sprite player_;
private:
	int windowWidth = 800;
	int windowHeight = 600;
};

#endif