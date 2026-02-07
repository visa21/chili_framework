#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
class Square
{
public:
	int x=255;
	int y=255;
	int width = 20;
	int height = 20;
	void Update(MainWindow& wnd);
	void Draw(Graphics& gfx);
	int Clamp(int var, int size, int dimension);
};

