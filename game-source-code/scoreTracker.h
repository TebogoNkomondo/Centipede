#ifndef SCORETRACKER_H
#define SCORETRACKER_H
#include "scoreTextfile.h"

class ScoreTracker{
public:
	ScoreTracker();
	~ScoreTracker();
	
	void updateCurrentScore();
	void updateHighScore();
	int getCurrentScore();
	int getHighScore();
	void resetCurrentScore();
	
private:
	int currentScore = 0;
	int highScore = 0;
	ScoreTextfile scoreStorage;
};

#endif