#include "UITextureManager.h"

UITextureManager::UITextureManager(SDL_Renderer* renderer) : TextureManager(renderer)
{
	m_Renderer = renderer;
	InitialiseTextures();
}

UITextureManager::~UITextureManager()
{
}

void UITextureManager::InitialiseTextures()
{
	CreateTextureInMap("UI/", "MoveLeft");
	CreateTextureInMap("UI/", "MoveRight");
	CreateTextureInMap("UI/", "MoveLeftKB");
	CreateTextureInMap("UI/", "MoveRightKB");
	CreateTextureInMap("UI/", "Coin");
	CreateTextureInMap("UI/", "PlayerBroken");
}
