#include "scoreTextfile.h"
using namespace std;

ScoreTextfile::ScoreTextfile(){
	writeCurrentScore(0);
}
ScoreTextfile::~ScoreTextfile(){}

int ScoreTextfile::readCurrentScore(){
	ifstream inFile;
	inFile.open("resources/currentScore.txt");
	if(inFile.fail()){
		cout<<"current score file does not exist"<<endl;
	}
	inFile >> currentScore_;
	
	inFile.close();
	return currentScore_;
}

void ScoreTextfile::writeCurrentScore(int scoreN){
	ofstream outFile;
	outFile.open("resources/currentScore.txt");
	outFile << scoreN;
	outFile.close();
}

int ScoreTextfile::readHighScore(){
	ifstream inFile;
	inFile.open("resources/highScore.txt");
	if(inFile.fail()){
		cout<<"High score file does not exist"<<endl;
	}
	inFile >> highScore_;
	
	inFile.close();
	return highScore_;
}

void ScoreTextfile::writeHighScore(int scoreN){
	ofstream outFile;
	outFile.open("resources/highScore.txt");
	outFile << scoreN;
	outFile.close();
}

