#include "Target.h"

Target::Target(Graphics& gfx, Board& brd)
	:
	gfx(gfx),
	brd(brd)
{	
	GenerateLocation();
}

void Target::Draw(Color c)
{
	brd.DrawCell(loc, c, false);

}

void Target::GenerateLocation()
{
	std::random_device rd;
	std::mt19937 rng(rd());	
	std::uniform_int_distribution<int> distLocationX(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> distLocationY(0, brd.GetHeight() - 1);
	loc.x = distLocationX(rng);
	loc.y = distLocationY(rng);
}

Location Target::GetLocation()
{
	return loc;
}


//void Target::ChangeDirection(Keyboard& kbd)
//{
//	if (kbd.KeyIsPressed(VK_UP))
//	{
//		SetDirection(true, false, false, false);
//	}
//	if (kbd.KeyIsPressed(VK_DOWN))
//	{
//		SetDirection(false, true, false, false);
//	}
//	if (kbd.KeyIsPressed(VK_LEFT))
//	{
//		SetDirection(false, false, true, false);
//	}
//	if (kbd.KeyIsPressed(VK_RIGHT))
//	{
//		SetDirection(false, false, false, true);
//	}
//
//}
//
//void Target::SetDirection(bool up, bool down, bool left, bool right)
//{
//	MoveUp = up;
//	MoveDown = down;
//	MoveLeft = left;
//	MoveRight = right;
//}
//
//void Target::Move(Keyboard& kbd)
//{
//	if (kbd.KeyIsPressed(VK_UP))
//	{
//		if (isPressedUP)
//		{
//			
//		}
//		else
//		{
//			loc.y--;
//			isPressedUP = true;
//		}
//	}
//	else
//	{
//		isPressedUP = false;
//	}
//
//	if (kbd.KeyIsPressed(VK_DOWN))
//	{
//		if (isPressedDWN)
//		{
//
//		}
//		else
//		{
//			loc.y++;
//			isPressedDWN = true;
//		}		
//	}
//	else
//	{
//		isPressedDWN = false;
//	}
//	if (kbd.KeyIsPressed(VK_LEFT))
//	{
//		if (isPressedLT)
//		{
//
//		}
//		else
//		{
//			loc.x--;
//			isPressedLT = true;
//		}		
//	}
//	else
//	{
//		isPressedLT = false;
//	}
//	if (kbd.KeyIsPressed(VK_RIGHT))
//	{
//		if (isPressedRT)
//		{
//
//		}
//		else
//		{
//			loc.x++;;
//			isPressedRT = true;
//		}		
//	}
//	else
//	{
//		isPressedRT = false;
//	}
//}
//
//void Target::ProcessMovement()
//{
//	interval++;
//	if (MoveRight)
//	{
//		if (interval == 30)
//		{
//			loc.x++;
//			interval = 0;
//		}
//	}
//	else if (MoveLeft)
//	{
//		if (interval == 30)
//		{
//			loc.x--;
//			interval = 0;
//		}
//	}
//	else if (MoveUp)
//	{
//		if (interval == 30)
//		{
//			loc.y--;
//			interval = 0;
//		}
//	}
//	else
//	{
//		if (interval == 30)
//		{
//			loc.y++;
//			interval = 0;
//		}
//	}
//	
//
//}
//
//void Target::TransitionLocation()
//{
//	if (loc.x < 0)
//	{
//		loc.x = brd.GetWidth() - 1;
//	}
//	if (loc.x >= brd.GetWidth())
//	{
//		loc.x = 0;
//	}
//	if (loc.y < 0)
//	{
//		loc.y = brd.GetHeight() - 1;
//	}
//	if (loc.y >= brd.GetHeight())
//	{
//		loc.y = 0;
//	}
//
//}


