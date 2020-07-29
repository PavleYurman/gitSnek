#pragma once
#include "Board.h"
//#include "Keyboard.h"
//#include <random>
//#include "Target.h"
//#include "Obstacle.h"

class Snake {

private:
	class Segment	// continue at 25:17
	{
	public:
		void InitHead(const Location& loc);		
		void MoveBy(const Location& delta_loc);
		void InitBody(Color c);
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
		//void Transit(Board& brd);
		//bool IsTargetColected(Target& tg);
		//Location GetLocation();
	private:
		Location loc;
		Color c;		
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	//void MoveBy(const Location& delta_loc, Board& brd);
	void Grow(Color color);
	void Grow();
	void Draw(Board& brd);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;
	/*bool IsOntheBoardMy(const Location& delta_loc, const Board& brd);*/
	// My methods----------
	//void ProcessInputDirection(const Keyboard& kbd);
	//void SetDirection(bool up, bool down, bool left, bool right);
	//void GenerateMovement(Board& brd);
	//bool HasEaten(Target& tg);
	//bool SelfColision();
private:
	static constexpr Color headColor = Colors::Yellow;
	//static constexpr Color bodyColor = Colors::Green;	
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];	
	int nSegments = 1;
	// My variables--------------
	//bool MoveUp = false;
	//bool MoveDown = false;
	//bool MoveLeft = false;
	//bool MoveRight = true;
	//int interval = 0;
};

