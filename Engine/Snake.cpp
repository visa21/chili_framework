
#include "Snake.h"


Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::Moveby(const Location& next)
{
	for (int i = num_segments; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].Move_By(next);
}

void Snake::Grow()
{
	if (num_segments < segments_max) {
		segments[num_segments].InitBody();
		num_segments++;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < num_segments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::snakeNextHeadLocation(const Location& next) const
{
	Location ret = segments[0].GetLocation();
	return { ret.x + next.x,ret.y + next.y };
}

bool Snake::IllegalLocation(const Location& next) const
{
	for (int i = 0; i < num_segments-1; i++)
	{
		if (segments[i].GetLocation() == next)
			return true;
	}
	return false;
}


void Snake::Segment::InitHead(const Location& head) 
{
	loc = head;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::tailColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Move_By(const Location& next)
{
	assert((abs(next.x) + abs(next.y)) == 1);
	loc.x += next.x;
	loc.y += next.y;
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.Draw_Cell(loc, c);
}

Location Snake::Segment::GetLocation() const
{
	return loc;
}
