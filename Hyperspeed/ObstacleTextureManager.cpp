#include "ObstacleTextureManager.h"

ObstacleTextureManager::ObstacleTextureManager(SDL_Renderer* renderer) : TextureManager(renderer)
{
	m_Renderer = renderer;
	InitialiseTextures();
}

ObstacleTextureManager::~ObstacleTextureManager()
{
}

void ObstacleTextureManager::InitialiseTextures()
{
	CreateTextureInMap("Environment/Obstacles/", "SmallMeteor");
	CreateTextureInMap("Environment/Obstacles/", "SmallDetailedMeteor");
	CreateTextureInMap("Environment/Obstacles/", "SmallSquareMeteor");
	CreateTextureInMap("Environment/Obstacles/", "SmallDetailedSquareMeteor");
	CreateTextureInMap("Environment/Obstacles/", "LargeMeteor");
	CreateTextureInMap("Environment/Obstacles/", "LargeDetailedMeteor");
	CreateTextureInMap("Environment/Obstacles/", "LargeSquareMeteor");
	CreateTextureInMap("Environment/Obstacles/", "LargeDetailedSquareMeteor");
	CreateTextureInMap("Environment/Obstacles/", "SmallMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "SmallDetailedMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "SmallSquareMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "SmallDetailedSquareMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "LargeMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "LargeDetailedMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "LargeSquareMeteorBlue");
	CreateTextureInMap("Environment/Obstacles/", "LargeDetailedSquareMeteorBlue");
}

