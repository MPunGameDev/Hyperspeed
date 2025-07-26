#pragma once

#include "Commons.h"

class GameObject;
class Texture2D;

class Collisions
{
public:

	static Collisions* Instance();

	bool Circle(GameObject* a, GameObject* b);

private:

	Collisions();
	~Collisions();

	static Collisions* m_Instance;
};

