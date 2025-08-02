#include "ObjectPool.h"

ObjectPool::ObjectPool(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

ObjectPool::~ObjectPool()
{
	std::vector<GameObject*>::iterator itr;

	for (itr = m_ObjectPool.begin(); itr != m_ObjectPool.end(); ++itr)
	{
		delete* itr;
		*itr = nullptr;
	}

	m_ObjectPool.clear();
}

void ObjectPool::Update(float deltaTime, SDL_Event e)
{
	std::vector<GameObject*>::iterator itr;

	for (itr = m_ObjectPool.begin(); itr != m_ObjectPool.end(); ++itr)
	{
		(*itr)->Update(deltaTime, e);
	}
}

void ObjectPool::Render()
{
	std::vector<GameObject*>::iterator itr;

	for (itr = m_ObjectPool.begin(); itr != m_ObjectPool.end(); ++itr)
	{
		(*itr)->Render();
	}
}