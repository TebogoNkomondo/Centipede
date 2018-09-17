#include <SFML/Graphics.hpp>
#include "polyCentipede.h"
#include "player.h"
#include <vector>

using namespace std;

//Thsi class will be responisble for drawing all movable objects and displaying 
//Them on the screen as the game is being played
//This class will also be used to manipulate screen objects (make some of them dissaper) 
class screen 
{
public:
	//Inside the constructor, declare the object that will be drawn on the screen
	screen();
	
	//show the splash screen message
	void draw_Splash_Screen_Message(sf::RenderWindow& my_window);
	//Pass a sprite to draw on the screen and display what the object is doing
	void draw_Centipede(int segment_Index, double x_Position, double y_Position, sf::RenderWindow& my_window);
	
	void drawPlayer(sf::RenderWindow& window);
	
	//the vector of sprite centiede segments
	vector <sf::Sprite> centipede;

private:  //Every that is a member of the screen calss should go here:
	//centipede Segment sprite
	sf::Sprite centipedeSegment;
	sf::Texture centipedeTexture;
	
	//splash screen mesage dispay;
	sf::Text splash_Message;
	
	//Enter key flag
	bool isEnter;
	
	Player playyer;
	
};