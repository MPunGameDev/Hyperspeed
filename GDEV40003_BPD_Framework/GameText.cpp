#include "GameText.h"

using namespace std;

bool GameText::m_TTFHasInit = false;

GameText::GameText(SDL_Renderer* renderer, const string& path, unsigned int fontSize)
{
	if (!InitTTF())
	{
		cerr << "Couldn't initialise TTF! Error is: " << TTF_GetError() << endl;
		m_ErrorEncountered = true;
		return;
	}

	this->m_Renderer = renderer;
	this->LoadFont(path, fontSize);

}

GameText::~GameText()
{
	Destroy();
}

bool GameText::LoadFont(const string& fontPath, unsigned int fontSize)
{
	this->m_Font = TTF_OpenFont(fontPath.c_str(), fontSize);

	if (!this->m_Font)
	{
		cerr << "Couldn't load font from path " << fontPath << "! Error is: " << TTF_GetError() << endl;
		m_ErrorEncountered = true;
		return false;
	}

	return true;
}

void GameText::RenderAt(const string& text, int x, int y)
{
	//Errors? Die
	if (m_ErrorEncountered)
		return;

	//Destroy tex if needed
	if (m_Texture != nullptr)
		SDL_DestroyTexture(m_Texture);

	//Size the Text
	int w, h;
	TTF_SizeText(m_Font, text.c_str(), &w, &h);

	//Load surf and tex
	SDL_Surface* surf = TTF_RenderText_Blended(m_Font, text.c_str(), m_Color);
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, surf);
	SDL_FreeSurface(surf);

	//Get render rect and render with it
	SDL_Rect renderRect{ x, y, w, h };
	renderRect.x = x - (w / 2);
	SDL_RenderCopy(m_Renderer, m_Texture, NULL, &renderRect);
}

void GameText::SetColor(SDL_Color color)
{
	this->m_Color = color;
}

void GameText::Destroy()
{
	m_Renderer = nullptr;
	
	delete m_Font;
	m_Font = nullptr;

	delete m_Texture;
	m_Texture = nullptr;

}

bool GameText::InitTTF()
{
	if (m_TTFHasInit)
		return true;

	return (TTF_Init() >= 0);
}
