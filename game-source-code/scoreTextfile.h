#ifndef SCORETEXTFILE_H
#define SCORETEXTFILE_H
#include <fstream>
#include <iostream>

class ScoreTextfile{
public:
	ScoreTextfile();
	~ScoreTextfile();
	int readCurrentScore();
	void writeCurrentScore(int scoreN);
	
	int readHighScore();
	void writeHighScore(int scoreN);
	
private:
	int currentScore_ = 0;
	int highScore_ =0;
};

#endif