#ifndef CENTIPEDE_H
#define CENTIPEDE_H

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
    
     vector <sf::Sprite> myCentipede;
     vector <bool> flag;
    
private:
    int centipedeSize;
    sf::Texture mushroomTexture;
    sf::Sprite centipedeSegment;
    //vector <sf::CircleShape> myCentipede;
    //vector <bool> flag;

};

#endif