#include "Coin.h"
#include "Constants.h"
#include "MathsHelper.h"
#include "Texture2D.h"

Coin::Coin(SDL_Renderer* renderer, Texture2D* texture, LANES assignedLane) : GameObject(0)
{
	m_Renderer = renderer;
	m_Texture = texture;
	m_AssignedLane = assignedLane;
	m_Speed = 250;
	m_Collected = false;
	m_CollisionRadius = 8;

	float startX;
	switch (m_AssignedLane)
	{
	case LANE_1: startX = LANEONECENTER - (m_Texture->GetWidth() / 4.0f); break;
	case LANE_2: startX = LANETWOCENTER - (m_Texture->GetWidth() / 4.0f); break;
	case LANE_3: startX = LANETHREECENTER - (m_Texture->GetWidth() / 4.0f); break;
	default:     startX = LANETWOCENTER;                                    break;
	}
	SetPosition(Vector2D(startX, (float)-random(100, 1000)));
}

Coin::~Coin()
{
}

void Coin::Render()
{
	if (!m_Collected)
		m_Texture->Render(m_Position, SDL_FLIP_NONE, 0.0, m_Texture->GetWidth() / 2, m_Texture->GetHeight() / 2);
}

void Coin::Update(float deltaTime, SDL_Event e)
{
	if (IsOffScreen())
		Recycle();
	else if (!m_Collected)
		MoveDown(deltaTime);
}

void Coin::Collect()
{
	m_Collected = true;
	SetPosition(Vector2D(GetPosition().x, (float)(SCREEN_HEIGHT + 100)));
}

void Coin::MoveDown(float deltaTime)
{
	SetPosition(Vector2D(GetPosition().x, GetPosition().y + deltaTime * m_Speed));
}

bool Coin::IsOffScreen()
{
	return m_Position.y > SCREEN_HEIGHT;
}

void Coin::Recycle()
{
	m_Collected = false;
	SetPosition(Vector2D(GetPosition().x, (float)-random(200, 1200)));
}
