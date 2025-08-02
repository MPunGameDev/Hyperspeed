#include "UIObject.h"
#include "Constants.h"

UIObject::UIObject(SDL_Renderer* renderer, string objectName, Vector2D startPos, TextureManager* textureManager) : GameObject(0)
{
	m_Renderer = renderer;
	m_TextureManager = textureManager;
	m_Texture = m_TextureManager->GetTextureByName(objectName);

	SetSpeed(MINOBJECTSPEED);

	SetPosition(Vector2D(startPos.x - (m_Texture->GetWidth() / 2), startPos.y));
}

UIObject::~UIObject()
{
	m_TextureManager = nullptr;
}

void UIObject::Render()
{
	m_Texture->Render(m_Position, SDL_FLIP_NONE);
}

void UIObject::Update(float deltaTime, SDL_Event e)
{
}

void UIObject::SetSpeed(int speed)
{
	m_Speed = speed;
}

void UIObject::SetTexture(Texture2D* newTexture)
{
	m_Texture = newTexture;
}
