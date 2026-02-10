#pragma once
struct Location
{
	bool operator== (const Location& other) {
		return x == other.x && y == other.y;
	}
	int x, y;
};