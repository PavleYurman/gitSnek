#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{	
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{		
	std::uniform_int_distribution<int> newDistLocationX(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> newDistLocationY(0, brd.GetHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = newDistLocationX(rng);
		newLoc.y = newDistLocationY(rng);
	} while (snake.IsInTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	//brd.DrawCell(loc, c, false);
	brd.DrawCell(loc, c);
}

Location& Goal::GetLocation()
{
	return loc;
}
