#include "stdafx.h"
#include "Object.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


Object::Object()
{
}


//Return the polarity.
const bool Object::getPolarity()
{
	return polarity;
}


Object::~Object()
{
}