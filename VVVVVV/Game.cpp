#include "stdafx.h"
#include "Game.h"
#include "Character.h"
#include "Object.h"
#include "Check.h"
#include "Level.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


Game::Game()
{
}


//Return the width of the window.
unsigned int Game::getScreenWidth()
{
	return 900;
}


//Return the height of the window.
unsigned int Game::getScreenHeight()
{
	return 900;
}


//Check for intersections between sprites.
bool Game::intersect(Sprite& captain, Sprite& object)
{
	if (object.getGlobalBounds().intersects(captain.getGlobalBounds()))
		return true;
	return false;
}


//Check if the sprite is going to intersect the rectangle the next iteration.
bool Game::verticalIntersect(Sprite& s, RectangleShape& r, double grav)
{
	RectangleShape s2;
	s2.setSize(Vector2f(s.getLocalBounds().width, s.getLocalBounds().height));
	s2.setOrigin(s2.getLocalBounds().width / 2, s2.getLocalBounds().height / 2);
	s2.setPosition(s.getPosition().x, s.getPosition().y);
	s2.move(0, grav);
	
	if (s2.getGlobalBounds().intersects(r.getGlobalBounds()))
		return true;
	return false;
}


//Checks if the character goes off the side of the viewscreen.
void Game::offSide(Sprite& sprite, View& view1, int& x, int& y)
{
	Game game;
	//Make the temporary values equal to the last values.
	xTemp = x;
	yTemp = y;
	//Reset the primary values.
	x = game.getScreenWidth();
	y = game.getScreenHeight();
	//Find which screen the sprite is on.
	while (x > sprite.getPosition().x)
		x -= game.getScreenWidth() / 5;
	while (y > sprite.getPosition().y)
		y -= game.getScreenHeight() / 5;
	//Find the differences to move the viewscreen.
	view1.move(x - xTemp, y - yTemp);
}


//Display the text after the solving of the puzzle.
bool Game::afterText(RenderWindow& w)
{
	Game game;
	Font f;
	Text text1, text2;
	//Make the screen reset.
	w.setView(w.getDefaultView());
	w.clear();
	//Initialize the text.
	if (f.loadFromFile("6809chargen.TTF"))
	{
		text1.setFont(f);
		text1.setString("Lone crew member rescued.\nPress return to exit.");
		text1.setCharacterSize(36);
		text1.setColor(Color::White);
		text2.setFont(f);
		text2.setString("LEVEL COMPLETE");
		text2.setCharacterSize(72);
		text2.setColor(Color::White);
		//Transform the text.
		text1.setOrigin(text1.getLocalBounds().width / 2, text1.getLocalBounds().height / 2);
		text2.setOrigin(text2.getLocalBounds().width / 2, text2.getLocalBounds().height / 2);
		text2.setPosition(game.getScreenWidth() / 2, game.getScreenHeight() / 2 - text2.getLocalBounds().height / 2);
		text1.setPosition(game.getScreenWidth() / 2, game.getScreenHeight() / 3 * 2);
		//Display the text.
		w.draw(text1);
		w.draw(text2);
		w.display();
		//Wait until the return key is pressed.
		bool wait = true;
		while (wait)
			if (Keyboard::isKeyPressed(Keyboard::Key::Return))
				wait = false;
	}
	return true;
}


//Draw the primary components of the game.
void Game::drawComponents(Level& l, Sprite& s, Sprite& s2, RenderWindow& w)
{
	w.clear();
	l.level1(w);
	w.draw(s);
	w.draw(s2);
	w.display();
}


//Move the character back to the last check point.
void Game::returnToCheck(Sprite& sprite, Level& l, View& v, int& x, int& y)
{
	//Until the sprite is moved to the live check, repeat.
	int i = 0;
	do
	{
		//Check if the checkpoint is live.
		if (l.check[i].lastCheck())
		{
			//Move the sprite.
			sprite.setPosition(l.check[i].getPosition().x + sprite.getLocalBounds().width / 2,
				l.check[i].getPosition().y + l.check[i].getLocalBounds().height - sprite.getLocalBounds().height / 2);
			//Move the viewscreen to the proper location.
			xTemp = x;
			yTemp = y;
			x = getScreenWidth();
			y = getScreenHeight();
			while (x > sprite.getPosition().x)
				x -= getScreenWidth() / 5;
			while (y > sprite.getPosition().y)
				y -= getScreenHeight() / 5;
			v.move(x - xTemp, y - yTemp);
		}
		i++;
	} while (!(l.check[i - 1].lastCheck()));
}


Game::~Game()
{
}