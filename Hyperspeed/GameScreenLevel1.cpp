#include "GameScreenLevel1.h"
#include "Constants.h"

#include "Texture2D.h"
#include "Collisions.h"
#include "Coin.h"
#include <iostream>

using namespace std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer, GameScreenManager* manager) : GameScreen(renderer, manager)
{
	m_MainMenuFlag = true;
	m_IsRunning = true;

	SDL_SetRenderDrawColor(m_Renderer, 0x000000, 0x000000, 0x000000, 0x000000);

	//Player Setup — start at top of screen so the intro slide-down plays
	my_Character = new Character(m_Renderer, "Images/Player/PlayerSprite.png", WINDOWCENTER);
	my_Character->SetPosition(Vector2D(my_Character->GetPosition().x, 100));

	//Obstacle Setup
	m_ObstacleTextures = new ObstacleTextureManager(m_Renderer);
	m_ObstaclePool = new ObstaclePool(m_Renderer, m_ObstacleTextures);

	//Background Setup
	m_BackgroundTextureManager = new BackgroundTextureManager(m_Renderer);
	m_StarBackgroundPool0 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 140, 60);
	m_StarBackgroundPool1 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 100, 100);
	m_StarBackgroundPool2 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 60, 180);

	m_UITextureManager = new UITextureManager(m_Renderer);

	//Distance Travelled Text
	m_Distance = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);

	//Coin Setup
	m_CoinPool = new CoinPool(m_Renderer, m_UITextureManager);
	m_CoinCountText = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_CoinHUDIcon = new UIObject(m_Renderer, "Coin", Vector2D(50, 20), m_UITextureManager);

	m_ExplosionAudio = new Audio("Sounds/Explosion.wav", 1);
	m_BackgroundMusic = new Audio("Sounds/BackgroundMusic.wav", 2);
	m_BackgroundMusic->Play(-1);
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete my_Character;
	my_Character = nullptr;

	delete m_ObstaclePool;
	m_ObstaclePool = nullptr;

	delete m_ObstacleTextures;
	m_ObstacleTextures = nullptr;

	delete m_StarBackgroundPool0;
	m_StarBackgroundPool0 = nullptr;

	delete m_StarBackgroundPool1;
	m_StarBackgroundPool1 = nullptr;

	delete m_StarBackgroundPool2;
	m_StarBackgroundPool2 = nullptr;

	delete m_BackgroundTextureManager;
	m_BackgroundTextureManager = nullptr;

	delete m_UITextureManager;
	m_UITextureManager = nullptr;

	delete m_CoinPool;
	m_CoinPool = nullptr;

	delete m_CoinCountText;
	m_CoinCountText = nullptr;

	delete m_CoinHUDIcon;
	m_CoinHUDIcon = nullptr;

	delete m_Distance;
	m_Distance = nullptr;

	delete m_ExplosionAudio;
	m_ExplosionAudio = nullptr;

	delete m_BackgroundMusic;
	m_BackgroundMusic = nullptr;
}

void GameScreenLevel1::Render()
{
	m_StarBackgroundPool0->Render();
	m_StarBackgroundPool1->Render();
	m_StarBackgroundPool2->Render();
	m_ObstaclePool->Render();
	m_CoinPool->Render();
	m_Distance->RenderAt(to_string(m_DistanceTravelled) + " P", LANETWOCENTER, 100);
	m_CoinHUDIcon->Render();
	m_CoinCountText->RenderAt(to_string(m_CoinsCollected), 60, 20);
	my_Character->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	if (m_IsRunning)
	{
		//Slide the ship down from the top before gameplay begins
		if (m_MainMenuFlag)
		{
			if (my_Character->GetPosition().y < PLAYERHEIGHTPOS)
			{
				my_Character->SetPosition(Vector2D(my_Character->GetPosition().x, my_Character->GetPosition().y + ((deltaTime * MOVEMENTSPEED) * 3)));
			}
			else
			{
				m_MainMenuFlag = false;
			}
		}

		m_DistanceTravelled++;

		m_StarBackgroundPool0->Update(deltaTime, e);
		m_StarBackgroundPool1->Update(deltaTime, e);
		m_StarBackgroundPool2->Update(deltaTime, e);
		my_Character->Update(deltaTime, e);
		m_ObstaclePool->Update(deltaTime, e);
		m_CoinPool->Update(deltaTime, e);

		//Check obstacle collisions
		std::vector<GameObject*>::iterator itr;

		for (itr = m_ObstaclePool->GetPool().begin(); itr != m_ObstaclePool->GetPool().end(); ++itr)
		{
			if (Collisions::Instance()->Circle(my_Character, (*itr)))
			{
				m_IsRunning = false;
			}
		}

		//Check coin collisions
		for (itr = m_CoinPool->GetPool().begin(); itr != m_CoinPool->GetPool().end(); ++itr)
		{
			Coin* coin = static_cast<Coin*>(*itr);
			if (Collisions::Instance()->Circle(my_Character, coin))
			{
				coin->Collect();
				m_CoinsCollected++;
			}
		}
	}
	else
	{
		m_ExplosionAudio->Play(0);
		m_BackgroundMusic->Pause();
		m_GameScreenManager->SetHighScore(m_DistanceTravelled);
		m_GameScreenManager->ChangeScreen(SCREEN_DEATHSCREEN, m_GameScreenManager);
	}
}
