#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "movableObject.h"
#include <iostream>
#define screen_Width 800
#define screen_Height 600
#include <SFML/Graphics.hpp>
///
///A centipede segment is a movable object so inherit from movableObject class
///
class centipedeSegment: public movableObject
{
public:
///
///The constructor is initialize the private x and y coordinates of a centipede segment equal to the passed values.
///The constructor is also used to initialze the bulleans that govern the centige movement algorithm
///
    centipedeSegment(double xCoordinate, double yCoordinate);
	
    /**
     * @brief This fuction is used to outline the movemnt algorithm of a single centipede segment, taking into account mushroom collisions
     * @param mushroomCollision: This parameter is used to receive a messsage from the MushroomCollisionHandler class on where a 
	 * mushroom collision has been detected or not.
     */
    void moveCentipedeSegment(bool mushroomCollision);
	
	/**
	 * @brief set x coordinate of centipede segment at particular position
	 * @param x: passed variable to set the centipede segment's position
	 */
	void set_xCoordinate(double x);
	
	/**
	 * @brief set y coordinate of centipede segment at particular position
	 * @param y: passed variable to set the centipede segment's position
	 */
    void set_yCoordinate(double y);
	
	/**
	 * @brief get x coordinate of centipedeSegment
	 * @return returned parameter is the centipede's x position on the screen
	 */
    double get_xCoordinate();
    
	/**
	 * @brief get y coordinate of centipedeSegment
	 * @return returned parameter is the centipede's y position on the screen
	 */
    double get_yCoordinate();
	
	/**
	 * @brief get which boundary (left of right) the centipede is coming from
	 * @return return a boolean (true or false) stating if the screen boundary a centipede segment is coming from is the Right Boundary
	 * If true, Then the centipede segment just hit the right boundary of the screen.
	 */
	bool getRightCollideBoundary();
	
	/**
	 * @brief get which boundary (left of right) the centipede is coming from
	 * @return return a boolean (true or false) stating if the screen boundary a centipede segment is coming from is the Left Boundary
	 * If true: Then the centipede segment just hit the left boundary of the screen.
	 */
	bool getLeftCollideBoundary();
    
private:
    //A movable object should know when it is at the boundary of the screen
    bool sideBoundary;
	bool mushroomCollision;
	bool bottomOfSCreenLeft;
	bool bottomOfScreenRight;
	bool mushroomCollisionTurnAndMoveRight;
	
	bool leftMushroom;
	bool rightMushroom;
	
	sf::Sprite centipedeSegment1;
	sf::Texture centipedeTexture1;
};

#endif