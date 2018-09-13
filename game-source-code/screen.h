#include <SFML/Graphics.hpp>
#include "polyCentipede.h"
#include <vector>

using namespace std;

class screen
{
public:
	//inside the constructor we need to declare screen size (height and the width)
	screen();
	//This function will diplay the splsh screen
	void splash_Screen();
	//keep the spash screen message displayed
	void keep_splash_Screen_Mesaage_Displayed(bool is_Enter_key);
	//Keep the window open until it is manually closed
	void keep_Window_Open();
	//Pass a sprite to draw on the screen and display what the object is doing
	void draw_Centipede(sf::Sprite object);
	//Display movements of objects on the screen
	void display_Object();
	//clear the screen
	void clear_Screen();
	
	//check if Enter key is pressed
	bool is_Enter_Key_Pressed();
	
private:  //Every that is a member of the screen calss should go here:
	//the window:
	sf::RenderWindow my_window;
	//centipede Segment sprite
	sf::Sprite centipedeSegment;
	sf::Texture centipedeTexture;
	
	//splash screen mesaage dispay;
	sf::Text splashMessage;
	
	//Enter key flag
	bool isEnter;
	
	vector <sf::Sprite> centipede;
	
};