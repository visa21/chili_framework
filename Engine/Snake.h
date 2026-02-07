#pragma once
#include "Board.h"
class Snake
{
public:
	Snake(const Location&);
	void Moveby(const Location&);
	void Grow();
	void Draw(const Board&) const;
private:
	class Segment
	{
		
		void InitHead(const Location&);
		void Init_Body();
		void Follow(const Segment&);
		void Move_By(const Location&);
		void Draw(const Board&) const;
	private:
		Location loc;
		Color c;
	};
	static constexpr int segments_max = 100;
	int num_segments = 1;
	Segment segments[segments_max];

};

