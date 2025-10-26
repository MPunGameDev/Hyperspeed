#include "DeathScreen.h"
#include <SDL.h>

DeathScreen::DeathScreen(SDL_Renderer* renderer, GameScreenManager* manager) : GameScreen(renderer, manager)
{
	m_Renderer = renderer;
	m_GameScreenManager = manager;
	SDL_SetRenderDrawColor(m_Renderer, 0x000000, 0x000000, 0x000000, 0x000000);

	//Background Setup
	m_BackgroundTextureManager = new BackgroundTextureManager(m_Renderer);
	m_StarBackgroundPool0 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 140, 30);
	m_StarBackgroundPool1 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 100, 50);
	m_StarBackgroundPool2 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 60, 90);

	m_Title = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 25);
	m_MilesSurvivedText = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_MilesSurvived = new GameText(m_Renderer, "Fonts/CabalBold.ttf",20);
	m_DistanceUnit = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_TryAgain = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 15);

	m_UITextureManager = new UITextureManager(m_Renderer);

	m_BrokenShip = new UIObject(m_Renderer, "PlayerBroken", Vector2D(LANETWOCENTER, PLAYERHEIGHTPOS - 30), m_UITextureManager);

	m_PossibleWords.push_back("Wrecked");
	m_PossibleWords.push_back("Pwned");
	m_PossibleWords.push_back("Obliterated");
	m_PossibleWords.push_back("Merked");
	m_PossibleWords.push_back("Dunk'd On");
	m_PossibleWords.push_back("Slammed");
	m_PossibleWords.push_back("360 NoScoped");
	m_PossibleWords.push_back("Clipped");

	m_SelectedWord = m_PossibleWords[random(0, m_PossibleWords.size() - 1)];
}

//Memory Cleanup
DeathScreen::~DeathScreen()
{
	delete m_StarBackgroundPool0;
	m_StarBackgroundPool0 = nullptr;

	delete m_StarBackgroundPool1;
	m_StarBackgroundPool1 = nullptr;

	delete m_StarBackgroundPool2;
	m_StarBackgroundPool2 = nullptr;

	delete m_BackgroundTextureManager;
	m_BackgroundTextureManager = nullptr;

	delete m_Title;
	m_Title = nullptr;

	delete m_MilesSurvived;
	m_MilesSurvived = nullptr;

	delete m_TryAgain;
	m_TryAgain = nullptr;

	delete m_BrokenShip;
	m_BrokenShip = nullptr;

	delete m_UITextureManager;
	m_UITextureManager = nullptr;
}

void DeathScreen::Render()
{
	m_StarBackgroundPool0->Render();
	m_StarBackgroundPool1->Render();
	m_StarBackgroundPool2->Render();

	m_Title->RenderAt("You got " + m_SelectedWord, LANETWOCENTER, 250);
	m_MilesSurvivedText->RenderAt("You survived ", LANETWOCENTER, 300);
	m_MilesSurvived->RenderAt(to_string(m_GameScreenManager->GetHighScore()), LANETWOCENTER, 350);
	m_DistanceUnit->RenderAt("Parsecs", LANETWOCENTER, 400);
	m_TryAgain->RenderAt("Press anything to play again", LANETWOCENTER, 450);

	m_BrokenShip->Render();
}

void DeathScreen::Update(float deltaTime, SDL_Event e)
{
	m_StarBackgroundPool0->Update(deltaTime, e);
	m_StarBackgroundPool1->Update(deltaTime, e);
	m_StarBackgroundPool2->Update(deltaTime, e);

	//Detect any keyup to change back to main menu

	if (e.type == SDL_KEYUP)
	{
		m_GameScreenManager->ChangeScreen(SCREEN_LEVEL1, m_GameScreenManager);
	}

	if (e.type == SDL_JOYBUTTONUP)
	{
		m_GameScreenManager->ChangeScreen(SCREEN_LEVEL1, m_GameScreenManager);
	}

}
