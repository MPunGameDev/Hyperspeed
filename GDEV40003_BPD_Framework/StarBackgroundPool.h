#pragma once

#include "MathsHelper.h"
#include "Constants.h"
#include "ObjectPool.h"
#include "BackgroundTextureManager.h"
#include "EnvironmentObject.h"

class StarBackgroundPool : public ObjectPool
{
private:

	virtual void InitialiseObjects() override;
	TextureManager* m_TextureManager = nullptr;


	int m_NumOfStars;
	int m_SpeedOfStars;

public:

	void SetStarPoolSpeed(int speed);
	StarBackgroundPool(SDL_Renderer* renderer, TextureManager* textureManager, int numOfStars, int speedOfStars);
	~StarBackgroundPool();
};

