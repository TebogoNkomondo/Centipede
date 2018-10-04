#include "splashScreen.h"
#include <iostream>
using namespace std;

SplashScreen::SplashScreen(){
	if(!font.loadFromFile("resources/sansation.ttf"))
	cout<< "Error loading sansation.ttf from resources- sf font"<<endl;
	
    splashMessage.setFont(font);
    splashMessage.setCharacterSize(40);
    splashMessage.setPosition(105, 70);
    splashMessage.setFillColor(sf::Color::Green);
    splashMessage.setString("Welcome to the Centipede Game!\n\nInstructions:"
	"\nPress Space bar to shoot\nPress Right to move Right:"
	"\nPress Left to move Left\nPress Down to move Down\nPress Up to move UP\n\nPress Enter to start the Game!!");
	auto splash_Message= splashMessage;
}

SplashScreen::~SplashScreen(){
	
}

void SplashScreen::drawSplashScreen(sf::RenderWindow& window){
	window.draw(splashMessage);
}

void SplashScreen::deadStatus(sf::RenderWindow& window){
	splashMessage.setString("YOU'VE LOST");
	splashMessage.setPosition(250,250);
	window.draw(splashMessage);
}

void SplashScreen::winStatus(sf::RenderWindow& window){
	splashMessage.setString("YOU'VE WON");
	splashMessage.setPosition(250,250);
	window.draw(splashMessage);
}
