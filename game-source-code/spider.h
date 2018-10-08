#ifndef SPIDER_H
#define SPIDER_H
#include "player.h"
#include "movableObject.h"
#include "spriteGetter.h"
#include <tuple>


class Spider {
public:
	/**
	 * spider texture is fecthed from spriteGetter class
	 * spider sprite dimensions are set in the constructor
	 */
	Spider();
	~Spider();
	/**
	 * @brief draws the spider sprite onto the screen
	 * @param window: window where spider is to be drawn
	 */
	void drawSpider(sf::RenderWindow& window);
	/**
	 * @brief this functions is responsible for downward movement of the spider.
	 * @param xMovement parameter to tell the spider to move either right or left depending on current direction of movement
	 * @return return true if lower boundary is hit, false if not
	 */
	bool moveSpiderDown(int xMovement);
	/**
	 * @brief this functions is responsible for upward movement of the spider.
	 * @param xMovement parameter to tell the spider to move either right or left depending on current direction of movement
	 * @return return true if upper boundary is hit, false if not
	 */
	bool moveSpiderUp(int xMovement);
	/**
	 * @brief moves the spider to the right
	 * @return : returns true and -2(for movement to the left) if spider hits the right boundary
	 * else it return false if spider false and 2(for continue moving right) if spider is not at right boundary
	 */
	tuple<bool, int> moveSpiderRight();
	/**
	 * @brief moves the spider to the left
	 * @return : returns true and 2(for movement to the right) if spider hits the left boundary
	 * else it return false if spider false and -2(for continue moving left) if spider is not at left boundary
	 */
	tuple<bool, int> moveSpiderLeft();
	/**
	 * @brief sets spider sprite at position (x,y)
	 * @param x : x co-ordinate of spider
	 * @param y : y co-ordinate of spider
	 */
	void setSpiderPosition(float x, float y);
	/**
	 * @brief sets the spider sprite's scale to (0,0), thus deleting spider from screen
	 */
	void deleteSpider();
	/**
	 * @brief regenerates the spider (sets the spider scale back to (0.12,0.07)) after every time counter reaches 500,
	 * hence making spider appear periodically
	 */
	void regenerateSpider();
	/**
	 * @brief returns spider sprite properties to be used for collisions later
	 * @return : returns spider sprite
	 */
	sf::Sprite getSpider();
	
protected:
	/**
	*texture_ stores spider texture loaded from spriteGetter
	* spider_ is the spider sprite
	*/
	sf::Texture texture_;
	sf::Sprite spider_;
private:
	/**
	*spiderTexture_ is the object by composition that is to be used for loading spider texture from spriteGetter
	* screen boundaries are set and player movement area boundary detectors are set (isUpBound,isLowBound,isLeftBound, and isRightBound)
	* xDirection is the current horizontal direction of the spider
	*/
	SpriteGetter spiderTexture_;
	int windowWidth = 800;
	int windowHeight = 600;
	bool isUpBound = false;
	bool isLowBound = false;
	bool isLeftBound = false;
	bool isRightBound = false;
	int xDirection;
	int period = 0;
};


#endif