#pragma once
#include "Graphics.h"
#include "Snake.h"
#include "Board.h"
#include <random>
class Goal
{
public:
	Goal(std::mt19937_64& rng, const Board& brd, const Snake& snek );
	void Draw(Board& brd) const;
	void Respawn(std::mt19937_64& rng, const Board&, const Snake& snek);
	Location GetLocation() const;

private:
	Location loc;
	Color c = Colors::Red;


};

