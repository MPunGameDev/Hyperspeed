#pragma once

#include <SDL.h>
#include <iostream>
#include "Commons.h"

using namespace std;

class Texture2D;

class GameObject
{
protected:

	SDL_Renderer* m_Renderer = nullptr;
	Vector2D m_Position;
	Texture2D* m_Texture = nullptr;
	float m_CollisionRadius;
	int m_Speed = 0;

public:

	GameObject(SDL_Renderer* renderer, string imagePath, Vector2D startPosition);
	GameObject(int doNothing) {}
	~GameObject();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D newPosition);
	virtual void SetSpeed(int speed) = 0;
	Vector2D GetPosition();
	Texture2D* GetTexture() { return m_Texture; }
	float GetCollisionRadius() { return m_CollisionRadius; }

};

