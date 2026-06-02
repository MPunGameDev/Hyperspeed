#pragma once

#include "GameScreen.h"
#include "Commons.h"

#include "Character.h"
#include "ObstaclePool.h"
#include "StarBackgroundPool.h"
#include "GameText.h"
#include "UIObject.h"
#include "UITextureManager.h"

#include "Audio.h"
#include "CoinPool.h"

class Texture2D;
class Character;
class ObstaclePool;

class GameScreenLevel1 : public GameScreen
{

public:

	GameScreenLevel1(SDL_Renderer* renderer, GameScreenManager* manager, bool renderMainMenu);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:

	Character* my_Character = nullptr;

	//Obstacle Pool Variables
	ObstaclePool* m_ObstaclePool = nullptr;
	ObstacleTextureManager* m_ObstacleTextures = nullptr;

	//Background Pool Setup
	StarBackgroundPool* m_StarBackgroundPool0 = nullptr;
	StarBackgroundPool* m_StarBackgroundPool1 = nullptr;
	StarBackgroundPool* m_StarBackgroundPool2 = nullptr;
	TextureManager* m_BackgroundTextureManager = nullptr;

	//Text for Main Menu
	GameText* m_Title = nullptr;
	GameText* m_ControlsTitle = nullptr;
	GameText* m_MoveRight = nullptr;
	GameText* m_MoveLeft = nullptr;

	GameText* m_InsertCoin = nullptr;

	UIObject* m_LeftIcon = nullptr;
	UIObject* m_RightIcon = nullptr;
	UIObject* m_LeftIconKB = nullptr;
	UIObject* m_RightIconKB = nullptr;

	UIObject* m_Coin = nullptr;

	TextureManager* m_UITextureManager = nullptr;

	//Coin Pool
	CoinPool* m_CoinPool = nullptr;
	int m_CoinsCollected = 0;
	GameText* m_CoinCountText = nullptr;
	UIObject* m_CoinHUDIcon = nullptr;

	//Distance Text
	GameText* m_Distance = nullptr;

	int m_DistanceTravelled = 0;

	bool m_IsRunning, m_DisplayMainMenu, m_MainMenuFlag;

	//Game Audio
	Audio* m_ExplosionAudio = nullptr;
	Audio* m_BackgroundMusic = nullptr;
};

