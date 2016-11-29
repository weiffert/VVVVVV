#include "stdafx.h"
#include "Check.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


//Initialize the checkpoint.
Check::Check()
{
	polarity = true;
	live = false;
	deadCheck();
}


//Make the check live.
void Check::activeCheck()
{
	if (active.loadFromFile("activeCheck.jpg"))
	{
		active.setSmooth(true);
		setTexture(active);
	}
	live = true;
}


//Make the check dead.
void Check::deadCheck()
{
	if (dead.loadFromFile("deadCheck.png"))
	{
		dead.setSmooth(true);
		setTexture(dead);
	}
	live = false;
}


//Return the checkpoint's value on live.
bool Check::lastCheck()
{
	return live;
}


Check::~Check()
{
}