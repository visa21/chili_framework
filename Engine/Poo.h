#pragma once
class Poo
{
public:
	void Update();
	int Clamp(int x,int size);
	void Initialize();
	static constexpr int width = 24;
	static constexpr int height = 24;
	int x;
	int y;
	bool IsEaten = false;
	int vx = 1;
	int vy = 1;
};

