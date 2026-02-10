#pragma once
#include "Board.h"
#include <cassert>
class Snake
{
public:
	Snake(const Location&);
	void Moveby(const Location&);
	void Grow();
	void Draw(Board&) const;
	Location snakeNextHeadLocation(const Location& next) const;
	bool IllegalLocation(const Location& next) const;
private:
	class Segment
	{
	public:
		void InitHead(const Location&);
		void InitBody();
		void Follow(const Segment&);
		void Move_By(const Location&);
		void Draw(Board&) const;
		Location GetLocation() const;
	private:
		Location loc;
		Color c;
	};
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color tailColor = Colors::Green;
	static constexpr int segments_max = 100;
	int num_segments = 1;
	Segment segments[segments_max];

};

