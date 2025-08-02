#pragma once
#include "TextureManager.h"

class UITextureManager : public TextureManager
{
public:

	UITextureManager(SDL_Renderer* renderer);
	~UITextureManager();

private:

	virtual void InitialiseTextures() override;
};

