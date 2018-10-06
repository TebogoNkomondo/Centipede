#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include "scoreTextfile.h"

class SplashScreen {
public:
	SplashScreen();
	~SplashScreen();
	void drawSplashScreen(sf::RenderWindow& window);
	void deadStatus(sf::RenderWindow& window);
	void winStatus(sf::RenderWindow& window);
private:
	sf::Text splashMessage;
	sf::Font font;
	sf::Text splashMessage2;
	sf::Text splashMessage3;
	ScoreTextfile score;
};

#endif