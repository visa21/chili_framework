#include "Poo.h"
#include "Graphics.h"
#include <random>

void Poo::Initialize()
{
	std::random_device rd;

	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, 770);

	std::uniform_int_distribution<int> yDist(0, 570);
	x = xDist(rng);
	y = yDist(rng);
}

void Poo::Update()
{

	x += vx;
	y += vy;
	const int oldx = x;

	const int oldy = y;
	x = Clamp(x, Graphics::ScreenWidth);
	if (x != oldx)
	{
		vx = -vx;
	}

	y = Clamp(y, Graphics::ScreenHeight);
	if (y != oldy)
	{
		vy = -vy;
	}

}


int Poo::Clamp(int var, int size)
{
	const int right = var + height;
	if (var < 0)
	{
		return 0;
	}
	else if (right >= size)
	{
		return size - height - 1;
	}
	else
	{
		return var;
	}
	return 0;
}