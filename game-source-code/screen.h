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
#include "spriteGetter.h"

using namespace std;

//Thsi class will be responisble for drawing all movable objects and displaying 
//Them on the screen as the game is being played
//This class will also be used to manipulate screen objects (make some of them dissaper) 
class screen : public BulletContainer
{
public:
	/**
	*Inside the constructor, declare the object that will be drawn on the screen
	*/
	screen();
	/**
	* Pass a sprite to draw on the screen and display what the object is doing
	*/
	void draw_Centipede(int segment_Index, double x_Position, double y_Position, sf::RenderWindow& my_window);
	/**
	 * @brief draws the player onto the screen
	 * @param window: window on which player is drawn
	 */
	void drawPlayer(sf::RenderWindow& window);
	/**
	 * @brief draws the mushrooms inside of the mushroomOnTheScreen vector onto the screen
	 * @param window: window on which the mushrooms are drawn.
	 */
	void drawMushroom(sf::RenderWindow& window);
	/**
	 * @brief handles collisions between the bullet and mushrooms by making use of the collisionHandler class
	 */
	void bullet_Mushroom_Collision();
	/**
	 * @brief :get the created vector of mushrooms
	 * @return  : returns the vector storing the mushrooms in the screen 
	 */
	vector <singleMushroom> getVectorOfMushrooms();
	/**
	* @brief the vector of sprite centiede segments
	 */
	vector <sf::Sprite> centipede;
	/**
	* this is the vector storing mushrooms on the scren
	*/
	vector <sf::Sprite> mushroomsOnTheScreen;
	/**
	 * @brief draws the spider onto the screen
	 * @param window : this is the window on which the screen is drawn
	 */
	void drawSpider(sf::RenderWindow& window);
	/**
	 * @brief : this function calls the collisionHandler class so that collisions are handled
	 * functions and provides it with all required parameters.
	 * @param my_window : this is the window on which collisions are displayed
	 * @return : returns {true,false} if the player is dead(lost). returns {false,true} if the player has won(i.e. killed all centipede segments).
	 */
	tuple<bool,bool> collisions(sf::RenderWindow& my_window);
	
	//=================================================================
	/**
	 * @brief handles collisions between mushrooms and bullets using the collisionHandler class.s
	 */
	void handleMushroomCollisions(); 

private:  
	/**
	*centipedeSegment is the sprite which represents one centipede segment
	* centipedeTexture stores the centipede texture that is loaded from the spriteGetter class
	* mush_ stores the mushroom texture that is loaded from the spriteGetter class
	* mushroom_ is the sprite which represents one mushroom 
	* playyer is the player object by composition which represents the player on the screen
	* spider1 is the spider object by composition which represents the spider on the screen
	*/
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
	
	collisionHandler collissionHandle;
	bool isDead = false;
	Laser bullet1;
	std::vector<Laser>bulletLoop1;
	
	BulletContainer bulletVectorr;
	bool centipedeArrayEmpty = false;
	SpriteGetter spriteGetter_;
	

};

#endif