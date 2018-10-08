#ifndef SCORETEXTFILE_H
#define SCORETEXTFILE_H
#include <fstream>
#include <iostream>

class ScoreTextfile{
public:
	ScoreTextfile();
	~ScoreTextfile();
	/**
	 * @brief reads the current score that is stored in the currentScore textfile.
	 * @return : returns the score stored inside of the currentScore textfile.
	 */
	int readCurrentScore();
	/**
	 * @brief writes the updated current score of the player inside of the currentScore textfile 
	 * @param scoreN : scoreN is the current score from the current game session
	 */
	void writeCurrentScore(int scoreN);
	/**
	 * @brief : reads the highest score ever recorded in game history from the highScore textfile
	 * @return : returns the high score that is in the highScore textfile
	 */
	int readHighScore();
	/**
	 * @brief sets a new high score if the current score is higher than the highest ever recorded high score.
	 * @param scoreN : this is the new high score value
	 */
	void writeHighScore(int scoreN);
	
private:
	int currentScore_ = 0;
	int highScore_ =0;
};

#endif