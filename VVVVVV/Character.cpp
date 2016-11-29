#include "stdafx.h"
#include "Character.h"
#include "Game.h"
#include "Level.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


//Initialize the character.
Character::Character()
{
	Game game;
	gravity = 0.5;
	//Load the texture.
	if (texture.loadFromFile("viridian.png"))
	{
		texture.setSmooth(true);
		setTexture(texture);
		setColor(Color(136, 252, 255));
	}
	//Transform the character.
	setOrigin(getLocalBounds().width / 2, getLocalBounds().height / 2);	
	setPosition(game.getScreenWidth() / 25 * 2 - getLocalBounds().width / 2,
		game.getScreenHeight() / 25 * 2 - getLocalBounds().height / 2);
}


//Transform a crew member.
void Character::makeCrewMember(bool second)
{
	Game game;
	if (second)
	{
		setColor(Color(213, 104, 212));
		setPosition(game.getScreenWidth() / 25 + getLocalBounds().width / 2,
			game.getScreenHeight() - game.getScreenHeight() / 25 - getLocalBounds().height / 2);
	}
}


//Switch the gravity and rotate the character.
void Character::shiftGravity()
{
	gravity *= -1;
	rotate(180);
}


//Return the value of gravity.
double Character::getGravity()
{
	return gravity;
}


//Update the position with the character and its relation with the level.
void Character::updatePos(Event e, Level& level)
{
	Game game;
	int xOff = 0;
	
	if (e.type == Event::KeyPressed)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
			xOff = -1;
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
			xOff = 1;
	}

	//Basically if there is gravity...
	if (gravity != 0)
	{
		//The person is to move.
		//create a temp, and apply the move to it.
		Sprite temp;
		Texture texture;
		if (texture.loadFromFile("viridian.png"))
		{
			temp.setTexture(texture);
			temp.setOrigin(temp.getLocalBounds().width / 2, temp.getLocalBounds().height / 2);
			temp.setPosition(getPosition());
			temp.move(xOff, 0);

			//check the limiters.
			//check the static objects.
			//if an intersection occurs, kill the loop and set a flag to true.
			int increment = 0;
			bool flagHorz = false;
			bool flagVert = false;

			//If there is horizontal motion...
			if (xOff != 0)
			{
				do
				{
					//Check for intersections with the temporary.
					if (increment < 4)
						flagHorz = temp.getGlobalBounds().intersects(level.limiters[increment].getGlobalBounds());
					else
						flagHorz = temp.getGlobalBounds().intersects(level.everythingElse[increment - 4].getGlobalBounds());
					increment++;
					//Repeat unless there is a true value for flagHorz or all of the blocks have been checked.
				} while (!flagHorz && increment < 64);
			}

			//Move the temporary back and apply the gravity value.
			temp.move(-1 * xOff, gravity);
			increment = 0;
			do
			{
				//Check for intersections with the temporary.
				if (increment < 4)
					flagVert = temp.getGlobalBounds().intersects(level.limiters[increment].getGlobalBounds());
				else
					flagVert = temp.getGlobalBounds().intersects(level.everythingElse[increment - 4].getGlobalBounds());
				//Repeat unless there is a true value for flagVert or all of the blocks have been checked.
				increment++;
			} while (!flagVert && increment < 64);

			//move the actual character
			if (!flagVert)
			{
				if (!flagHorz)
					move(xOff, gravity);
				else
					move(0, gravity);
			}			
			else
			{
				if (!flagHorz)
					move(xOff, 0);
				else
					move(0, 0); 
			}
		}
	}

}


//Transform the character to be red.
void Character::dead()
{
	life = false;
	setColor(Color(220, 10, 7));
}


//Transform the character to be blue and shift the gravity.
void Character::live()
{
	life = true;
	setColor(Color(136, 252, 255));
	if (gravity < 0)
		shiftGravity();
}


//Return the life value.
bool Character::getLife()
{
	return life;
}


Character::~Character()
{
}