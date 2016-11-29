/*
Name: William Eiffert
Date: May 16, 2015
Description: This game is a sequel level to the game VVVVVV.
I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.
*/

#include "stdafx.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Level.h"
#include "Character.h"

using namespace std;
using namespace sf;

int _tmain(int argc, _TCHAR* argv[])
{
	//Declare the components of the game.
	int x, y, xTemp, yTemp, increment;
	x = 0;
	y = 0;
	bool finished = false;
	bool done;
	Game game;
	Level level;
	Character captain, crew;

	//Delineate the crew member.
	captain.makeCrewMember(false);
	crew.makeCrewMember(true);

	//SFML Window.
	RenderWindow window(VideoMode(game.getScreenWidth(), game.getScreenHeight()), "VVVVVV");
	VideoMode::getFullscreenModes();
	window.setPosition(Vector2i(0, 0));

	//Set the view.
	View view1(Vector2f(0, 0), Vector2f(game.getScreenWidth() / 5, game.getScreenHeight() / 5));
	view1.move(game.getScreenWidth() / 5 / 2, game.getScreenHeight() / 5 / 2);
	window.setView(view1);

	//Set the level.
	level.once();

	//Event loop. This controls the flow of the game.
	while (window.isOpen())
	{
		Event event;
		//Listen for events.
		while (window.pollEvent(event))
		{
			//Close the window if the exit button or the escape key is pressed.
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape))
				window.close();

			//Change the gravity if the keyboard is released.
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Space)
				{
					for (int i = 0; i < 64; i++)
					{
						if (i < 4)
						{
							if (game.verticalIntersect(captain, level.limiters[i], captain.getGravity()))
								captain.shiftGravity();
						}
						else
						{
							if (game.verticalIntersect(captain, level.everythingElse[i - 4], captain.getGravity()))
								captain.shiftGravity();
						}
					}
				}
			}
		}

		//Uncomment for seeing the whole level.
		//window.setView(window.getDefaultView());

		//Comment if the whole level needs to be seen.
		window.setView(view1);

		//Draw the components.
		game.drawComponents(level, captain, crew, window);

		//Character goes off a side of a screen, move the view screen.
		game.offSide(captain, view1, x, y);

		//Update the captain's position if he moves.
		captain.updatePos(event, level);
		
		//Check for intersections between spikes and the character.
		increment = 0;
		do
		{
			if (game.intersect(captain, level.spike[increment]))
			{
				if (!level.spike[increment].getPolarity())
				{
					captain.dead();
					game.drawComponents(level, captain, crew, window);
					time_t timer = time(NULL);
					while (time(NULL) - timer < 1)
						game.returnToCheck(captain, level, view1, x, y);
				}
			}
			increment++;
		} while (captain.getLife() && increment <= level.getSpikeNum());

		//If the captain is dead...
		if (!(captain.getLife()))
			captain.live();

		//Check for intersections between the captain and the disc.
		if (game.intersect(captain, level.disc))
			level.disc.pickedUp();

		//Check for intersections between the checkpoints and the character.
		increment = 0;
		done = false;
		do
		{
			if (game.intersect(captain, level.check[increment]))
			{
				if (level.check[increment].lastCheck())
					done = true;
				for (int x = 0; x < 15; x++)
					level.check[x].deadCheck();
				level.check[increment].activeCheck();
				done = true;
			}
			increment++;
		} while (!done && increment < 15);

		//Check if the character intersects the terminal.
		if (game.intersect(captain, level.terminal))
			if (Keyboard::isKeyPressed(Keyboard::Key::Return))
				level.terminal.showText(window);

		//Check if the character finds the crewman.
		if (game.intersect(captain, crew))
			finished = game.afterText(window);

		//Close the window if the captain has found the crewman.
		if (finished)
			window.close();
	}
	return 0;
}