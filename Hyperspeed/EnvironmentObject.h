#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class EnvironmentObject : public GameObject
{
public:

	EnvironmentObject(SDL_Renderer* renderer, string objectName, Vector2D startPos, TextureManager* textureManager);
	~EnvironmentObject();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	virtual void SetSpeed(int speed) override;

	void SetTexture(Texture2D* newTexture);
	Texture2D* GetTexture() { return m_Texture; }

private:

	int m_Speed;

	TextureManager* m_TextureManager = nullptr;

protected:

	virtual void MoveDown(float deltaTime);
	virtual bool IsOffScreen();

};

