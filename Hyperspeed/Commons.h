#pragma once

struct Vector2D
{
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float initial_x, float initial_y)
	{
		x = initial_x;
		y = initial_y;
	}

	bool operator==(Vector2D comparedValue) const
	{
		return (x == comparedValue.x && y == comparedValue.y);
	}

};

struct Rect2D
{

	float x;
	float y;
	float width;
	float height;

	Rect2D(float xPos, float yPos, float width, float height)
	{
		x = xPos;
		y = yPos;
		this->width = width;
		this->height = height;

	}
};

enum SCREENS
{
	SCREEN_MAINMENU,
	SCREEN_DEATHSCREEN,
	SCREEN_LEVEL1
};

enum FACING
{
	FACING_LEFT,
	FACING_RIGHT,
	FACING_UP,
};

enum LANES 
{
	LANE_1,
	LANE_2,
	LANE_3
};