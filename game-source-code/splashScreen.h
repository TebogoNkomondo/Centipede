#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>

class SplashScreen{
public:
	SplashScreen();
	~SplashScreen();
	void drawSplashScreen(sf::RenderWindow& window);
private:
	sf::Text splashMessage;
	sf::Font font;
};

#endif