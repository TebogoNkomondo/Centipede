#include "screen.h"

screen::screen()
{ 
	//screen_Height and screen_Width are already defined in the centipedeSegment header file
	//Which is already include in the polyCentipede header
	
	//We need to render the window
	sf::RenderWindow my_window (sf::VideoMode(screen_Width,screen_Height), " The CentipedeGame", sf::Style::Titlebar );
}

void screen::splash_Screen()
{
	// Set up text to display on splash screen
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"))
        cout<< "Error loading sansation.ttf from resource folder"<<endl;

	 // Initialize the splash message
    splashMessage.setFont(font);
    splashMessage.setCharacterSize(40);
    splashMessage.setPosition(170.f, 150.f);
    splashMessage.setFillColor(sf::Color::Green);
    splashMessage.setString("Welcome to the Centipede Game!\n\nInstructions:\nPress Space bar to shoot\nPress Right to move Right\nPress Left to move Left\nPress Down to move Down\nPress Up to move UP\n\nPress Enter to start the Game!!");
	
	isEnter= false;
}

void screen::keep_splash_Screen_Mesaage_Displayed(bool is_Enter_key)
{
	if(is_Enter_key)
	{
		my_window.draw(splashMessage);
		my_window.display();
		my_window.clear();
	}
}

bool screen::is_Enter_Key_Pressed()
{
	sf::Event event;
	//Check if the enter key has been presed. If it is set 'startTheGame' to true
	while(my_window.pollEvent(event))
	{
		 switch(event.type)
		{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Enter:
						return true;
						break;
					
					default:
						return false;
				}
			default:
				return false;
		}
	}
}

void screen::keep_Window_Open()
{
	while(my_window.isOpen())
    {
        sf::Event event;
		while(my_window.pollEvent(event))
        {
            switch(event.type)
            {
                //check that the window is not closed
                case sf::Event::Closed:
                    my_window.close();
                    break;
					
					//Also check the state of the Enter key:
					isEnter= is_Enter_Key_Pressed();
					
				default:
                    break;
			}
		}
	}
}

void screen::draw_Centipede(sf::Sprite object){
	//we need to inialize this centipede object we are drawing in main
	
}

