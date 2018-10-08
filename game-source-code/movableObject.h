#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H
using namespace std;

///
///This strongly typed enum will be used to assist in telling a game object which direction it must move.
///
enum class Direction
{
    Right,
    Left,
    Up,
    Down,
};

class movableObject
{
public:
	//The constructor of this class does nothing
    movableObject();
	/**
	 * @brief This constructor does nothing
	 * @param Down : the parameter is passed to indicate that the moveable object must move Down
	 */
    virtual void moveDown(Direction Down);
	/**
	 * @brief 
	 * @param Up : the parameter is passed to indicate that the moveable object must move Up
	 */
    virtual void moveUp(Direction Up);
	/**
	 * @brief 
	 * @param Right :this parameter is passed to indicate that the moveable object must move Right
	 */
    virtual void moveRight(Direction Right);
	/**
	 * @brief 
	 * @param Left : this parameter is passed to indicate that the moveable object must move Left
	 */
    virtual void moveLeft(Direction Left);
    
protected:
   double xPosition;
   double yPosition;
   static double moveSpeed;
};

#endif