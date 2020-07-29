#include "Obstacle.h"

Obstacle::Obstacle(std::mt19937& rng, Board& brd, Snake& snake, Goal& goal)
{
	GenerateLocation(rng, brd, snake, goal);
}

//Obstacle::Obstacle() {}

void Obstacle::GenerateLocation(std::mt19937& rng, const Board& brd, const Snake& snake, Goal& goal)
{
	std::uniform_int_distribution<int> newDistLocationX(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> newDistLocationY(0, brd.GetHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = newDistLocationX(rng);
		newLoc.y = newDistLocationY(rng);		
	} while (snake.IsInTile(newLoc) || goal.GetLocation() == loc);

	loc = newLoc;
}

//void Obstacle::Apear(std::mt19937& rng, const Board& brd, const Snake& snake, Goal& goal, Obstacle& obs)
//{
//	std::uniform_int_distribution<int> newDistLocationX(0, brd.GetWidth() - 1);
//	std::uniform_int_distribution<int> newDistLocationY(0, brd.GetHeight() - 1);
//
//	Location newLoc;
//	do
//	{
//		newLoc.x = newDistLocationX(rng);
//		newLoc.y = newDistLocationY(rng);
//	} while (snake.IsInTile(newLoc) || newLoc == goal.GetLocation() || LocIsTaken(obs));
//
//	loc = newLoc;
//}

void Obstacle::Draw(Board& brd) const
{
	//brd.DrawCell(loc, c, false);
	brd.DrawCell(loc, c);
}

const Location& Obstacle::GetLocation()
{
	return loc;
}

bool Obstacle::LocIsTaken(Obstacle& new_obstacle) const
{
	if (loc == new_obstacle.GetLocation())
	{
		return true;
	}

	return false;
}
