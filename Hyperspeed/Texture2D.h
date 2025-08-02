#pragma once

#include <SDL.h>
#include <string>
#include "Commons.h"

#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

class Texture2D
{

public:

	Texture2D(SDL_Renderer* renderer);
	~Texture2D();

	bool LoadFromFile(std::string path);
	void Free();
	void Render(Vector2D new_position, SDL_RendererFlip flip, double angle = 0.0);

	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }
	SDL_RendererFlip GetFlip() { return m_Flip; }

	void SetWidth(int width);
	void SetHeight(int height);
	void SetFlip(SDL_RendererFlip flip);

private:

	SDL_Renderer* m_Renderer = nullptr;
	SDL_Texture* m_Texture = nullptr;

	SDL_RendererFlip m_Flip = SDL_FLIP_NONE;

	int m_Width;
	int m_Height;
};

#endif //_TEXTURE2D_H

