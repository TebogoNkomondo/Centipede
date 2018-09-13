#include "polyCentipede.h"

polyCentipede::polyCentipede(int lengthOfCentipede)
{
    centipedeLength= lengthOfCentipede;
    
    //declare centipedeSegments that form the centipede
    auto position=0;
    for(int i=0; i<centipedeLength; i++)
    {
        //initialize centipede segments positions
        centipedeSegment oneSegment(position,0);
        myCentipede2.push_back(oneSegment);
        position+=20;
    }
    
}