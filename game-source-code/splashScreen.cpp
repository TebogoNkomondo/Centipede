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
	splashMessage2.setFont(font);
	splashMessage2.setCharacterSize(35);
	splashMessage2.setFillColor(sf::Color::Green);
	splashMessage3 = splashMessage2;
}

SplashScreen::~SplashScreen(){
	
}

void SplashScreen::drawSplashScreen(sf::RenderWindow& window){
	window.draw(splashMessage);
}

void SplashScreen::deadStatus(sf::RenderWindow& window){
	splashMessage.setString("YOU'VE LOST\nCurrent Score:\nHighScore:");
	splashMessage.setPosition(250,250);
	window.draw(splashMessage);
	splashMessage2.setPosition(530,300);
	splashMessage2.setString(std::to_string(score.readCurrentScore()));
	window.draw(splashMessage2);
	splashMessage3.setPosition(510,345);
	splashMessage3.setString(std::to_string(score.readHighScore()));
	window.draw(splashMessage3);
}

void SplashScreen::winStatus(sf::RenderWindow& window){
	splashMessage.setString("YOU'VE WON\nCurrent Score:\nHighScore:");
	splashMessage.setPosition(250,250);
	window.draw(splashMessage);
	splashMessage2.setPosition(530,300);
	splashMessage2.setString(std::to_string(score.readCurrentScore()));
	window.draw(splashMessage2);
	splashMessage3.setPosition(510,345);
	splashMessage3.setString(std::to_string(score.readHighScore()));
	window.draw(splashMessage3);
}

