/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Snake.h"
#include "SnakeMy.h"
//#include "Target.h"
#include "Goal.h"
#include "Obstacle.h"
#define N 100

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

	/********************************/
	/*  User Functions              */
	//bool IsColiding(Snake& snek);
	bool IsSnakeInObstacle(Snake& snake, Obstacle& obstacle);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board board;
	Snake snek;
	//unsigned int green = 255;
	//Color segment_color = Colors::Green;
	Location delta_loc = { 1, 0 };
	std::mt19937 rng;		
	int count_obstacle = 0;
	//Obstacle obstacles[N];
	// allocating dynamic array 
	// of Size N using malloc() 
	Obstacle* obstacles = (Obstacle*)malloc(sizeof(Obstacle) * N);
	//double snekMovePreriod = 25.0; // default was 60 frames/moves per second; now is 60/25 = 2.5 moves per second

	int snek_move_period = 20;
	static constexpr int snek_move_period_min = 4;
	double acceleration = 0.7;
	int snekMoveCounter = 0;
	static constexpr int snek_speedup_period = 180;
	int snek_spedup_counter = 0;
	bool start_game = false;
	bool gameOver = false;
	//SnakeMy snkMy;	
	
	//Target target;
	Goal goal;
	// My var g.o.
	/*bool gameOver = false;*/
	/********************************/
};