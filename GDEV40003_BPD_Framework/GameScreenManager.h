#pragma once

#include <SDL.h>
#include "Commons.h"

class GameScreen;

class GameScreenManager
{
public:

	GameScreenManager(SDL_Renderer* renderer);
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);
	void ChangeScreen(SCREENS newScreen, GameScreenManager* manager);

	void SetHighScore(int score) { m_HighScore = score; }
	int GetHighScore() { return m_HighScore; }

private:

	SDL_Renderer* m_Renderer = nullptr;
	GameScreen* m_Current_Screen = nullptr;

	int m_HighScore = 0;

};

