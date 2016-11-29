#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Object.h"

using namespace sf;

class Check : public Object
{
public:
	Check();
	void activeCheck();
	void deadCheck();
	bool lastCheck();
	~Check();
private:
	Texture dead;
	Texture active;
	bool live;
};

