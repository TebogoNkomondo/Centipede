#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class centipede
{
public:
    centipede(int sizeOfCentipede);
    //move the centipede
    void moveCentipedeRight(int centipedeSegment);
    void moveCentipedeLeft(int centipedeSegment);
    void moveCentipedeDown(int centipedeSegment);
    void moveCentipedeUP(int centipedeSegment);
    
    int getCentipedesize();
    
     vector <sf::CircleShape> myCentipede;
     vector <bool> flag;
    
private:
    int centipedeSize;
    //vector <sf::CircleShape> myCentipede;
    //vector <bool> flag;

};
