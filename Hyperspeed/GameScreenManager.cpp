#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenMainMenu.h"
#include "GameScreenLevel1.h"
#include "DeathScreen.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
	m_Current_Screen = nullptr;
}

GameScreenManager::~GameScreenManager()
{
	m_Renderer = nullptr;

	delete m_Current_Screen;
	m_Current_Screen = nullptr;
}

void GameScreenManager::Render()
{
	m_Current_Screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_Current_Screen->Update(deltaTime, e);
}

void GameScreenManager::ChangeScreen(SCREENS newScreen, GameScreenManager* manager)
{
	if (m_Current_Screen != nullptr)
	{
		delete m_Current_Screen;
		m_Current_Screen = nullptr;
	}

	GameScreen* tempScreen = nullptr;

	switch (newScreen)
	{
		case SCREEN_MAINMENU: tempScreen = new GameScreenMainMenu(m_Renderer, manager); break;
		case SCREEN_LEVEL1: tempScreen = new GameScreenLevel1(m_Renderer, manager); break;
		case SCREEN_DEATHSCREEN: tempScreen = new DeathScreen(m_Renderer, manager); break;
	}

	m_Current_Screen = (GameScreen*)tempScreen;
	tempScreen = nullptr;
}
