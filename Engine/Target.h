#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Board.h"
#include "MainWindow.h"
#include <random>

class Target {
public:
	Target(Graphics& gfx, Board& brd);
	void Draw(Color c);
	void GenerateLocation();
	Location GetLocation();
	//------not needed methods-----------------
	//void ChangeDirection(Keyboard& kbd);
	//void SetDirection(bool up, bool down, bool left, bool right);
	//void Move(Keyboard& kbd);
	//void ProcessMovement();
	//void TransitionLocation();
private:
	Location loc;
	bool updateLoc = false;
	Graphics& gfx;
	Board& brd;
	//bool isPressedUP = false;
	//bool isPressedDWN = false;
	//bool isPressedLT = false;
	//bool isPressedRT = false;
	//int interval = 0;
	//bool MoveLeft = true;
	//bool MoveRight = false;
	//bool MoveUp = false;
	//bool MoveDown = false;

};