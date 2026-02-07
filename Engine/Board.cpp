#include "Board.h"

Board::Board(Graphics& gfx) : gfx(gfx)
{
}

void Board::Draw_Cell(const Location& loc, Color c)
{
	gfx.DrawRect(loc.x * dimension, loc.y * dimension, width, height, c);
}

int Board::Get_Grid_W()
{
	return width;
}

int Board::Get_Grid_H()
{
	return height;
}
