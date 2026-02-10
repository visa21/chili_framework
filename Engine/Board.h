#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics& gfx);
	void Draw_Cell(const Location& loc, Color c);
	int Get_Grid_W();
	int Get_Grid_H();
	bool isInsideBoard(const Location& loc);
private:
	static constexpr int width = 10;
	static constexpr int height = 10;
	static constexpr int dimension = 20;
	Graphics& gfx;
};

