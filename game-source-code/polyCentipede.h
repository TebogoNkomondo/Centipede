#ifndef POLYCENTIPEDE_H
#define POLYCENTIPEDE_H

#include "centipedeSegment.h"
#include <vector>
///
///A centipede train must know its length
///
#define length_of_centipede 12

//A poly centipede is a centipede train
class polyCentipede
{
public:
///
///The constructor inializes the vectoe size of centipede segments to be equal to passed parameter value: lengthOfCentipede
//
    polyCentipede(int lengthOfCentipede);
///
///Create a vector of centipede objects 
///
    vector<centipedeSegment> myCentipede2;
    
private:
    int centipedeLength;
};

#endif