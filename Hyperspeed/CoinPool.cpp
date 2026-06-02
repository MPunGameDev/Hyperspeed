#include "CoinPool.h"

CoinPool::CoinPool(SDL_Renderer* renderer, TextureManager* textureManager) : ObjectPool(renderer)
{
	m_Renderer = renderer;
	m_TextureManager = textureManager;
	InitialiseObjects();
}

CoinPool::~CoinPool()
{
	m_TextureManager = nullptr;
}

void CoinPool::InitialiseObjects()
{
	Texture2D* coinTexture = m_TextureManager->GetTextureByName("Coin");
	m_ObjectPool.push_back(new Coin(m_Renderer, coinTexture, LANE_1));
	m_ObjectPool.push_back(new Coin(m_Renderer, coinTexture, LANE_2));
	m_ObjectPool.push_back(new Coin(m_Renderer, coinTexture, LANE_3));
}
