#include "BackgroundTextureManager.h"

BackgroundTextureManager::BackgroundTextureManager(SDL_Renderer* renderer) : TextureManager(renderer)
{
	m_Renderer = renderer;
	InitialiseTextures();
}

BackgroundTextureManager::~BackgroundTextureManager()
{
}

void BackgroundTextureManager::InitialiseTextures()
{
	CreateTextureInMap("Environment/Background/", "MediumStar");
	CreateTextureInMap("Environment/Background/", "SmallStar");
	CreateTextureInMap("Environment/Background/", "MediumStarPurple");
	CreateTextureInMap("Environment/Background/", "SmallStarPurple");
	CreateTextureInMap("Environment/Background/", "TinyStarPurple");
	CreateTextureInMap("Environment/Background/", "SmallStarDull");

}
