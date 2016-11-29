#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Game.h"
#include "Object.h"
#include "Level.h"

using namespace sf;

class Character : public Object
{
public:
	Character();
	void makeCrewMember(bool);
	void shiftGravity();
	double getGravity();
	void updatePos(Event, Level&);
	void dead();
	void live();
	bool getLife();
	~Character();
private:
	bool life;
	double gravity;
};