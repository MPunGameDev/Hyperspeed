#include "StarBackgroundPool.h"

StarBackgroundPool::StarBackgroundPool(SDL_Renderer* renderer, TextureManager* textureManager, int numOfStars, int speedOfStars) : ObjectPool(renderer)
{
	m_Renderer = renderer;
	m_TextureManager = textureManager;
	m_NumOfStars = numOfStars;
	m_SpeedOfStars = speedOfStars;

	InitialiseObjects();
}

StarBackgroundPool::~StarBackgroundPool()
{
	m_TextureManager = nullptr;
}

void StarBackgroundPool::InitialiseObjects()
{
	for (int i = 0; i < m_NumOfStars; i++)
	{
		EnvironmentObject* star = new EnvironmentObject(m_Renderer, m_TextureManager->GetRandomName(), Vector2D(random(0, SCREEN_WIDTH), random(-SCREEN_HEIGHT, SCREEN_HEIGHT)), m_TextureManager);
		star->SetSpeed(m_SpeedOfStars);
		m_ObjectPool.push_back(star);

		star = nullptr;
	}

}

void StarBackgroundPool::SetStarPoolSpeed(int speed)
{
	m_SpeedOfStars = speed;

	for (int i = 0; i < m_NumOfStars; i++)
	{
		m_ObjectPool[i]->SetSpeed(speed);
	}
}
