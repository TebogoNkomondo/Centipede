#ifndef SPIDER_H
#define SPIDER_H
#include "player.h"
#include "movableObject.h"
#include <tuple>


class Spider : movableObject {
public:
	Spider();
	~Spider();
	void drawSpider(sf::RenderWindow& window);
	bool moveSpiderDown(int xMovement);
	bool moveSpiderUp(int xMovement);
	tuple<bool, int> moveSpiderRight();
	tuple<bool, int> moveSpiderLeft();
	
	void setSpiderPosition();
	void deleteSpider();
	
	sf::Sprite getSpider();
	
protected:
	sf::Texture texture_;
	sf::Sprite spider_;
private:

	int windowWidth = 800;
	int windowHeight = 600;
		bool isUpBound = false;
	bool isLowBound = false;
	bool isLeftBound = false;
	bool isRightBound = false;
	int xDirection;
	
};


#endif