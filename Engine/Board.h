#pragma once
#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx, int start_x, int start_y);
	void DrawBoard();
	void DrawBorder();
	void DrawCell(const Location& loc, Color c, bool has_border);	
	void DrawCell(const Location& loc, Color c);	
	int GetWidth() const;
	int GetHeight() const;
	bool isInsideBoard(const Location& loc) const;
	void SetDrawPosition(Graphics& gfx, Location& loc, int x, int y);
private:
	static constexpr int cell_padding = 1;
	static constexpr Color border_color = Colors::Blue;
	static constexpr int dimension = 15;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int x = 150;
	static constexpr int y = 50;
	static constexpr int border_width = 4;
	static constexpr int border_padding = 2;

	Graphics& gfx;
public:
	int starting_x;
	int starting_y;
	bool has_border = false;
};