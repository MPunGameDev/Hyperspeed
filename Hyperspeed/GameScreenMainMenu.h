#pragma once

#include "GameScreen.h"
#include "Commons.h"

#include "Character.h"
#include "StarBackgroundPool.h"
#include "GameText.h"
#include "UIObject.h"
#include "UITextureManager.h"
#include "Audio.h"

class GameScreenMainMenu : public GameScreen
{
public:

	GameScreenMainMenu(SDL_Renderer* renderer, GameScreenManager* manager);
	~GameScreenMainMenu();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:

	Character* m_Character = nullptr;

	StarBackgroundPool* m_StarBackgroundPool0 = nullptr;
	StarBackgroundPool* m_StarBackgroundPool1 = nullptr;
	StarBackgroundPool* m_StarBackgroundPool2 = nullptr;
	TextureManager* m_BackgroundTextureManager = nullptr;

	GameText* m_Title = nullptr;
	GameText* m_ControlsTitle = nullptr;
	GameText* m_MoveLeft = nullptr;
	GameText* m_MoveRight = nullptr;
	GameText* m_InsertCoin = nullptr;

	UIObject* m_LeftIcon = nullptr;
	UIObject* m_RightIcon = nullptr;
	UIObject* m_LeftIconKB = nullptr;
	UIObject* m_RightIconKB = nullptr;
	UIObject* m_Coin = nullptr;

	TextureManager* m_UITextureManager = nullptr;

	Audio* m_BackgroundMusic = nullptr;
};
