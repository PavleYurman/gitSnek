/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
//#include "Board.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(gfx, 150, 50),
	rng(std::random_device()()),	
	snek({3, 3}),		
	goal(rng, board, snek)
{	
	// some code change
	 //initialize all obstacles with unique location
	for (int i = 0; i < N; i++)
	{		
		obstacles[i].GenerateLocation(rng, board, snek, goal);
		 //check if the location of obstacle i is the same as already generated obstacle j; if so generate new location for i
		for (int j = 0; j < i; j++)
		{
			while (obstacles[i].GetLocation() == obstacles[j].GetLocation())
			{
				obstacles[i].GenerateLocation(rng, board, snek, goal);
			}
		}
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

//void Game::UpdateModel()
//{		
//	//if (snkMy.GetTargetColected())
//	//{
//	//	//snkMy.SetCountGrowth(1);
//	//	tg.GenerateLocation();
//	//	snkMy.Update();
//	//	snkMy.SetTargetColected(false);
//	//	
//	//}
//	/*snkMy.ProcessMovement();*/
//	//snkMy.ChangeDirection(wnd.kbd);
//	if (snkMy.IsSelfColiding()) // does not work
//	{
//
//	}
//	else
//	{
//		snkMy.MoveV1(wnd.kbd);
//		snkMy.TransitionLocation();
//		if (snkMy.TargetIsColected(tg))
//		{
//			tg.GenerateLocation();
//		}
//	}
//
//		
//}

void Game::UpdateModel()
{
	if (start_game)
	{
		if (!gameOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0, -1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0, 1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1, 0 };
			}

			++snekMoveCounter;
			if (snekMoveCounter >= snek_move_period)
			{
				snekMoveCounter = 0;
				const Location headLoc = snek.GetNextHeadLocation(delta_loc);
				for (int i = 0; i < count_obstacle; i++)
				{
					if (IsSnakeInObstacle(snek, obstacles[i]))
					{
						gameOver = true;
					}
				}
				if (!board.isInsideBoard(headLoc) || snek.IsInTileExceptEnd(headLoc))
				{
					gameOver = true;
				}
				else
				{
					const bool eating = headLoc == goal.GetLocation();
					if (eating)
					{
						snek.Grow();
						++count_obstacle;
						//snekMovePreriod -= acceleration;
						//if (snekMovePreriod == 15.0 || snekMovePreriod == 10.0)
						//{
						//	acceleration -= 0.15;
						//}
						//if (snekMovePreriod <= 5)
						//{
						//	acceleration = 0.05;
						//}
						//green -=5;
						//segment_color = Color(0, green, 0);
						//if (green < 5)
						//{
						//	green = 255;
						//}
					}
					snek.MoveBy(delta_loc);
					if (eating)
					{
						goal.Respawn(rng, board, snek);
					}

				}

			}
			++snek_spedup_counter;
			if (snek_spedup_counter >= snek_speedup_period)
			{
				snek_spedup_counter = 0;
				snek_move_period = std::max(snek_move_period - 1, snek_move_period_min);	
			}
		} // if game over: do not update the data
	}
	else
	{		
		start_game = wnd.kbd.KeyIsPressed(VK_RETURN);		
	}

	
	
	

	// My logic
	//if (!gameOver)
	//{
	//	snake.GenerateMovement(board);
	//	snake.ProcessInputDirection(wnd.kbd);		
	//	if (snake.HasEaten(target))
	//	{
	//		target.GenerateLocation();
	//		snake.Grow();
	//	}
	//	if (snake.SelfColision())
	//	{
	//		gameOver = true;
	//	}
	//}
	//else
	//{	}	
}

void Game::ComposeFrame()
{
	if (start_game)
	{
		goal.Draw(board);
		if (gameOver || count_obstacle >= N)
		{
			SpriteCodex::DrawGameOver(350, 265, gfx);
		}
		else
		{
			for (int i = 0; i < count_obstacle; i++)
			{
				obstacles[i].Draw(board);
			}
		}
		snek.Draw(board);
		//board.DrawBoard();
		board.DrawBorder();
	}
	else
	{
		SpriteCodex::DrawTitle(290, 225, gfx);
	}

	//Test code
	//std::uniform_int_distribution<int> distCol;
	//for (int y = 0; y < board.GetHeight(); y++)  
	//{
	//	for (int x = 0; x < board.GetWidth(); x++)
	//	{			
	//		Location loc{x, y}; // struct initialization; us {} when all members are public // {} can bi used also for
	//		//Color c(distCol(rng), distCol(rng), distCol(rng));							// constructors			
	//		Color c(255, 255, 255);
	//		board.DrawCell(loc, c); // continue at 15:20
	//	}
	//}	
	//target.Draw(Colors::Blue);
	//snake.Draw(board);		
}

bool Game::IsSnakeInObstacle(Snake& snake, Obstacle& obstacle)
{
	return snake.GetNextHeadLocation(delta_loc) == obstacle.GetLocation();
}

//bool Game::IsColiding(Snake& snek)
//{
//	for (int i = 0; i < count_obstacle; i++)
//	{
//		if (snek.IsInObstacle(obstacles[i]))
//		{
//			return true;
//		}
//	}
//
//	return false;
//}

