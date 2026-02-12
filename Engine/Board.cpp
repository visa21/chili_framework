#include "Board.h"

Board::Board(Graphics& gfx) : gfx(gfx)
{
}

void Board::Draw_Cell(const Location& loc, Color c)
{
	gfx.DrawRect(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::Get_Grid_W() const
{
	return width;
}

int Board::Get_Grid_H() const
{
	return height;
}

bool Board::isInsideBoard(const Location& loc)
{
	return loc.x < 0 ? false : loc.x > width ? false : loc.y > height ? false : loc.y < 0 ? false : true;
}
