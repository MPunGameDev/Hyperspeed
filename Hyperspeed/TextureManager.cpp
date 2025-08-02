#include "TextureManager.h"
#include "MathsHelper.h"

void TextureManager::CreateTextureInMap(string prefix, string obstacleName)
{
	Texture2D* texture = new Texture2D(m_Renderer);

	if (!texture->LoadFromFile("Images/" + prefix + obstacleName + ".png"))
	{
		cout << "Could not create texture for" << obstacleName << endl;
	}
	else 
	{
		m_TextureMap.insert({ obstacleName, texture });
		cout << "Texture created in memory for " << obstacleName << endl;
	}

}

Texture2D* TextureManager::GetTextureByName(string obstacleName)
{
	if (!IsTextureInMap(obstacleName))
	{
		cout << "Error Texture not found" << endl;
		return nullptr;
	}

	for (auto i = m_TextureMap.begin(); i != m_TextureMap.end(); i++)
	{
		if (obstacleName == i->first)
		{
			return i->second;
		}
	}
}

Texture2D* TextureManager::GetRandomTexture()
{
	int randValue = random(0, m_TextureMap.size() - 1);

	std::map<string, Texture2D*>::iterator itr = m_TextureMap.begin();

	std::advance(itr, randValue);

	return (*itr).second;
}

string TextureManager::GetRandomName()
{
	int randValue = random(0, m_TextureMap.size() - 1);

	std::map<string, Texture2D*>::iterator itr = m_TextureMap.begin();

	std::advance(itr, randValue);

	return (*itr).first;
}

TextureManager::TextureManager(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
	cout << "TextureManager Instance Created" << endl;
}

TextureManager::~TextureManager()
{
	m_Renderer = nullptr;

	for (auto i = m_TextureMap.begin(); i != m_TextureMap.end(); i++)
	{
		delete i->second;
		i->second = nullptr;
	}
	m_TextureMap.clear();
}

bool TextureManager::IsTextureInMap(string name)
{
	for (auto i = m_TextureMap.begin(); i != m_TextureMap.end(); i++)
	{
		if (i->first == name)
		{
			return true;
		}
	}

	return false;
}
