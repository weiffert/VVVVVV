#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Object.h"

using namespace sf;

class Disc : public Object
{
public:
	Disc();
	void pickedUp();
	~Disc();
};

