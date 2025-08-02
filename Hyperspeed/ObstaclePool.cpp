#include "ObstaclePool.h"

ObstaclePool::ObstaclePool(SDL_Renderer* renderer, ObstacleTextureManager* textureManager) : ObjectPool(renderer)
{
	m_Renderer = renderer;

	m_TextureManager = textureManager;

	InitialiseObjects();
}

ObstaclePool::~ObstaclePool()
{
	m_TextureManager = nullptr;
}

void ObstaclePool::InitialiseObjects()
{
	Obstacle* laneOneObstacle = new Obstacle(m_Renderer, "SmallMeteor", LANE_1, m_TextureManager);
	Obstacle* laneTwoObstacle = new Obstacle(m_Renderer, "SmallDetailedMeteor", LANE_2, m_TextureManager);
	Obstacle* laneThreeObstacle = new Obstacle(m_Renderer, "SmallMeteor", LANE_3, m_TextureManager);
	
	m_ObjectPool.push_back(laneOneObstacle);
	m_ObjectPool.push_back(laneTwoObstacle);
	m_ObjectPool.push_back(laneThreeObstacle);

}

