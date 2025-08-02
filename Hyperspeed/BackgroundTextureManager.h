#pragma once
#include "TextureManager.h"
class BackgroundTextureManager : public TextureManager
{
public:

	BackgroundTextureManager(SDL_Renderer* renderer);
	~BackgroundTextureManager();

private:

	virtual void InitialiseTextures() override;
};

