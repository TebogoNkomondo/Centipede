#ifndef SCORETRACKER_H
#define SCORETRACKER_H
#include "scoreTextfile.h"

class ScoreTracker{
public:
	ScoreTracker();
	~ScoreTracker();
	/**
	 * @brief updates the current score as the game progresses
	 */
	void updateCurrentScore();
	/**
	 * @brief updates the high score if the current score beats the previous high score
	 */
	void updateHighScore();
	/**
	 * @brief returns the current score from the currentScore textfile
	 * @return : returns value stored in currentScore textfile
	 */
	int getCurrentScore();
	/**
	 * @brief returns the high score stored in the highScore textfile
	 * @return : returns the value stored in the highScore textfile
	 */
	int getHighScore();
	/**
	 * @brief resets the current score backt to zero at the start of a new game session.
	 */
	void resetCurrentScore();
	
private:
	int currentScore = 0;
	int highScore = 0;
	/**
	*By composition the scoreStorage object is used to call scoreTextfile class so that it can read values stored in currentScore 
	* and highScore textfiles.
	*/
	ScoreTextfile scoreStorage;
};

#endif