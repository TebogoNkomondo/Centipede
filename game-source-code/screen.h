#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include "polyCentipede.h"
#include "player.h"
#include "bulletContainer.h"
#include "singleMushroom.h"
#include <vector>
#include "spider.h"
#include <tuple>
#include "collisionHandler.h"
//#include "mushroomCollisionHandler.h"

using namespace std;

//Thsi class will be responisble for drawing all movable objects and displaying 
//Them on the screen as the game is being played
//This class will also be used to manipulate screen objects (make some of them dissaper) 
class screen : public BulletContainer
{
public:
	//Inside the constructor, declare the object that will be drawn on the screen
	screen();
	//Pass a sprite to draw on the screen and display what the object is doing
	void draw_Centipede(int segment_Index, double x_Position, double y_Position, sf::RenderWindow& my_window);
	
	void drawPlayer(sf::RenderWindow& window);
	
	void drawMushroom(sf::RenderWindow& window);
	
	void bullet_Mushroom_Collision();
	
	//get the created vector of mushrooms
	vector <singleMushroom> getVectorOfMushrooms();
	//the vector of sprite centiede segments
	vector <sf::Sprite> centipede;
	vector <sf::Sprite> mushroomsOnTheScreen;
	
	void drawSpider(sf::RenderWindow& window);
	tuple<bool,bool> collisions(sf::RenderWindow& my_window);
	void bulletCentipede1();
	
	//=================================================================
	void handleMushroomCollisions(); 

private:  //Every that is a member of the screen calss should go here
	sf::Sprite centipedeSegment;
	sf::Texture centipedeTexture;
	sf::Texture mush_;
	sf::Sprite mushroom_;
	int numberOfRandomMushrooms;
	//Enter key flag
	bool isEnter;
	vector <singleMushroom> mushrooms;
	
	Player playyer;
	Spider spider1;
	BulletContainer bulletVectorr;
	//BulletContainer bulletT(std::vector<Laser> b);
	
	collisionHandler spiderBullet1;
	//CentipedeTrain myCentipedeTrain;
	bool mushCol =false;
	bool isDead = false;
	Laser bullet1;
	std::vector<Laser>bulletLoop1;
	
	//================================================================================
	//mushroomCollisionHandler handleMushroomCollisions;
	bool centipedeArrayEmpty = false;

};

#endif