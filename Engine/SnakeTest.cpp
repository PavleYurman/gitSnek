#include "SnakeTest.h"

SnakeTest::SnakeTest(Graphics& gfx, Board& brd)
	:
	gfx(gfx),
	brd(brd)
{
	for (int l = 0; l < snakeLenght; l++) // continue
	{
		loc[l].x = l;
		loc[l].y = 3;		
	}
}

void SnakeTest::Draw(Color c)
{
	for (int l = 0; l < snakeLenght; l++) // continue
	{
		brd.DrawCell(loc[l], c);		
	}
}


void SnakeTest::TransitionLocation()
{
	for (int l = 0; l < snakeLenght; l++)
	{
		if (loc[l].x < 0)
		{
			loc[l].x = brd.GetWidth() - 1;
		}
		if (loc[l].x >= brd.GetWidth())
		{
			loc[l].x = 0;
		}
		if (loc[l].y < 0)
		{
			loc[l].y = brd.GetHeight() - 1;
		}
		if (loc[l].y >= brd.GetHeight())
		{
			loc[l].y = 0;
		}
	}
}