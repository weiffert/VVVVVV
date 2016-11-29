#include "stdafx.h"
#include "Terminal.h"
#include "Game.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


//Declare the terminal
Terminal::Terminal()
{
	polarity = true;
	if (texture.loadFromFile("terminal.jpg"))
	{
		texture.setSmooth(true);
		setTexture(texture);
	}
}


//Initialize the text.
void Terminal::setText()
{
	if (font.loadFromFile("6809chargen.TTF"))
	{
		text1.setFont(font);
		text1.setString("The world collapsed.\nThis is a strange new place.\n"
			"Its a maze.\nIts not the labryinth,\nbut good luck all the same.");
		text1.setCharacterSize(56);
		text1.setColor(Color::White);
	}
}


//Show the text with a rectangle formatting the text.
void Terminal::showText(RenderWindow& w)
{
	Game game;
	//Initialize the text.
	setText();
	//Transform the text.
	text1.setOrigin(text1.getLocalBounds().width / 2, text1.getLocalBounds().height / 2);
	text1.setPosition(game.getScreenWidth() / 2, game.getScreenHeight() / 2); 
	//Initialize and transform the rectangle.
	RectangleShape r(Vector2f(text1.getLocalBounds().width + 5,
		text1.getLocalBounds().height + 15));
	r.setFillColor(Color::Black);
	r.setOrigin(r.getLocalBounds().width / 2, r.getLocalBounds().height / 2);
	r.setPosition(game.getScreenWidth() / 2, game.getScreenHeight() / 2);
	r.move(0, 15);
	//Display the rectangle and text.
	w.setView(w.getDefaultView());
	w.draw(r);
	w.draw(text1);
	w.display();
	//Wait until a key has been pressed.
	bool wait = true;
	while (wait)
		if (Keyboard::isKeyPressed(Keyboard::Key::Space) || Keyboard::isKeyPressed(Keyboard::Key::Left)
			|| Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::Escape))
			wait = false;
}


Terminal::~Terminal()
{
}