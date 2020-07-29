//#pragma once
//#include "Location.h"
//#include "Graphics.h"
//#include "Board.h"
//#include "MainWindow.h"
//#include "Target.h"
//
//class SnakeMy {
//public:
//	SnakeMy(Graphics& gfx, Board& brd);
//	void Draw(Color c);
//	void ChangeDirection(Keyboard& kbd);
//	void SetDirection(bool up, bool down, bool left, bool right);
//	void Move(Keyboard& kbd);
//	void SnakeMy::MoveV1(Keyboard& kbd);
//	void ProcessMovement();
//	void TransitionLocation();
//	bool TargetIsColected(Target& trgt);
//	int GetGrowth();
//	int GetLength();
//	//bool IsSelfColiding();
//	static constexpr int snakeLenght = 4;
//	Location loc[snakeLenght];
//	//int SetCountGrowth(int growBy);
//private:	
//	Graphics& gfx;
//	Board& brd;
//	bool isPressedUP = false;
//	bool isPressedDWN = false;
//	bool isPressedLT = false;
//	bool isPressedRT = false;
//	int interval = 0;
//	bool MoveLeft = true;
//	bool MoveRight = false;
//	bool MoveUp = false;
//	bool MoveDown = false;	
//	int countGrowth = 1;
//	int countPressUp = 0;
//	int countPressDown = 0;
//	int countPressLeft = 0;
//	int countPressRight = 0;
//	bool changeDirection = false;
//	bool snekDys = false;
//};