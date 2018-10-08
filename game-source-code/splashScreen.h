#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include "scoreTextfile.h"

class SplashScreen {
public:
	SplashScreen();
	~SplashScreen();
	/**
	 * @brief draws the initial splash screen that is to be displayed at start of game
	 * @param window : window on which screen is drawn
	 */
	void drawSplashScreen(sf::RenderWindow& window);
	/**
	 * @brief displays the screen for when a player has died(lost game)
	 * @param window : window on which splash screen is drawn
	 */
	void deadStatus(sf::RenderWindow& window);
	/**
	 * @brief displays the screen for when a player has won the game
	 * @param window :window on which splash screen is drawn
	 */
	void winStatus(sf::RenderWindow& window);
private:
	sf::Text splashMessage;
	sf::Font font;
	sf::Text splashMessage2;
	sf::Text splashMessage3;
	ScoreTextfile score;
};

#endif