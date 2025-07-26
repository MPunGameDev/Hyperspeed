#include "GameScreen.h"

#include <SDL.h>
#include <iostream>
#include <string>

GameScreen::GameScreen(SDL_Renderer* renderer, GameScreenManager* manager)
{
	m_Renderer = renderer;
	m_GameScreenManager = manager;
}

GameScreen::~GameScreen()
{
	m_Renderer = nullptr;
}

void GameScreen::Render()
{
}

void GameScreen::Update(float deltaTime, SDL_Event e)
{
}
