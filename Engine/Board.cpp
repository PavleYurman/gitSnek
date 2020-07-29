#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx, int start_x, int start_y)
	:
	gfx(gfx)
{
	assert(start_x >= 0 && start_x < gfx.ScreenWidth - width * dimension);
	assert(start_y >= 0 && start_y < gfx.ScreenHeight - height * dimension);
	starting_x = start_x;
	starting_y = start_y;
}

void Board::DrawBoard()
{
	for (int y = 0; y < GetHeight(); y++)
	{
		for (int x = 0; x < GetWidth(); x++)
		{
			Color c = Colors::Black;
			Location loc;
			loc.y = y;
			loc.x = x;
			if ((x < 1 || x > GetWidth() - 2) || (y < 1 || y > GetHeight() - 2))
			{
				c = Colors::Blue;
			}
			//DrawCell(loc, c, false);
			DrawCell(loc, c);
		}
	}
}
// The idea Chilli had was to compose the border from 4 rectangles: up, down, left right
void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + 2 * (border_padding + border_width) + height * dimension;
	const int right = left + 2 * (border_padding + border_width) + width * dimension;
	// top rect
	gfx.DrawRect(left, top, right, top + border_width, border_color);
	// bottom rect
	gfx.DrawRect(left, bottom - border_width, right, bottom, border_color);
	// left rect
	gfx.DrawRect(left, top + border_width, left + border_width, bottom - border_width, border_color);
	// right rect
	gfx.DrawRect(right - border_width, top + border_width, right, bottom - border_width, border_color);
}

// ignore
void Board::DrawCell(const Location& loc, Color c, bool has_border)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension + starting_x, loc.y * dimension + starting_y, dimension, dimension, c, has_border);
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x + border_width + border_padding;
	const int off_y = y + border_width + border_padding;

	gfx.DrawRectDim(loc.x * dimension + off_x + cell_padding, loc.y * dimension + off_y + cell_padding,
		dimension - 2 * cell_padding, dimension - 2 * cell_padding, c, has_border);
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

bool Board::isInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		   loc.y >= 0 && loc.y < height;
}

void Board::SetDrawPosition(Graphics& gfx, Location& loc, int x, int y)
{

}

