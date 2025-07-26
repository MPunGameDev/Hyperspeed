#pragma once

#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "GameText.h"
#include "UIObject.h"

#include "MathsHelper.h"
#include "UITextureManager.h"

#include "StarBackgroundPool.h"

class DeathScreen : public GameScreen
{
public:

	DeathScreen(SDL_Renderer* renderer, GameScreenManager* manager);
	~DeathScreen();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:

	//Background Pool Setup
	StarBackgroundPool* m_StarBackgroundPool0 = nullptr;
	StarBackgroundPool* m_StarBackgroundPool1 = nullptr;
	StarBackgroundPool* m_StarBackgroundPool2 = nullptr;
	TextureManager* m_BackgroundTextureManager = nullptr;

	//Death Screen Text
	GameText* m_Title = nullptr;
	GameText* m_MilesSurvivedText = nullptr;
	GameText* m_MilesSurvived = nullptr;
	GameText* m_DistanceUnit = nullptr;
	GameText* m_TryAgain = nullptr;

	//UI Objects
	UITextureManager* m_UITextureManager = nullptr;
	UIObject* m_BrokenShip = nullptr;

	vector<string> m_PossibleWords;
	string m_SelectedWord;
};

