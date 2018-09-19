#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H
using namespace std;

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
    movableObject();
    virtual void moveDown(Direction Down);
    virtual void moveUp(Direction Up);
    virtual void moveRight(Direction Right);
    virtual void moveLeft(Direction Left);
    
protected:
   double xPosition;
   double yPosition;
   static double moveSpeed;
};

#endif