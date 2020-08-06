## Centipede

- This project was completed in 2018 for the Software Development 2 course at the University of Witwatersrand.
- The project was a 2 person effort by myself(Tebogo Nkomondo) and my partner Oratile Marope. 
- The project aim was to re-create the Centipede arcade game using object-orientated C++(C++17) and the SFML library.
- Furthermore doctest was used to implement tests for the Game. 

### Features
- **Centipede** :
    - The centipede train moves horizontally from the top row of the screen.
    - The centipede train consists of 12 elements. Each element is represented by a circular object.
    - Upon collision with a screen boundary or mushroom element, the centipede train moves 1 row down and changes direction
- **Player** :
    - The player is represented by a space ship object. 
        - The player can move up, down, left and right in a small designated player area at the bottom of the screen.
        - The player can shoot bullets from the center of the space ship.
        - The player dies upon collision with either a mushroom, spider or a centipede element.
        - The player also dies if any elements of the centipede train reach the bottom of the screen.
        - When the player's fired bullets collide with a mushroom, spider or a centipede element the player has points added to their score. 
        - At the end of the game, the player's points will be displayed on the screen along with the current high score for all players.
            
- **Bullets** :
    - The bullets are represented by a laser object.
    - Bullets will kill the object that they collide with.
              
- **Spider** :
    - A spider is represented by a spider object.
    - Spiders move diagonally accross the player area.
    - Upon collision with the upper or lower player area boundaries, the spider will continue moving in the same horizontal direction but the opposite vertical direction.
    - When the spider collides with a left or right player area boundary it will move in the opposite horizontal direction but same vertical direction.
    - If killed, another spider will appear on the playing area at periodic time interva##ls.
    - The spiders will kill the player if they collide with the player.
              
- **Mushroom** :
    - Mushrooms are represented by a mushroom object.
    - A random number of mushrooms are randonly placed within the playing area at the start of each game. 
        
  **SplashScreen** :
    - When launched the game will display a splash screen with game playing instructions.
    - When a game ends the splash screen will appear again displaying the current score and high score.
        
              
 ### Playing the game:
 - To play the game open the executables folder and launch the Game.exe file.