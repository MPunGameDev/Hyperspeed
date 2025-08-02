#include "Collisions.h"
#include "GameObject.h"
#include "Texture2D.h"

Collisions* Collisions::m_Instance = nullptr;

Collisions* Collisions::Instance()
{
	if (!m_Instance)
	{
		m_Instance = new Collisions;
	}

	return m_Instance;
}

bool Collisions::Circle(GameObject* a, GameObject* b)
{
	Texture2D* aTexture = a->GetTexture();
	Texture2D* bTexture = b->GetTexture();

	int spriteAOffsetX = aTexture->GetHeight() / 2;
	int spriteBOffsetX = bTexture->GetHeight() / 2;

	int spriteAOffsetY = aTexture->GetWidth() / 2;
	int spriteBOffsetY = aTexture->GetWidth() / 2;

	Vector2D vec = Vector2D(((a->GetPosition().x + spriteAOffsetX)  - (b->GetPosition().x + spriteBOffsetX)), ((a->GetPosition().y + spriteAOffsetY) - (b->GetPosition().y)));

	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));

	double combinedDistance = (a->GetCollisionRadius() + b->GetCollisionRadius());

	return distance < combinedDistance;

	return false;
}

Collisions::Collisions()
{

}

Collisions::~Collisions()
{
	m_Instance = nullptr;
}

