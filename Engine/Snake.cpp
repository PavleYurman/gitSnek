#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	constexpr int nColors = 4;
	constexpr Color collors[nColors] = {
		{10, 100, 32},
		{10, 130, 48},
		{18, 160, 48},
		{10, 130, 48}
	};	
	for (int i = 1; i < nSegmentsMax; i++)
	{
		segments[i].InitBody(collors[i % nColors]); // continue at 28:20

	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

//My modified impl:
//void Snake::MoveBy(const Location& delta_loc, Board& brd)
//{
//	for (int i = nSegments; i > 0; --i)
//	{
//		segments[i].Follow(segments[i - 1]);
//	}
//	segments[0].MoveBy(delta_loc); // continue at 37:30
//	segments[0].Transit(brd);
//}

void Snake::Grow(Color color)  // continue video at: 7:40...
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody(color);
		++nSegments;	
	}
}

void Snake::Grow() 
{
	if (nSegments < nSegmentsMax)
	{		
		++nSegments;	
	}
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}

}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation()); // this is a COPY CONSTRUCTOR
	l.Add(delta_loc);
	return l;
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}

bool Snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}

	return false;
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}

	return false;
}





//bool Snake::IsOntheBoardMy(const Location& delta_loc, const Board& brd)
//{
//	Location locHead = GetNextHeadLocation(delta_loc);
//
//	return brd.isInsideBoard(locHead);
//}

//void Snake::SetDirection(bool up, bool down, bool left, bool right)
//{
//	MoveUp = up;
//	MoveDown = down;
//	MoveLeft = left;
//	MoveRight = right;
//}



//void Snake::ProcessInputDirection(const Keyboard& kbd)
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
//}

//void Snake::GenerateMovement(Board& brd)
//{	
//	Location delta_loc;
//	if (MoveUp)
//	{
//		delta_loc.y = -1;
//		delta_loc.x = 0;
//	}
//	if (MoveDown)
//	{
//		delta_loc.y = 1;
//		delta_loc.x = 0;
//	}
//	if (MoveLeft)
//	{
//		delta_loc.y = 0;
//		delta_loc.x = -1;
//	}
//	if(MoveRight)
//	{
//		delta_loc.y = 0;
//		delta_loc.x = 1;
//	}
//	interval++;
//	if (interval == 30)
//	{
//		MoveBy(delta_loc, brd);
//		interval = 0;
//	}
//	
//}

//bool Snake::HasEaten(Target& tg)
//{
//	return segments[0].IsTargetColected(tg);
//}

// My ver. to do
//void Snake::MoveByMy(const Location& delta_loc)
//{
//	for (size_t i = 1; i < nSegments; i++)
//	{
//		segments[i].loc = segments[i - 1].loc;
//	}
//	segments[0].loc = delta_loc;
//}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	//c = headColor;
	c = Snake::headColor;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	// validate delta_loc
	//assert(delta_loc.x == loc.x + 1 || delta_loc.x == loc.x - 1);
	//assert(delta_loc.y == loc.y + 1 || delta_loc.y == loc.y  - 1);
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);

	loc.Add(delta_loc);
}

void Snake::Segment::InitBody(Color color)
{	
	c = color;

}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& brd) const
{
	/*brd.DrawCell(loc, c, true);*/
	brd.DrawCell(loc, c);
}



//void Snake::Segment::Transit(Board& brd)
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
//}

//bool Snake::Segment::IsTargetColected(Target& tg)
//{
//	return loc == tg.GetLocation();
//}

//Location Snake::Segment::GetLocation()
//{
//	return loc;
//}

//bool Snake::SelfColision()
//{
//	for (int i = nSegments - 1; i > 0; --i)
//	{
//		if (segments[0].GetLocation() == segments[i].GetLocation())
//		{
//			return true;
//		}		
//	}
//	return false;
//}



