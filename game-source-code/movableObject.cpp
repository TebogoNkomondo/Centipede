#include "movableObject.h"
//Decalare the moving speed;
double movableObject::moveSpeed(5);

movableObject::movableObject()
{
     //there's nothing to do
}

void movableObject::moveRight(Direction Right)
{
    //To move an object to the right, just change its x position
    xPosition+=moveSpeed;
}

void movableObject::moveLeft(Direction Left)
{
    //To move an object to the left, just change the x postion
    xPosition+= -moveSpeed;
}

void movableObject::moveDown(Direction Down)
{
    //Just chnge the y position
    yPosition+= moveSpeed;
}

void movableObject::moveUp(Direction Up)
{
    //Just change y position
    yPosition+= -moveSpeed;
}

