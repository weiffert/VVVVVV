#include "stdafx.h"
#include "Spike.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


//Initialize the spike.
Spike::Spike()
{
	polarity = false;
	if (texture.loadFromFile("spike.png"))
	{
		texture.setSmooth(true);
		setTexture(texture);
	}
}


Spike::~Spike()
{
}
