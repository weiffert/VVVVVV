#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Object.h"

using namespace sf;

class Block : public RectangleShape
{
public:
	Block();
	void sizeSetter(int, int);
	~Block();
};

