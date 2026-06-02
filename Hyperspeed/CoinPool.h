#pragma once
#include "ObjectPool.h"
#include "Coin.h"
#include "TextureManager.h"

using namespace std;

class CoinPool : public ObjectPool
{
public:
	CoinPool(SDL_Renderer* renderer, TextureManager* textureManager);
	~CoinPool();

private:
	virtual void InitialiseObjects() override;
	TextureManager* m_TextureManager;
};
