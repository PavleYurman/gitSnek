#pragma once

#include "Goal.h"
//#include "Board.h"
//#include <random>


class Obstacle
{
public:
	Obstacle(std::mt19937& rng, Board& brd, Snake& snake, Goal& goal);
	//Obstacle() {};
	void GenerateLocation(std::mt19937& rng, const Board& brd, const Snake& snake, Goal& goal);
	//void Apear(std::mt19937& rng, const Board& brd, const Snake& snake, Goal& goal, Obstacle& obs);
	void Draw(Board& brd) const;
	const Location& GetLocation();
	bool LocIsTaken(Obstacle& obsticle) const;
private:
	static constexpr Color c = Colors::Gray;
	Location loc;

};
