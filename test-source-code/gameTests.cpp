#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/player.h"
using namespace std;
using namespace sf;

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

TEST_CASE("Check if position is set")
{
    Player player1;
	vector<sf::Vector2f> pos;
	player1.setPosition(sf::Vector2f(float(400),float(400.0f)));
	
    CHECK(player1.GetPlayer().getPosition() == sf::Vector2f(400.0f,400.0f));
}

TEST_CASE("Check for right movement")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,400));
	player2.MoveRight();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(400.3f,400.0f));
}

TEST_CASE("Check for left movement")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,400));
	player2.MoveLeft();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(399.7f,400.0f));
}


TEST_CASE("Check for up movement")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,700));
	player2.MoveUp();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(400.0f,699.7f));
}

TEST_CASE("Check for down movement")
{
	Player player2;
	player2.setPosition(sf::Vector2f(400,550));
	player2.MoveDown();
    CHECK(player2.GetPlayer().getPosition() == sf::Vector2f(400.0f,550.3f));
}

