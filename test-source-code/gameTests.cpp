#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/player.h"
#include "../game-source-code/centipede.h"
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
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(405,400.0f));
}

TEST_CASE("Check for left movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,400));
	player2.MoveLeft();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(395,400.0f));
}


TEST_CASE("Check for up movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,700));
	player2.MoveUp();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(400.0f,695));
}

TEST_CASE("Check for down movement of player")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,550));
	player2.MoveDown();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(400.0f,555));
}

//============================================================Centipede Tests=========================================================

TEST_CASE("Check that the centipede vector size is equal to the passed constructor value")
{
    //This test is to test that the created centipede's number of segments is eqaul to the passed constructor value;
    
    centipede theCentipede(20);
    CHECK(theCentipede.myCentipede.size() == 20);
}

TEST_CASE("Check that the centipede moves to the right")
{
    //Check that the centipede succesfully moves to the right
    //Check this for only one segment of the centipede.
    
    centipede theCentipede(1);
    theCentipede.moveCentipedeRight(0);
    CHECK(theCentipede.myCentipede.at(0).getPosition().x == 3);
}

TEST_CASE("Check that the centipede moves down")
{
    //Check that the centipede succesfully moves down
    //Check this for only one segment of the centipede.
    
    centipede theCentipede(1);
    //place the centiopede at the right boundary of the screen.
    theCentipede.myCentipede.at(0).setPosition(765,0);
    
    theCentipede.moveCentipedeDown(0);
    CHECK(theCentipede.myCentipede.at(0).getPosition().y == 19.99999f);
}

TEST_CASE("Check that the centipede moves to the left")
{
    //Check that the centipede succesfully moves to the left
    //Check this for only one segment of the centipede.

    centipede theCentipede(1);
    //first we need to set the flag boolean of out centipede segment to zero to indicate that we have made one turn down
    theCentipede.flag.at(0)=false;
    theCentipede.myCentipede.at(0).setPosition(765,0);
    theCentipede.moveCentipedeLeft(0);
    CHECK(theCentipede.myCentipede.at(0).getPosition().x == 762);
}

//TEST_CASE("The centipede does not go out of screen bounds")
//{
//   
//}

//TEST_CASE("The centipede sprite loads succesfully")
//{
//   
//}

//TEST_CASE("The centipede is able to move UP after hitting the bottom boundary of the screen")
//{
//   
//}