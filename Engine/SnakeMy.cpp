//#include "SnakeMy.h"
//
//SnakeMy::SnakeMy(Graphics& gfx, Board& brd)
//	:
//	gfx(gfx),
//	brd(brd)
//{
//	int l = 0;
//	//for (int ln = 0; ln < snakeLenght; ln++) // continue
//	//{	
//		loc[0].x = 5;
//		loc[0].y = 3;
//		loc[1].x = 4;
//		loc[1].y = 3;
//		loc[2].x = 3;
//		loc[2].y = 3;
//		loc[3].x = 2;
//		loc[3].y = 3;
//
//		/*l++;*/
//	//}
//}
//
//
//
//void SnakeMy::Draw(Color c)
//{			
//	int l = 0;
//	while (l < countGrowth)
//	{
//		brd.DrawCell(loc[l], c, false);
//		l++;
//	}
//
//	
//}
//
//void SnakeMy::ChangeDirection(Keyboard& kbd)
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
//void SnakeMy::SetDirection(bool up, bool down, bool left, bool right)
//{
//	MoveUp = up;
//	MoveDown = down;
//	MoveLeft = left;
//	MoveRight = right;
//}
//
//void SnakeMy::MoveV1(Keyboard& kbd)
//{	
//	
//	if (kbd.KeyIsPressed(VK_UP))
//	{	
//		if (isPressedUP)
//		{
//	
//		}
//		else
//		{	
//			for (int i = 0; i < snakeLenght - 3; i++)
//			{		
//				loc[i + 3].x = loc[2].x;
//				loc[i + 3].y = loc[2].y;
//				loc[i + 2].x = loc[1].x;
//				loc[i + 2].y = loc[1].y;
//				loc[i + 1].x = loc[i].x;
//				loc[i + 1].y = loc[i].y;				
//			}
//			loc[0].y--;
//
//			isPressedUP = true;
//			/*countPressUp++;*/
//		}
//	}
//	else
//	{
//		isPressedUP = false;
//		SetDirection(true, false, false, false);
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
//			for (int i = 0; i < snakeLenght - 3; i++)
//			{
//				loc[i + 3].x = loc[2].x;
//				loc[i + 3].y = loc[2].y;
//				loc[i + 2].x = loc[1].x;
//				loc[i + 2].y = loc[1].y;
//				loc[i + 1].x = loc[i].x;
//				loc[i + 1].y = loc[i].y;
//			}
//			loc[0].y++;
//			isPressedDWN = true;		
//		}
//	}
//	else
//	{
//		isPressedDWN = false;
//		SetDirection(false, true, false, false);
//	}
//	if (kbd.KeyIsPressed(VK_LEFT))
//	{	
//		if (isPressedLT)
//		{
//	
//		}
//		else
//		{
//			for (int i = 0; i < snakeLenght - 3; i++)
//			{
//				loc[i + 3].x = loc[2].x;
//				loc[i + 3].y = loc[2].y;
//				loc[i + 2].x = loc[1].x;
//				loc[i + 2].y = loc[1].y;
//				loc[i + 1].x = loc[i].x;
//				loc[i + 1].y = loc[i].y;
//			}
//			loc[0].x--;
//			isPressedLT = true;			
//		}
//	}
//	else
//	{
//		isPressedLT = false;
//		SetDirection(false, false, true, false);
//	}
//	if (kbd.KeyIsPressed(VK_RIGHT))
//	{	
//		if (isPressedRT)
//		{
//	
//		}
//		else
//		{
//			for (int i = 0; i < snakeLenght - 3; i++)
//			{
//				loc[i + 3].x = loc[2].x;
//				loc[i + 3].y = loc[2].y;
//				loc[i + 2].x = loc[1].x;
//				loc[i + 2].y = loc[1].y;
//				loc[i + 1].x = loc[i].x;
//				loc[i + 1].y = loc[i].y;
//			}
//			loc[0].x++;
//			isPressedRT = true;
//		}
//	}
//	else
//	{
//		isPressedRT = false;
//		SetDirection(false, false, false, true);
//	}
//	
//	
//}
//
//void SnakeMy::Move(Keyboard& kbd)
//{
//	if (kbd.KeyIsPressed(VK_UP))
//	{
//		if (isPressedUP)
//		{
//
//		}
//		else
//		{
//			for (int i = 0; i < snakeLenght; i++)
//			{
//				loc[i].y--;
//			}
//			
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
//			for (int i = 0; i < snakeLenght; i++)
//			{
//				loc[i].y++;
//			}
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
//			for (int i = 0; i < snakeLenght; i++)
//			{
//				loc[i].x--;
//			}			
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
//			for (int i = 0; i < snakeLenght; i++)
//			{
//				loc[i].x++;
//			}			
//			isPressedRT = true;
//		}
//	}
//	else
//	{
//		isPressedRT = false;
//	}
//}
//
//void SnakeMy::ProcessMovement()
//{
//	interval++;
//	if (MoveRight)
//	{
//		if (interval == 30)
//		{
//			interval = 0;
//			for (int l = 0; l < snakeLenght; l++)
//			{
//				loc[l].x++;
//			}				
//		}
//	}
//	else if (MoveLeft)
//	{
//		if (interval == 30)
//		{			
//			interval = 0;
//			for (int l = 0; l < snakeLenght; l++)
//			{
//				loc[l].x--;
//			}
//		}
//	}
//	else if (MoveUp)
//	{
//		if (interval == 30)
//		{			
//			interval = 0;
//			for (int l = 0; l < snakeLenght; l++)
//			{
//				loc[l].y--;
//			}
//		}
//	}
//	else
//	{
//		if (interval == 30)
//		{			
//			interval = 0;
//			for (int l = 0; l < snakeLenght; l++)
//			{
//				loc[l].y++;
//			}
//		}
//	}
//
//
//}
//
//void SnakeMy::TransitionLocation()
//{
//	for (int l = 0; l < snakeLenght; l++)
//	{	
//		if (loc[l].x < 0)
//		{
//			loc[l].x = brd.GetWidth() - 1;
//		}
//		if (loc[l].x >= brd.GetWidth())
//		{
//			loc[l].x = 0;
//		}
//		if (loc[l].y < 0)
//		{
//			loc[l].y = brd.GetHeight() - 1;
//		}
//		if (loc[l].y >= brd.GetHeight())
//		{
//			loc[l].y = 0;
//		}
//	}
//}
//
//bool SnakeMy::TargetIsColected(Target& trgt)
//{
//	if (countGrowth >= snakeLenght)
//	{
//		countGrowth = countGrowth;
//		return false;
//	}
//	//if (loc[0] == trgt.GetLocation())
//	//{		
//	//	countGrowth += 1;		
//	//	loc[countGrowth - 1].confirmedLocation = true;		
//	//	return true;
//	//}
//	return false;
//}
//
//int SnakeMy::GetGrowth()
//{
//	return countGrowth;
//}
//
//int SnakeMy::GetLength()
//{
//	return snakeLenght;
//}
//
////bool SnakeMy::IsSelfColiding()
////{
////	if (loc[0] == loc[3] && loc[3].confirmedLocation == true)
////	{
////		return true;
////	}	
////
////	return false;
////}
//
//
//
////int SnakeMy::GetCountGrowth()
////{
////	return countGrowth;
////}
//
//int SnakeMy::SetCountGrowth(int growBy)
//{
//	return countGrowth += growBy;
//}


