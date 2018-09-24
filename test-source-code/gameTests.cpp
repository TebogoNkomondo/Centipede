#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/player.h"
#include "../game-source-code/centipede.h"
#include "../game-source-code/screen.h"
#include "../game-source-code/laser.h"
#include "../game-source-code/spider.h"
#include "../game-source-code/polycentipede.h"
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


//============================================================Poly Centipede Tests=========================================================

TEST_CASE("Check that a centipede segment moves to the right by the moveSpeed (5) ")
{
//    //Check that the centipede succesfully moves to the right
//    //Check this for only one segment of the centipede.
//    
	centipedeSegment centipede1(0,0);
	centipede1.moveCentipedeSegment(false);
	//polyCentipede centipedeTrain(1);
    //centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
    CHECK(centipede1.get_xCoordinate() == 5);
}

TEST_CASE("Check that a centipede segment moves to the down by the moveSpeed (5) ")
{
//    //Check that the centipede succesfully moves to the down
//    //Check this for only one segment of the centipede.
//    
	centipedeSegment centipede1(756,0);
	centipede1.moveCentipedeSegment(true);
    CHECK(centipede1.get_yCoordinate() == 15);
}

TEST_CASE("Check that a centipede segment moves to the left by the moveSpeed (5) ")
{
//    //Check that the centipede succesfully moves to the down
//    //Check this for only one segment of the centipede.
//    
	centipedeSegment centipede1(800,0);
	centipede1.moveCentipedeSegment(false);
    CHECK(centipede1.get_xCoordinate() == 795);
}

/*
TEST_CASE("Check that a centipede segment moves to the down by the moveSpeed (5)* 3")
{
    //Check that the centipede succesfully moves down
    //Check this for only one segment of the centipede.
    
    polyCentipede centipedeTrain(1);
    //we cannot set the centipede to be at the boundary
	//We hence need to allow it to move
	//the centipede segment will move down the x coordinate is equal to screen_width -15;
	do{
		centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
	}while(centipedeTrain.myCentipede2.at(0).get_xCoordinate() != screen_Width -15);
	
    centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
    CHECK(centipedeTrain.myCentipede2.at(0).get_yCoordinate() == 15 );
}


TEST_CASE("Check that the centipede moves to the left")
{
    //Check that the centipede succesfully moves to the left
    //Check this for only one segment of the centipede.
	//moving left is directly subsequent moving down. 
	
	 polyCentipede centipedeTrain(1);
	
	do{
		centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
	}while(centipedeTrain.myCentipede2.at(0).get_xCoordinate() != screen_Width -15);
	
	//after we have hid the boundary, move the centipede twice
    centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
	centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
	
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
	   centipedeTrain.myCentipede2.at(0).moveCentipedeSegment();
   }
   CHECK(centipedeTrain.myCentipede2.at(0).get_xCoordinate() < screen_Width);
   
   CHECK(centipedeTrain.myCentipede2.at(0).get_xCoordinate() > 0);
}

//TEST_CASE ("Check that a centipede seperates after coming into contact with a bullet")


//TEST_CASE ("Check that a centipede changes direction after colliding with a mushroom")*/

