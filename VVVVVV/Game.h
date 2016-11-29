#pragma once
#include "Character.h"
#include "Object.h"
#include "Level.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <time.h>

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	unsigned int getScreenWidth();
	unsigned int getScreenHeight();
	bool intersect(Sprite&, Sprite&);
	bool verticalIntersect(Sprite&, RectangleShape&, double);
	void offSide(Sprite&, View&, int&, int&);
	bool afterText(RenderWindow&);
	void returnToCheck(Sprite&, Level&, View&, int&, int&);
	void drawComponents(Level&, Sprite&, Sprite&, RenderWindow&);
private:
	unsigned int screenWidth;
	unsigned int screenHeight;
	int top, bottom, left, right, xTemp, yTemp;
};