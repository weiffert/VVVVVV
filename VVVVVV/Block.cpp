#include "stdafx.h"
#include "Block.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


Block::Block()
{
}


//Set the size and color of the block.
void Block::sizeSetter(int x, int y)
{
	setSize(Vector2f(x, y));
	setFillColor(Color(23, 177, 246));
}


Block::~Block()
{
}
