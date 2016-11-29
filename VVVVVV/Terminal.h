#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Object.h"

using namespace sf;

class Terminal : public Object
{
public:
	Terminal();
	void setText();
	void showText(RenderWindow&);
	~Terminal();
private:
	Text text1;
	Font font;
};

