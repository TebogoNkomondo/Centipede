#include "centipede.h"

centipede::centipede(int sizeOfCentipede)
{
    //set the centipede sprite
    if(!mushroomTexture.loadFromFile("frame-6.png"))
    {
        cout<< "Load texture failed"<<endl;
    }
    centipedeSegment.setTexture(mushroomTexture);
    centipedeSegment.setScale(sf::Vector2f(0.1,0.1));
    
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
    if(myCentipede.at(centipedeSegment).getPosition().x > 800 && flag.at(centipedeSegment))
            {
                for(int j=0; j<100; j++)
                {
                    myCentipede.at(centipedeSegment).move(0.0f, 0.3f );
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
                for(int t=0; t<100; t++)
                {
                    myCentipede.at(centipedeSegment).move (0.0f, 0.3f );
                }
                flag.at(centipedeSegment)= true;
            }
}

//void centipede::moveCentipede()
//{
//    for(int i=0; i<centipedeSize; i++)
//        {
//            //Move the centipede to the right
//            if(myCentipede.at(i).getPosition().x <800 && flag.at(i) )
//            {
//                myCentipede.at(i).move(0.1f, 0.0f );
//            }
//            if(myCentipede.at(i).getPosition().x > 800 && flag.at(i))
//            {
//                for(int j=0; j<100; j++)
//                {
//                    myCentipede.at(i).move(0.0f, 0.1f );
//                }
//                flag.at(i)= false;
//            }
//           if(!flag.at(i))
//            {
//                myCentipede.at(i).move(-0.1f, 0.0f );
//            }
//            if(myCentipede.at(i).getPosition().x < 0 && !flag.at(i))
//            {
//                for(int t=0; t<100; t++)
//                {
//                    myCentipede.at(i).move (0.0f, 0.1f );
//                }
//                flag.at(i)= true;
//            }
//            
//            window.draw(myCentipede.at(i));
//        }
//}