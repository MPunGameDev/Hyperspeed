#pragma once

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <iostream>

using namespace std;

class GameText
{
public:

	GameText(SDL_Renderer* renderer, const string& path, unsigned int fontSize);
	~GameText();

	bool LoadFont(const string& fontPath, unsigned int fontSize);

	void RenderAt(const string& text, int x, int y);
	void SetColor(SDL_Color color);

protected:

	SDL_Texture* m_Texture = nullptr;
	TTF_Font* m_Font = nullptr;
	SDL_Color m_Color{ 255,255,255,255 };
	SDL_Renderer* m_Renderer = nullptr;

private:
	void Destroy();

	static bool m_TTFHasInit;
	static bool InitTTF();

	bool m_ErrorEncountered = false;

};

