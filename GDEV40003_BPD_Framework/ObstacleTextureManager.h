#pragma once

#include "TextureManager.h"

class ObstacleTextureManager : public TextureManager
{
public:

	ObstacleTextureManager(SDL_Renderer* renderer);
	~ObstacleTextureManager();

private:

	virtual void InitialiseTextures() override;

protected:



};

