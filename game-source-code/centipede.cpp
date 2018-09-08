#include "centipede.h"

centipede::centipede(int sizeOfCentipede)
{
    //set the centipede sprite
    if(!mushroomTexture.loadFromFile("resources/soccerBall.png"))
    {
        cout<< "Load texture failed"<<endl;
    }
    centipedeSegment.setTexture(mushroomTexture);
    centipedeSegment.setScale(sf::Vector2f(0.12,0.12));
    
    centipedeSize= sizeOfCentipede;
    
    int position=0;
    for(int i=0; i<centipedeSize; i++)
    {
        flag.push_back(true);
        myCentipede.push_back(centipedeSegment);
        myCentipede.at(i).setPosition(position, 0);
        position+=25;
    }
}

int centipede::getCentipedesize()
{
    return centipedeSize;
}

void centipede::moveCentipedeRight(int centipedeSegment)
{
    //Move the centipede to the right
            if(myCentipede.at(centipedeSegment).getPosition().x <800 && flag.at(centipedeSegment) )
            {
                myCentipede.at(centipedeSegment).move(4, 0.0f );
            }
}

void centipede::moveCentipedeDown(int centipedeSegment)
{
    if(myCentipede.at(centipedeSegment).getPosition().x > 760 && flag.at(centipedeSegment))
            {
                for(int j=0; j<50; j++)
                {
                    myCentipede.at(centipedeSegment).move(0.0f, 0.4f );
                }
                flag.at(centipedeSegment)= false;
            }
}

void centipede::moveCentipedeLeft(int centipedeSegment)
{
    if(!flag.at(centipedeSegment))
            {
                myCentipede.at(centipedeSegment).move(-4, 0.0f );
            }
}

void centipede::moveCentipedeUP(int centipedeSegment)
{
    if(myCentipede.at(centipedeSegment).getPosition().x < 0 && !flag.at(centipedeSegment))
            {
                for(int t=0; t<50; t++)
                {
                    myCentipede.at(centipedeSegment).move (0.0f, 0.4f );
                }
                flag.at(centipedeSegment)= true;
            }
}