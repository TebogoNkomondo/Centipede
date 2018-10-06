#include "scoreTracker.h"
#include <iostream>
using namespace std;

ScoreTracker::ScoreTracker(){
	highScore = scoreStorage.readHighScore();
	currentScore = 0;
}

ScoreTracker::~ScoreTracker(){}

void ScoreTracker::updateCurrentScore(){
	currentScore++;
	scoreStorage.writeCurrentScore(currentScore);
}

void ScoreTracker::updateHighScore(){
	if(currentScore > highScore){
		highScore = currentScore;
		scoreStorage.writeHighScore(highScore);
	}
	else{
		highScore = highScore;
	}
}

int ScoreTracker::getCurrentScore(){
	return currentScore;
}

int ScoreTracker::getHighScore(){
	return highScore;
}

void ScoreTracker::resetCurrentScore(){
	currentScore = 0;
}