#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <time.h>
#include "Block.h"
#include "Check.h"
#include "Spike.h"
#include "Terminal.h"
#include "Disc.h"
#include "Figure.h"

using namespace sf;

class Level
{
public:
	Level();
	void level1(RenderWindow &);
	int getSpikeNum();
	void once();
	void spikeBlock(int, int, int);
	void moveOrigin(View, unsigned int, unsigned int);
	Block limiters[4];
	Block everythingElse[60];
	Check check[15];
	Spike spike[1000];
	Terminal terminal; 
	Disc disc;
	~Level();
private:
	int viewWidth;
	int viewHeight;
	int fifthHeight;
	int fifthWidth;
	int spikeNum;
};

