#pragma once

#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include "GameObject.h"

using namespace std;

class ObjectPool
{
private:

	virtual void InitialiseObjects() = 0;

public:

	ObjectPool(SDL_Renderer* renderer);
	~ObjectPool();

	virtual vector<GameObject*>& GetPool() { return m_ObjectPool; }

	virtual void Update(float deltaTime, SDL_Event e);
	virtual void Render();

protected:
	SDL_Renderer* m_Renderer;

	vector<GameObject*> m_ObjectPool;
};

