#pragma once

#include "ObjectPool.h"
#include "Obstacle.h"

using namespace std;

class ObstaclePool : public ObjectPool
{
private:

	virtual void InitialiseObjects() override;
	ObstacleTextureManager* m_TextureManager;

public:

	ObstaclePool(SDL_Renderer* renderer, ObstacleTextureManager* textureManager);
	~ObstaclePool();

protected:


};

