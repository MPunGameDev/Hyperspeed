#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Texture2D.h"

using namespace std;

class TextureManager
{
public:

	TextureManager(SDL_Renderer* renderer);
	~TextureManager();

	Texture2D* GetTextureByName(string name);
	Texture2D* GetRandomTexture();
	string GetRandomName();

	virtual void InitialiseTextures() = 0;

private:

	bool IsTextureInMap(string name);

protected:

	SDL_Renderer* m_Renderer = nullptr;
	map<string, Texture2D*> m_TextureMap;
	void CreateTextureInMap(string prefix, string ObstacleName);
};

