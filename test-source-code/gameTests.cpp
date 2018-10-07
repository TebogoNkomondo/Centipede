#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/player.h"
#include "../game-source-code/screen.h"
#include "../game-source-code/laser.h"
#include "../game-source-code/spider.h"
#include "../game-source-code/polycentipede.h"
#include "../game-source-code/collisionHandler.h"
#include "../game-source-code/scoreTracker.h"
#include "../game-source-code/scoreTextfile.h"
#include "../game-source-code/bulletContainer.h"
#include "../game-source-code/spriteGetter.h"
#include "../game-source-code/mushroomCollisionHandler.h"


using namespace std;
using namespace sf;


//===================================================================Players test code=======================================================
TEST_CASE("Check that player x scale is 0.35")
{
    Player playy;
    CHECK(playy.GetPlayer().getScale().x == 0.35f);
}

TEST_CASE("Check that player y scale is 0.35")
{
    Player playyer;
    CHECK(playyer.GetPlayer().getScale().y == 0.35f);
}

TEST_CASE("Check if player position is set")
{
    Player player1;
	vector<sf::Vector2f> pos;
	player1.setPosition(sf::Vector2f(float(400),float(400.0f)));
	
    CHECK(player1.GetPlayer().getPosition() == sf::Vector2f(400.0f,400.0f));
}

TEST_CASE("Check for right movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,400));
	player2.MoveRight();
    CHECK(player2.GetPlayer().getPosition().x == 405);
}

TEST_CASE("Check for left movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,400));
	player2.MoveLeft();
    CHECK(player2.GetPlayer().getPosition().x == 395);
}

TEST_CASE("Check for up movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,570));
	player2.MovePlayerUp();
    CHECK(player2.GetPlayer().getPosition().y == 565);
}

TEST_CASE("Check for down movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,565));
	player2.MovePlayerDown();
    CHECK(player2.GetPlayer().getPosition().y == 570);
}

//TESTS FOR LASER
TEST_CASE("Check x scale of laser"){
	Laser laser1;
	CHECK(laser1.getBullet().getScale().x== 0.2f);
}

TEST_CASE("Check y scale of laser"){
	Laser laser2;
	CHECK(laser2.getBullet().getScale().y== 0.2f);
}

TEST_CASE("Check laser movement up"){
	Laser laser1;
	laser1.setPosition(300,300);
	laser1.Shoot();
	CHECK(laser1.getBullet().getPosition().y == 290);
}


//TESTS FOR SPIDER
TEST_CASE("Check x scale of SPIDER"){
	Spider spider1;
	CHECK(spider1.getSpider().getScale().x== 0.12f);  		//bullet only moves up
}

TEST_CASE("Check y scale of SPIDER"){
	Spider spider2;
	CHECK(spider2.getSpider().getScale().y== 0.07f);
}

TEST_CASE("Check SPIDER movement up"){
	Spider spider3;
	spider3.setSpiderPosition(300,570);
	spider3.moveSpiderUp(0);
	CHECK(spider3.getSpider().getPosition().y == 568);
}

TEST_CASE("Check SPIDER movement up"){
	Spider spider4;
	spider4.setSpiderPosition(300,570);
	spider4.moveSpiderDown(0);
	CHECK(spider4.getSpider().getPosition().y == 572);
}

TEST_CASE("Check spider movement to the right"){
	Spider spider5;
	spider5.setSpiderPosition(300,570);
	spider5.moveSpiderDown(2);			///we have to test using the down function
	CHECK(spider5.getSpider().getPosition().x == 302);
}

TEST_CASE("Check spider movement to the left"){
	Spider spider6;
	spider6.setSpiderPosition(300,570);
	spider6.moveSpiderDown(-2);			///we have to test using the down function
	CHECK(spider6.getSpider().getPosition().x == 298);
}

//==============================player spider collission tests=====================================
TEST_CASE("Check if spider-player collision leads to spider death in x"){
	Spider spider7;
	Player player7;
	collisionHandler collisionHandle;
	spider7.setSpiderPosition(400,520);
	player7.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider7,player7);
	CHECK(spider7.getSpider().getScale().x == 0);
}

TEST_CASE("Check if spider-player collision leads to spider death in y"){
	Spider spider8;
	Player player8;
	collisionHandler collisionHandle;
	spider8.setSpiderPosition(400,520);
	player8.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider8,player8);
	CHECK(spider8.getSpider().getScale().y == 0);
}

TEST_CASE("Check if spider does not die if no collision occurs for x scale"){
	Spider spider8;
	Player player8;
	collisionHandler collisionHandle;
	spider8.setSpiderPosition(600,520);
	player8.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider8,player8);
	CHECK(spider8.getSpider().getScale().x == 0.12f);
}

TEST_CASE("Check if spider does not die if no collision occurs for y scale"){
	Spider spider8;
	Player player8;
	collisionHandler collisionHandle;
	spider8.setSpiderPosition(600,520);
	player8.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider8,player8);
	CHECK(spider8.getSpider().getScale().y == 0.07f);
}


TEST_CASE("Check if spider-player collision leads to player death in x"){
	Spider spider9;
	Player player9;
	collisionHandler collisionHandle;
	spider9.setSpiderPosition(400,520);
	player9.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider9, player9);
	CHECK(player9.GetPlayer().getScale().x == 0);
}

TEST_CASE("Check if spider-player collision leads to player death in y"){
	Spider spider10;
	Player player10;
	collisionHandler collisionHandle;
	spider10.setSpiderPosition(400,520);
	player10.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider10,player10);
	CHECK(player10.GetPlayer().getScale().y == 0);
}


TEST_CASE("Check if player does not die if there is no collision for x scale"){
	Spider spider10;
	Player player10;
	collisionHandler collisionHandle;
	spider10.setSpiderPosition(600,520);
	player10.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider10,player10);
	CHECK(player10.GetPlayer().getScale().x == 0.35f);
}

TEST_CASE("Check if player does not die if there is no collision for y scale"){
	Spider spider10;
	Player player10;
	collisionHandler collisionHandle;
	spider10.setSpiderPosition(600,520);
	player10.setPosition(sf::Vector2f(400,520));
	collisionHandle.playerSpider(spider10,player10);
	CHECK(player10.GetPlayer().getScale().y == 0.35f);
}

//===================================bullet spider collision tests============================================================
TEST_CASE("Check if spider-bullet collision leads to spider death for x scale"){
	Spider spider11;
	Laser laser1;
	Laser laser2;
	collisionHandler collisionHandle1;
	spider11.setSpiderPosition(300,300);
	laser1.setPosition(300,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	collisionHandle1.bulletSpider(spider11, bulletVector);
	CHECK(spider11.getSpider().getScale().x == 0);
}

TEST_CASE("Check if spider-bullet collision leads to spider death for y scale"){
	Spider spider11;
	Laser laser1;
	Laser laser2;
	collisionHandler collisionHandle1;
	spider11.setSpiderPosition(300,300);
	laser1.setPosition(300,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	collisionHandle1.bulletSpider(spider11, bulletVector);
	CHECK(spider11.getSpider().getScale().y == 0);
}

TEST_CASE("Check if that spider does not die if no collision occurs for y scale"){
	Spider spider11;
	Laser laser1;
	Laser laser2;
	collisionHandler collisionHandle1;
	spider11.setSpiderPosition(500,500);
	laser1.setPosition(300,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	collisionHandle1.bulletSpider(spider11, bulletVector);
	CHECK(spider11.getSpider().getScale().y == 0.07f);
}

TEST_CASE("Check if that spider does not die if no collision occurs for x scale"){
	Spider spider11;
	Laser laser1;
	Laser laser2;
	collisionHandler collisionHandle1;
	spider11.setSpiderPosition(500,500);
	laser1.setPosition(300,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	collisionHandle1.bulletSpider(spider11, bulletVector);
	CHECK(spider11.getSpider().getScale().x == 0.12f);
}

//=========================================================Player-centipede collision tests=============================================
TEST_CASE("Check that player-centipede collision is detected"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	Player player2;
	collisionHandler collisionHandle2;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment1.setPosition(300,300);
	centipedeSegment.setPosition(400,400);
	player2.setPosition(sf::Vector2f(300,300));
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	auto isCollision = collisionHandle2.playerCentipede(player2,centipede);
	CHECK(isCollision == true);
}

TEST_CASE("Check that no collision is detected between player and centipede when no collision occurs"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	Player player2;
	collisionHandler collisionHandle2;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment1.setPosition(500,300);
	centipedeSegment.setPosition(400,400);
	player2.setPosition(sf::Vector2f(300,300));
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	auto isCollision = collisionHandle2.playerCentipede(player2,centipede);
	CHECK(isCollision == false);
}

TEST_CASE("Check that player dies upon collision with centipede for x scale"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	Player player2;
	collisionHandler collisionHandle2;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment1.setPosition(300,300);
	centipedeSegment.setPosition(400,400);
	player2.setPosition(sf::Vector2f(300,300));
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	collisionHandle2.playerCentipede(player2,centipede);
	CHECK(player2.GetPlayer().getScale().x == 0);
}

TEST_CASE("Check that player dies upon collision with centipede for y scale"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	Player player2;
	collisionHandler collisionHandle2;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment1.setPosition(300,300);
	centipedeSegment.setPosition(400,400);
	player2.setPosition(sf::Vector2f(300,300));
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	collisionHandle2.playerCentipede(player2,centipede);
	CHECK(player2.GetPlayer().getScale().y == 0);
}

//=========================================================Centipede-bullet collision tests==============================================
TEST_CASE("Check that centipede segment gets killed after being hit by bullet for x scale"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment.setPosition(300,300);
	centipedeSegment1.setPosition(400,400);
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	
	Laser laser1;
	Laser laser2;
	laser1.setPosition(300,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	
	collisionHandler collisionHandle;
	collisionHandle.bulletCentipede(bulletVector,centipede);
	
	CHECK(centipede.at(0).getScale().x == 0);
}

TEST_CASE("Check that centipede segment gets killed after being hit by bullet for y scale"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment.setPosition(300,300);
	centipedeSegment1.setPosition(400,400);
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	
	Laser laser1;
	Laser laser2;
	laser1.setPosition(300,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	
	collisionHandler collisionHandle;
	collisionHandle.bulletCentipede(bulletVector,centipede);
	
	CHECK(centipede.at(0).getScale().y == 0);
}

TEST_CASE("Check that centipede segment that hasn't been hit by bullet does not die"){
	vector <sf::Sprite> centipede;
	sf::Sprite centipedeSegment;
	SpriteGetter spriteGetter_;
	auto centipedeTexture = spriteGetter_.centipedeTexture();
    centipedeSegment.setTexture(centipedeTexture);
    centipedeSegment.setScale(sf::Vector2f(0.14,0.14));
	sf::Sprite centipedeSegment1 = centipedeSegment;
	centipedeSegment.setPosition(300,300);
	centipedeSegment1.setPosition(400,400);
	centipede.push_back(centipedeSegment);
	centipede.push_back(centipedeSegment1);
	
	Laser laser1;
	Laser laser2;
	laser1.setPosition(500,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	
	collisionHandler collisionHandle;
	collisionHandle.bulletCentipede(bulletVector,centipede);
	
	CHECK(centipede.at(0).getScale() == sf::Vector2f(0.14f,0.14f));
}
//=========================================================Mushroom-bullet collision tests=============================================
TEST_CASE("Check that mushroom that has been hit by bullet dies"){
	vector <sf::Sprite> mushroomsOnTheScreen;
	SpriteGetter spriteGetter_;
	sf::Texture mush_;
	sf::Sprite mushroom_;
	sf::Sprite mushroom_1;
	mush_ = spriteGetter_.mushroomTexture();
	mushroom_.setTexture(mush_);
	mushroom_.setScale(sf::Vector2f(0.2,0.2));
	mushroom_1 = mushroom_;
	mushroom_.setPosition(500,300);
	mushroom_1.setPosition(700,500);
	
	mushroomsOnTheScreen.push_back(mushroom_);
	mushroomsOnTheScreen.push_back(mushroom_1);
	Laser laser1;
	Laser laser2;
	laser1.setPosition(500,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	
	collisionHandler collisionHandle;
	collisionHandle.bullet_Mushroom_Collision(bulletVector,mushroomsOnTheScreen);
	CHECK(mushroomsOnTheScreen.at(0).getScale() == sf::Vector2f(0,0));
}


TEST_CASE("Check that mushroom that has not been hit by bullet does not die"){
	vector <sf::Sprite> mushroomsOnTheScreen;
	SpriteGetter spriteGetter_;
	sf::Texture mush_;
	sf::Sprite mushroom_;
	sf::Sprite mushroom_1;
	mush_ = spriteGetter_.mushroomTexture();
	mushroom_.setTexture(mush_);
	mushroom_.setScale(sf::Vector2f(0.2,0.2));
	mushroom_1 = mushroom_;
	mushroom_.setPosition(500,300);
	mushroom_1.setPosition(700,500);
	
	mushroomsOnTheScreen.push_back(mushroom_);
	mushroomsOnTheScreen.push_back(mushroom_1);
	Laser laser1;
	Laser laser2;
	laser1.setPosition(500,300);
	laser2.setPosition(400,400);
	std::vector<Laser> bulletVector;
	bulletVector.push_back(laser1);
	bulletVector.push_back(laser2);
	
	collisionHandler collisionHandle;
	collisionHandle.bullet_Mushroom_Collision(bulletVector,mushroomsOnTheScreen);
	CHECK(mushroomsOnTheScreen.at(1).getScale() == sf::Vector2f(0.2f,0.2f));
}
//============================================================Poly Centipede Tests=========================================================
TEST_CASE("Check that a centipede segment moves to the right by the moveSpeed (5) ")
{
	//    //Check that the centipede succesfully moves to the right
//    //Check this for only one segment of the centipede.
//    
	polyCentipede centipedeTrain(1);
    centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
    CHECK(centipedeTrain.myCentipede2.at(0).get_xCoordinate() == 5);
}

TEST_CASE("Check that a centipede segment moves to the down by the moveSpeed (5)* 3")
{
	polyCentipede centipedeTrain(1);
    //we cannot set the centipede to be at the boundary
	//We hence need to allow it to move
	//the centipede segment will move down the x coordinate is equal to screen_width -15;
	do{
		centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
	}while(centipedeTrain.myCentipede2.at(0).get_xCoordinate() != screen_Width -15);
	
    centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
    CHECK(centipedeTrain.myCentipede2.at(0).get_yCoordinate() == 15 );
}

TEST_CASE("Check that the centipede moves to the left")
{
    //Check that the centipede succesfully moves to the left
    //Check this for only one segment of the centipede.
	//moving left is directly subsequent moving down. 
	
	 polyCentipede centipedeTrain(1);
	
	do{
		centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
	}while(centipedeTrain.myCentipede2.at(0).get_xCoordinate() != screen_Width -15);
	
	//after we have hid the boundary, move the centipede twice
    centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
	centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
	
	CHECK(centipedeTrain.myCentipede2.at(0).get_xCoordinate() == screen_Width - (15 +5));
}

TEST_CASE("Check a centipede segment's position never exceeds the screen width")
{
	//We are loking to the test that the centipede segment never moves out of the side boundary of the screen
   polyCentipede centipedeTrain(1);
   
   //to do this, we let the centipede move for a number of times equal to the screen_width- then test the position of the x coordinate
   //we already know that this centipede will be moving by a factor of 5
   for(int i= 0; i< screen_Width; i++)
   {
	   centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
   }
   CHECK(centipedeTrain.myCentipede2.at(0).get_xCoordinate() < screen_Width);
   
   CHECK(centipedeTrain.myCentipede2.at(0).get_xCoordinate() > 0);
}

TEST_CASE ("Check that a centipede goes up after hitting bottom walls of the screen")
{
	//We are loking to the test that the centipede segment goes up when it hits the bootom screen boundary
	//perform tests for one centipede centipede segment 
   polyCentipede centipedeTrain(1);
   
   //we need to place this centipede segment at the bootom screen boudary
   centipedeTrain.myCentipede2.at(0).set_xCoordinate(-1.0);
   centipedeTrain.myCentipede2.at(0).set_yCoordinate(screen_Height-10.0);
   centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
   
   //After moving the posistion of this segment must have a y coordinate
   CHECK(centipedeTrain.myCentipede2.at(0).get_yCoordinate() == 590.0);
   
   //Do the same for the other side:
   centipedeTrain.myCentipede2.at(0).set_xCoordinate(screen_Width-15);
   centipedeTrain.myCentipede2.at(0).set_yCoordinate(screen_Height-10.0);
   
    CHECK(centipedeTrain.myCentipede2.at(0).get_yCoordinate() == 590.0);
}

//======================================================Mushroom and centipede Collisions=====================================================================================
TEST_CASE ("Check that a centipede and mushroom collision is detected")
{
	//we must first declare a centipede train
	polyCentipede centipedeTrain(1);
	//We also need to pass a screen object;
	screen my_screen;
	mushroomCollisionHandler handleMushroomCollisions;
	
	//Get the vector of mushrooms that was initialized
	my_screen.getVectorOfMushrooms();
	
	//keep moving the centipede segment until it hits a mushroom particle
	do{
		 centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
	}while(!handleMushroomCollisions.isCollision(centipedeTrain, my_screen,0));
	
	//This loop will stop when isCollison returns a true
	CHECK(handleMushroomCollisions.isCollision(centipedeTrain, my_screen,0) == true);
}

TEST_CASE ("After a collision has been detected, check that all centipede segments move down")
{
	polyCentipede centipedeTrain(1);
	screen my_screen;
	mushroomCollisionHandler handleMushroomCollisions;
	
	my_screen.getVectorOfMushrooms();
	auto yBeforeCollision= centipedeTrain.myCentipede2.at(0).get_yCoordinate();
	bool isCollision;
	
	//keep moving the centipede segment until it hits a mushroom particle
	do{
		 centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
		 yBeforeCollision= centipedeTrain.myCentipede2.at(0).get_yCoordinate();
		 isCollision= handleMushroomCollisions.isCollision(centipedeTrain, my_screen,0);
	}while(!handleMushroomCollisions.isCollision(centipedeTrain, my_screen,0));
	
	//After a collsion has been detected, we must now ensure that the segment's y coordinate has increased;
	centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(isCollision);
	auto yAfterCollison= centipedeTrain.myCentipede2.at(0).get_yCoordinate();

	CHECK(yAfterCollison == yBeforeCollision + 15);
}

TEST_CASE ("Check that a centipede segment reverse direction after colliding a mushroom")
{
	polyCentipede centipedeTrain(1);
	screen my_screen;
	mushroomCollisionHandler handleMushroomCollisions;
	
	my_screen.getVectorOfMushrooms();
	bool isCollision;
	
	auto xBeforeCollison= centipedeTrain.myCentipede2.at(0).get_xCoordinate();
	//keep moving the centipede segment until it hits a mushroom particle
	do{
		 centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(false);
		 xBeforeCollison= centipedeTrain.myCentipede2.at(0).get_xCoordinate();
		 isCollision= handleMushroomCollisions.isCollision(centipedeTrain, my_screen,0);
	}while(!handleMushroomCollisions.isCollision(centipedeTrain, my_screen,0));
	
	centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(isCollision); 
	//centipedeTrain.myCentipede2.at(0).moveCentipedeSegment(isCollision); 
	
	auto xAfterCollison= centipedeTrain.myCentipede2.at(0).get_xCoordinate();
	
	//One of these check will pass and the other will fail. This is because we cannot be certain of which direction the centipede
	//is colliding with mushroom from.
	
	if(centipedeTrain.myCentipede2.at(0).getRightCollideBoundary())
		CHECK(xAfterCollison == xBeforeCollison -5);
	
	else{
	CHECK (xAfterCollison == xBeforeCollison + 5 );
	}
}


