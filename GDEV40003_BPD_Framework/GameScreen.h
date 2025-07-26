#pragma once
#include <SDL.h>
#include "GameScreenManager.h"

#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

class GameScreen
{
public:

	GameScreen(SDL_Renderer* renderer, GameScreenManager* manager);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

protected:

	SDL_Renderer* m_Renderer = nullptr;
	GameScreenManager* m_GameScreenManager = nullptr;

};

#endif //_GAMESCREEN_H

