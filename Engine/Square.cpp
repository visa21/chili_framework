#include "Square.h"
void Square::Draw(Graphics& gfx)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			gfx.PutPixel(x+i, y+j, 255, 255, 255);
		}
	}
}

int Square::Clamp(int var, int size, int dimension)
{
	const int right = var + dimension;
	if (var < 1)
	{
		return 1;
	}
	else if (right >= size)
	{
		return size - dimension - 2;
	}
	else
		return var;
	//return 0;
}

void Square::Update(MainWindow& wnd)
{
	x = Clamp(x, Graphics::ScreenWidth, width);
	y = Clamp(y, Graphics::ScreenHeight, height);
	width = Clamp(width, Graphics::ScreenWidth, width);
	height = Clamp(height, Graphics::ScreenHeight, height);
	if (wnd.kbd.KeyIsPressed('A'))
	{
		x--;
	}

	if (wnd.kbd.KeyIsPressed('W'))
	{
		y++;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		y--;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		x++;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		width--;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		height++;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		height--;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		width++;
	}
}