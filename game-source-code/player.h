#ifndef Player_H
#define Player_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

class Player{
public:
	Player();
	~Player();
	
	void Draw(sf::RenderWindow &window);
	//movement functions
	void handleKey();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	
	sf::Sprite GetPlayer();
	void setPosition(sf::Vector2f newPos);
	
private:
	sf::Texture real_;
	sf::Sprite player_;
	int windowWidth = 800;
	int windowHeight = 600;
};

#endif