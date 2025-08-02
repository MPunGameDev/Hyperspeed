#include "EnvironmentObject.h"
#include "Constants.h"

EnvironmentObject::EnvironmentObject(SDL_Renderer* renderer, string objectName, Vector2D startPos, TextureManager* textureManager) : GameObject(0)
{
	m_Renderer = renderer;
	m_TextureManager = textureManager;
	m_Texture = m_TextureManager->GetTextureByName(objectName);

	SetSpeed(MINOBJECTSPEED);

	SetPosition(Vector2D(startPos.x, startPos.y));
}

EnvironmentObject::~EnvironmentObject()
{
	m_TextureManager = nullptr;
}

void EnvironmentObject::Render()
{
	m_Texture->Render(m_Position, m_Texture->GetFlip());
}

void EnvironmentObject::Update(float deltaTime, SDL_Event e)
{
	if (IsOffScreen())
	{
		SetPosition(Vector2D(GetPosition().x, -SCREEN_HEIGHT));
	}
	else
	{
		MoveDown(deltaTime);
	}
}

void EnvironmentObject::SetSpeed(int speed)
{
	m_Speed = speed;
}

void EnvironmentObject::SetTexture(Texture2D* newTexture)
{
	m_Texture = newTexture;
}

void EnvironmentObject::MoveDown(float deltaTime)
{
	SetPosition(Vector2D(GetPosition().x, GetPosition().y + deltaTime * m_Speed));
}

bool EnvironmentObject::IsOffScreen()
{
	if (m_Position.y > SCREEN_HEIGHT)
	{
		return true;
	}

	return false;
}
