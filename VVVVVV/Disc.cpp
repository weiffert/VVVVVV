#include "stdafx.h"
#include "Disc.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


//Initialize the disc.
Disc::Disc()
{
	polarity = true;
	if (texture.loadFromFile("disc.png"))
	{
		texture.setSmooth(true);
		setTexture(texture);
	}
}


//Make the disc appear to have been picked up.
//Makes the disc transparant.
void Disc::pickedUp()
{
	setColor(Color(0, 0, 0));
}


Disc::~Disc()
{
}