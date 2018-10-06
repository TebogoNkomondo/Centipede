#include "spriteGetter.h"
#include <iostream>
using namespace std;

SpriteGetter::SpriteGetter(){}

SpriteGetter::~SpriteGetter(){}

sf::Texture SpriteGetter::laserTexture(){
	if(!laser_.loadFromFile("resources/bullet.png")){
		cout<<"falied to load laser file"<<endl;
	}
	return laser_;
}

sf::Texture SpriteGetter::playerTexture(){
	if(!playerTexure_.loadFromFile("resources/purple.png")){
		cout<<"falied to load player file"<<endl;
	}
	return playerTexure_;
}

sf::Texture SpriteGetter::spiderTexture(){
	if(!spiderTexture_.loadFromFile("resources/spider.png")){
		std::cout<<"falied to load spider file"<<endl;
	}
	return spiderTexture_;
}

