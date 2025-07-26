#include "GameObject.h"
#include "Constants.h"
#include "Texture2D.h"

GameObject::GameObject(SDL_Renderer* renderer, string imagePath, Vector2D startPosition)
{
	m_Renderer = renderer;

	m_Texture = new Texture2D(m_Renderer);


	if (!m_Texture->LoadFromFile(imagePath))
	{
		cout << "Failed to load GameObject texture!" << endl;
	}

	if (startPosition ==  Vector2D WINDOWCENTER) 
	{
		SetPosition(Vector2D(startPosition.x - (m_Texture->GetWidth() / 2), startPosition.y - (m_Texture->GetHeight() / 2)));
	}
	else 
	{
		m_Position = startPosition;
	}
}

GameObject::~GameObject()
{
	m_Renderer = nullptr;
}

void GameObject::Render()
{
	m_Texture->Render(m_Position, SDL_FLIP_NONE);
}

void GameObject::Update(float deltaTime, SDL_Event e)
{
}

void GameObject::SetPosition(Vector2D newPosition)
{
	m_Position = newPosition;
}

Vector2D GameObject::GetPosition()
{
	return m_Position;
}
