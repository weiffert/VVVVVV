#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;
class Object : public Sprite
{
public:
	Object();
	const bool getPolarity();
	~Object();
protected:
	bool polarity;
	Texture texture;
};

