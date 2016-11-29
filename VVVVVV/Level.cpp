#include "stdafx.h"
#include "Level.h"
#include "Game.h"
#include "Block.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


Level::Level()
{
}


//Draw the components of the level.
void Level::level1(RenderWindow &w)
{
	w.draw(terminal);
	w.draw(disc);
	for (int i = 0; i < 15; i++)
		w.draw(check[i]);
	for (int i = 0; i <= spikeNum; i++)
		w.draw(spike[i]);
	for (int i = 0; i < 4; i++)
			w.draw(limiters[i]);
	for (int i = 0; i <60; i++)
		w.draw(everythingElse[i]);
}


//Return the value of how many spikes were used.
int Level::getSpikeNum()
{
	return spikeNum;
}


//Declares the obstacles of the game.
void Level::once()
{
	//Initialize the termial, disc, blocks, spikes, and checkpoints.
	Game game;
	viewHeight = game.getScreenHeight() / 5;
	viewWidth = game.getScreenWidth() / 5;
	fifthHeight = game.getScreenHeight() / 25;
	fifthWidth = game.getScreenWidth() / 25;

	//Position the terminal.
	terminal.setPosition(fifthWidth * 2 - terminal.getLocalBounds().width,
		fifthHeight * 4 - terminal.getLocalBounds().height);

	//Position the disc.
	disc.setPosition(fifthWidth + fifthWidth / 2 - disc.getLocalBounds().width / 2,
		viewHeight * 3 + fifthHeight + fifthHeight / 2 - disc.getLocalBounds().height / 2);

	//Position the blocks and size them.
	limiters[0].sizeSetter(game.getScreenWidth(), fifthHeight);
	limiters[0].setPosition(0, 0);
	limiters[1].sizeSetter(game.getScreenWidth(), fifthHeight);
	limiters[1].setPosition(0, game.getScreenHeight() - fifthHeight);
	limiters[2].sizeSetter(fifthWidth, game.getScreenHeight());
	limiters[2].setPosition(0, 0);
	limiters[3].sizeSetter(fifthWidth, game.getScreenHeight());
	limiters[3].setPosition(game.getScreenWidth() - fifthWidth, 0);
	everythingElse[0].sizeSetter(viewWidth - fifthWidth * 2, fifthHeight);
	everythingElse[0].setPosition(0, fifthHeight * 2);
	everythingElse[1].sizeSetter(viewWidth * 2 + fifthWidth * 2, fifthHeight * 2);
	everythingElse[1].setPosition(0, fifthHeight * 4);
	everythingElse[2].sizeSetter(fifthWidth * 2, fifthHeight);
	everythingElse[2].setPosition(viewWidth * 2 + fifthWidth * 2, fifthHeight * 2);
	everythingElse[3].sizeSetter(viewWidth - fifthWidth, fifthHeight);
	everythingElse[3].setPosition(viewWidth * 2 + fifthWidth * 4, fifthHeight * 3);
	everythingElse[4].sizeSetter(viewWidth, fifthHeight);
	everythingElse[4].setPosition(viewWidth * 3 + fifthWidth * 2, fifthHeight * 2);
	everythingElse[5].sizeSetter(fifthWidth * 2, fifthHeight * 4);
	everythingElse[5].setPosition(viewWidth * 5 - fifthWidth * 2, fifthHeight * 2);
	everythingElse[6].sizeSetter(fifthWidth, fifthHeight * 4);
	everythingElse[6].setPosition(viewWidth * 4 + fifthWidth, fifthHeight * 2);
	everythingElse[7].sizeSetter(fifthWidth * 2, fifthHeight * 7);
	everythingElse[7].setPosition(viewWidth * 4 - fifthWidth, viewHeight - fifthHeight);
	everythingElse[8].sizeSetter(viewWidth + fifthWidth * 2, fifthHeight);
	everythingElse[8].setPosition(viewWidth * 2 + fifthWidth * 3, viewHeight + fifthHeight);
	everythingElse[9].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[9].setPosition(viewWidth * 4 + fifthWidth * 2, viewHeight + fifthHeight * 2);
	everythingElse[10].sizeSetter(fifthWidth, viewHeight);
	everythingElse[10].setPosition(viewWidth * 4 + fifthWidth, viewHeight * 2 - fifthHeight);
	everythingElse[11].sizeSetter(fifthWidth, viewHeight);
	everythingElse[11].setPosition(viewWidth * 4 + fifthWidth * 3, viewHeight + fifthHeight * 4);
	everythingElse[12].sizeSetter(fifthWidth * 4, fifthHeight * 2);
	everythingElse[12].setPosition(viewWidth * 4 + fifthWidth, viewHeight * 3 - fifthHeight);
	everythingElse[13].sizeSetter(viewWidth, fifthHeight);
	everythingElse[13].setPosition(viewWidth * 4 - fifthWidth, viewHeight * 4 - fifthHeight * 2);
	everythingElse[14].sizeSetter(fifthWidth * 15, fifthHeight);
	everythingElse[14].setPosition(fifthWidth * 3, viewHeight * 3 + fifthHeight * 3);
	everythingElse[15].sizeSetter(fifthWidth * 3, fifthHeight * 2);
	everythingElse[15].setPosition(viewWidth * 3 - fifthWidth, viewHeight * 3 - fifthHeight);
	everythingElse[16].sizeSetter(fifthWidth, fifthHeight * 2);
	everythingElse[16].setPosition(viewWidth * 3 + fifthWidth * 3, viewHeight * 2 + fifthHeight);
	everythingElse[17].sizeSetter(fifthHeight, fifthWidth);
	everythingElse[17].setPosition(viewWidth * 3 + fifthWidth, viewHeight * 2 + fifthHeight * 2);
	everythingElse[18].sizeSetter(fifthWidth * 2, fifthHeight * 4);
	everythingElse[18].setPosition(viewWidth * 3 - fifthWidth, viewHeight * 2 - fifthHeight);
	everythingElse[19].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[19].setPosition(viewWidth * 3 + fifthWidth * 2, viewHeight + fifthHeight * 3);
	everythingElse[20].sizeSetter(fifthWidth, fifthHeight * 2);
	everythingElse[20].setPosition(viewWidth * 2 + fifthWidth * 3, viewHeight + fifthHeight * 3);
	everythingElse[21].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[21].setPosition(viewWidth * 2 + fifthWidth, viewHeight + fifthHeight * 2);
	everythingElse[22].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[22].setPosition(viewWidth + fifthWidth, viewHeight + fifthHeight * 2);
	everythingElse[23].sizeSetter(fifthWidth, viewHeight);
	everythingElse[23].setPosition(fifthWidth * 2, viewHeight + fifthHeight * 2);
	everythingElse[24].sizeSetter(fifthWidth * 2, fifthHeight * 2);
	everythingElse[24].setPosition(fifthWidth * 4, viewHeight * 2 - fifthHeight);
	everythingElse[25].sizeSetter(fifthWidth, fifthHeight * 2);
	everythingElse[25].setPosition(fifthWidth * 3, viewHeight * 2 + fifthHeight * 2);
	everythingElse[26].sizeSetter(fifthWidth, fifthHeight * 3);
	everythingElse[26].setPosition(fifthWidth, viewHeight * 2 + fifthHeight * 3);
	everythingElse[27].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[27].setPosition(fifthWidth * 2, viewHeight * 3 + fifthHeight);
	everythingElse[28].sizeSetter(fifthWidth * 2, viewHeight);
	everythingElse[28].setPosition(viewWidth - fifthWidth, viewHeight * 3 - fifthHeight);
	everythingElse[29].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[29].setPosition(viewWidth + fifthWidth, viewHeight * 2 + fifthHeight * 3);
	everythingElse[30].sizeSetter(viewWidth + fifthWidth * 2, fifthHeight);
	everythingElse[30].setPosition(viewWidth + fifthWidth, viewHeight * 2 + fifthHeight);
	everythingElse[31].sizeSetter(fifthWidth * 4, fifthHeight);
	everythingElse[31].setPosition(viewWidth + fifthWidth * 3, viewHeight * 2 + fifthHeight * 2);
	everythingElse[32].sizeSetter(fifthWidth * 3, fifthHeight);
	everythingElse[32].setPosition(viewWidth + fifthWidth * 3, viewHeight * 2 + fifthHeight * 3);
	everythingElse[33].sizeSetter(fifthWidth * 2, fifthHeight);
	everythingElse[33].setPosition(viewWidth + fifthWidth * 3, viewHeight * 2 + fifthHeight * 4);
	everythingElse[34].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[34].setPosition(viewWidth + fifthWidth * 3, viewHeight * 3);
	everythingElse[35].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[35].setPosition(viewWidth + fifthWidth * 2, viewHeight * 3 + fifthHeight);
	everythingElse[36].sizeSetter(fifthWidth, fifthHeight * 4);
	everythingElse[36].setPosition(fifthWidth * 2, viewHeight * 4 - fifthHeight);
	everythingElse[37].sizeSetter(viewWidth, fifthHeight);
	everythingElse[37].setPosition(fifthWidth, viewHeight * 4 + fifthHeight * 2);
	everythingElse[38].sizeSetter(fifthWidth, fifthHeight * 2);
	everythingElse[38].setPosition(viewWidth + fifthWidth * 2, viewHeight * 4 + fifthHeight * 2);
	everythingElse[39].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[39].setPosition(viewWidth + fifthWidth * 3, viewHeight * 4 + fifthHeight * 3);
	everythingElse[40].sizeSetter(fifthWidth * 3, fifthHeight);
	everythingElse[40].setPosition(viewWidth * 2 - fifthWidth, viewHeight * 3 + fifthHeight * 2);
	everythingElse[41].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[41].setPosition(viewWidth * 2, viewHeight * 3 + fifthHeight);
	everythingElse[42].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[42].setPosition(viewWidth * 2 + fifthWidth, viewHeight * 3);
	everythingElse[43].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[43].setPosition(viewWidth * 2 + fifthWidth * 2, viewHeight * 3 - fifthHeight);
	everythingElse[44].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[44].setPosition(viewWidth * 2 + fifthWidth * 3, viewHeight * 2 + fifthHeight * 3);
	everythingElse[45].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[45].setPosition(viewWidth * 2 + fifthWidth * 3, viewHeight * 3 + fifthHeight);
	everythingElse[46].sizeSetter(fifthWidth * 2, fifthHeight * 2);
	everythingElse[46].setPosition(viewWidth * 2 - fifthWidth, viewHeight * 2 - fifthHeight);
	everythingElse[47].sizeSetter(fifthWidth, fifthHeight * 2);
	everythingElse[47].setPosition(viewWidth * 2 + fifthWidth, viewHeight * 4 + fifthHeight * 2);
	everythingElse[48].sizeSetter(fifthWidth, fifthHeight * 2);
	everythingElse[48].setPosition(viewWidth * 2 + fifthWidth * 3, viewHeight * 4 - fifthHeight);
	everythingElse[49].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[49].setPosition(viewWidth * 2 + fifthWidth * 3, viewHeight * 5 - fifthHeight * 2);
	everythingElse[50].sizeSetter(fifthWidth * 2, fifthHeight);
	everythingElse[50].setPosition(viewWidth * 2 + fifthWidth * 4, viewHeight * 4 + fifthHeight * 2);
	everythingElse[51].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[51].setPosition(viewWidth * 3 + fifthWidth, viewHeight * 4 + fifthHeight);
	everythingElse[52].sizeSetter(fifthWidth, fifthHeight);
	everythingElse[52].setPosition(viewWidth * 3 + fifthWidth * 2, viewHeight * 4 - fifthHeight);
	everythingElse[53].sizeSetter(fifthWidth * 2, fifthHeight);
	everythingElse[53].setPosition(viewWidth * 3 + fifthWidth * 3, viewHeight * 4);
	everythingElse[54].sizeSetter(fifthWidth * 2, fifthHeight);
	everythingElse[54].setPosition(viewWidth * 4, viewHeight * 4 + fifthHeight);

	//Position the checkpoints.
	check[0].setPosition(fifthWidth * 2 - check[0].getLocalBounds().width,
		fifthHeight * 2 - check[0].getLocalBounds().height);
	check[1].setPosition(viewWidth + fifthWidth / 2 - check[1].getLocalBounds().width / 2,
		fifthHeight * 4 - check[1].getLocalBounds().height);
	check[2].setPosition(viewWidth + fifthWidth * 4 + fifthWidth / 2 - check[2].getLocalBounds().width / 2,
		fifthHeight * 4 - check[2].getLocalBounds().height);
	check[3].setPosition(viewWidth * 3 + fifthWidth * 2 + fifthWidth / 2 - check[3].getLocalBounds().width / 2,
		fifthHeight * 2 - check[3].getLocalBounds().height);
	check[4].setPosition(viewWidth * 4 + fifthWidth + fifthWidth / 2 - check[4].getLocalBounds().width / 2,
		fifthHeight * 2 - check[4].getLocalBounds().height);
	check[5].setPosition(viewWidth * 4 + fifthWidth * 2 + fifthWidth / 2 - check[5].getLocalBounds().width / 2,
		viewHeight * 3 - fifthHeight - check[5].getLocalBounds().height);
	check[6].setPosition(viewWidth * 2 + fifthHeight * 3 + fifthWidth / 2 - check[6].getLocalBounds().width / 2,
		viewHeight + fifthHeight - check[6].getLocalBounds().height);
	check[7].setPosition(viewWidth + fifthWidth + fifthWidth / 2 - check[7].getLocalBounds().width / 2,
		viewHeight + fifthHeight * 2 - check[7].getLocalBounds().height);
	check[8].setPosition(fifthWidth * 2 + fifthWidth / 2 - check[8].getLocalBounds().width / 2,
		viewHeight + fifthHeight * 2 - check[8].getLocalBounds().height);
	check[9].setPosition(fifthWidth + fifthWidth / 2 - check[9].getLocalBounds().width / 2,
		viewHeight * 4 + fifthHeight * 2 - check[9].getLocalBounds().height);
	check[10].setPosition(viewWidth + fifthWidth / 2 - check[10].getLocalBounds().width / 2,
		viewHeight * 2 + fifthHeight * 4 - check[10].getLocalBounds().height);
	check[11].setPosition(viewWidth + fifthWidth + fifthWidth / 2 - check[11].getLocalBounds().width / 2,
		viewHeight * 3 + fifthHeight * 3 - check[11].getLocalBounds().height);
	check[12].setPosition(viewWidth * 3 - fifthWidth + fifthWidth / 2 - check[12].getLocalBounds().width / 2,
		viewHeight + fifthHeight * 4 - check[12].getLocalBounds().height);
	check[13].setPosition(viewWidth * 3 - fifthWidth + fifthWidth / 2 - check[13].getLocalBounds().width / 2,
		viewHeight * 2 + fifthHeight * 4 - check[13].getLocalBounds().height);
	check[14].setPosition(viewWidth * 5 - fifthWidth * 2 + fifthWidth / 2 - check[14].getLocalBounds().width / 2,
		viewHeight * 3 + fifthHeight * 3 - check[14].getLocalBounds().height);

	//Position and rotate the spike blocks.
	spikeNum = 0;
	int width, height, rotation;
	rotation = 0;
	for (int i = 1; i < 4; i++)
	{
		width = viewWidth + fifthWidth * i;
		height = fifthHeight * 4;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth * 4;
	height = fifthHeight * 3;
	spikeBlock(width, height, rotation);

	width = viewWidth * 3 + fifthWidth;
	spikeBlock(width, height, rotation);

	width = viewWidth * 3;
	height = fifthHeight;
	rotation = 180;
	spikeBlock(width, height, rotation);

	for (int i = 1; i < 5; i++)
	{
		width = viewWidth * 4 + fifthWidth * 2;
		height = fifthHeight + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	for (int i = 1; i < 5; i++)
	{
		width = viewWidth * 4 + fifthWidth * 3;
		height = fifthHeight + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 4 + fifthWidth;
	height = viewHeight + fifthHeight;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 + fifthWidth * 3;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 + fifthWidth * 2;
	height = viewHeight + fifthHeight * 2;
	rotation = 0;
	spikeBlock(width, height, rotation);

	height = viewHeight + fifthHeight * 3;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 + fifthWidth;
	height = viewHeight + fifthHeight * 4;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewHeight * 4 + fifthHeight * 3;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 5; i++)
	{
		width = viewWidth * 4 + fifthWidth * 2;
		height = viewHeight + fifthHeight * 4 + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	for (int i = 0; i < 5; i++)
	{
		width = viewWidth * 4 + fifthWidth * 3;
		height = viewHeight + fifthHeight * 4 + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 3;
	height = viewHeight + fifthHeight;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth * 3 + fifthWidth * 2 + fifthWidth * i;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 3 + fifthWidth;
	height = fifthHeight * 4;
	rotation = 180;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 3; i++)
	{
		width = viewWidth + fifthWidth * 2 + fifthWidth * i;
		height = viewHeight + fifthHeight;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 3; i++)
	{
		width = viewWidth * 2 + fifthWidth * 4 + fifthWidth * i;
		height = viewHeight + fifthHeight * 2;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 3 + fifthWidth * 3;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 6; i++)
	{
		width = fifthWidth;
		height = viewHeight + fifthHeight * 2 + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	for (int i = 0; i < 5; i++)
	{
		width = fifthWidth * 2;
		height = viewHeight + fifthHeight * 2 + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth + fifthWidth;
	height = viewHeight + fifthHeight * 2;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 2;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth;
	rotation = 270;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 4; i++)
	{
		width = viewWidth * 3 + fifthWidth * 4;
		height = viewHeight + fifthHeight * 2 + fifthHeight * i;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth + fifthWidth;
	height = viewHeight + fifthHeight * 3;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth * 3;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth * 2 + fifthWidth * 3;
		height = viewHeight + fifthHeight * 3 + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 3 + fifthWidth * 2;
	height = viewHeight + fifthHeight * 3;
	spikeBlock(width, height, rotation);

	width = viewWidth * 3 + fifthWidth * 3;
	rotation = 90;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth + fifthWidth * 4 + fifthHeight * i;
		height = viewHeight + fifthHeight * 4;
		rotation = 0;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 3 + fifthWidth * 2;
	rotation = 180;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth + fifthWidth;
		height = viewHeight + fifthHeight * 4 + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth * 2 + fifthWidth;
		height = viewHeight + fifthHeight * 4 + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth * 3;
	height = viewHeight * 2;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 4;
	height = viewHeight * 2 + fifthHeight;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth + fifthWidth + fifthWidth * i;
		rotation = 0;
		spikeBlock(width, height, rotation);
	}

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth * 2 + fifthWidth + fifthWidth * i;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth * 3;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 2;
	height = viewHeight * 2 + fifthHeight * 2;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 3;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth + fifthWidth + fifthWidth * i;
		rotation = 180;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth * 2;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = fifthWidth * 3;
		height = viewHeight * 2 + fifthHeight * 2 + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	for (int i = 0; i < 4; i++)
	{
		width = viewWidth + fifthWidth * 3;
		height = viewHeight * 2 + fifthHeight * 2 + fifthHeight * i;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth * 2;
	height = viewHeight * 2 + fifthHeight * 2;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = viewWidth * 3 + fifthWidth * 2;
	spikeBlock(width, height, rotation);

	width = fifthWidth;
	height = viewHeight * 2 + fifthHeight * 3;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth * 3;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 3; i++)
	{
		width = fifthWidth * 2;
		height = viewHeight * 2 + fifthHeight * 3 + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth;
	height = viewHeight * 2 + fifthHeight * 3;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth * 3;
	rotation = 270;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 3;
	height = viewHeight * 2 + fifthHeight * 4;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewHeight + fifthHeight;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthHeight * 2;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 4; i++)
	{
		width = fifthWidth * 4;
		height = viewHeight * 2 + fifthHeight * 4 + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2;
	height = viewHeight * 3 - fifthHeight;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth * 2;
	rotation = 270;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 - fifthWidth;
	height = viewHeight * 3;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 3; i++)
	{
		width = viewWidth * 2 + fifthWidth * 4;
		height = viewHeight * 2 + fifthHeight * i;
		rotation = 270;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth + fifthWidth * 4;
	height = viewHeight * 3;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth;
	rotation = 270;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 2;
	height = viewHeight * 3 + fifthHeight;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 2;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 3;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 3;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2;
	rotation = 270;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 6; i++)
	{
		width = fifthWidth;
		height = viewHeight * 3 + fifthHeight + fifthHeight * i;
		rotation = 90;
		spikeBlock(width, height, rotation);
	}

	width = fifthWidth * 2;
	height = viewHeight * 3 + fifthHeight * 2;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 2;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 4;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 4;
	rotation = 270;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 3;
	height = viewHeight * 3 + fifthHeight * 3;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 2;
	height = viewHeight * 3 + fifthHeight * 4;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth + fifthWidth * 3 + fifthWidth * i;
		rotation = 180;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth;
	spikeBlock(width, height, rotation);

	width = viewWidth * 3 + fifthWidth;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 + fifthWidth * 2;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 - fifthWidth;
	height = viewHeight * 4;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth * 3 + fifthWidth * 3;
	height = viewHeight * 4 + fifthHeight;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 + fifthWidth;
	height = viewHeight * 4 + fifthHeight;
	rotation = 0;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = viewWidth * 3 - fifthWidth + fifthWidth * i;
		height = viewHeight * 4 + fifthHeight * 2;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 4;
	rotation = 180;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth * 4;
	rotation = 270;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 2;
	height = viewHeight * 4 + fifthHeight * 3;
	rotation = 180;
	spikeBlock(width, height, rotation);

	for (int i = 0; i < 2; i++)
	{
		width = fifthWidth * 4 + fifthWidth * i;
		spikeBlock(width, height, rotation);
	}

	width = viewWidth * 2 + fifthWidth * 3;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth * 4;
	rotation = 90;
	spikeBlock(width, height, rotation);

	width = viewWidth * 2 + fifthWidth * 3;
	rotation = 270;
	spikeBlock(width, height, rotation);

	width = fifthWidth * 3;
	height = viewHeight * 5 - fifthHeight;
	rotation = 0;
	spikeBlock(width, height, rotation);

	width = viewWidth + fifthWidth;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 - fifthWidth;
	spikeBlock(width, height, rotation);

	width = viewWidth * 4 + fifthWidth;
	spikeBlock(width, height, rotation);
}


//Position the individual spikes in the size of a block.
void Level::spikeBlock(int width, int height, int rotation)
{
	for (int i = 0; i < fifthWidth; i += spike[spikeNum].getLocalBounds().width)
	{
		if (rotation == 90)
		{
			spike[spikeNum].rotate(rotation);
			spike[spikeNum].setPosition(width + spike[spikeNum].getLocalBounds().width, height + i);
		}
		if (rotation == 180)
		{
			spike[spikeNum].rotate(rotation);
			spike[spikeNum].setPosition(i + width + spike[spikeNum].getLocalBounds().width, height + spike[spikeNum].getLocalBounds().height);
		}
		if (rotation == 270)
		{
			spike[spikeNum].rotate(rotation);
			spike[spikeNum].setPosition(width - spike[spikeNum].getLocalBounds().width, height + i + spike[spikeNum].getLocalBounds().width);
		}
		if (rotation == 0)
			spike[spikeNum].setPosition(i + width, height - spike[spikeNum].getLocalBounds().height);
		spikeNum++;
	}
}


//Move the view point.
void Level::moveOrigin(View view, unsigned int x, unsigned int y)
{
	view.move(x, y);
}


Level::~Level()
{
}