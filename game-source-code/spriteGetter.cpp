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

sf::Texture SpriteGetter::centipedeTexture(){
    if(!centipedeTexture_.loadFromFile("resources/soccerBall.png"))
    {
        cout<< "Load centipede texture failed"<<endl;
    }
	return centipedeTexture_;
}

sf::Texture SpriteGetter::mushroomTexture(){
	if(!mush_.loadFromFile("resources/mushroom.png")){
		cout<<"falied to load mushroom file"<<endl;
	}
	return mush_;
}