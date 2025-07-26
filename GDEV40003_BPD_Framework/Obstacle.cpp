#include "Obstacle.h"
#include "Constants.h"
#include "MathsHelper.h"

#include "Texture2D.h"

Obstacle::Obstacle(SDL_Renderer* renderer, string obstacleName, LANES assignedLane, ObstacleTextureManager* textureManager) : GameObject(0)
{
	m_Renderer = renderer;
	m_TextureManager = textureManager;
	m_Texture = m_TextureManager->GetTextureByName(obstacleName);
	m_AssignedLane = assignedLane;
	SetSpeed(random(MINOBJECTSPEED, MAXOBJECTSPEED));

	switch (m_AssignedLane)
	{
	case LANE_1:
		SetPosition(Vector2D(LANEONECENTER - (m_Texture->GetWidth() / 2), -100));
		break;
	case LANE_2:
		SetPosition(Vector2D(LANETWOCENTER - (m_Texture->GetWidth() / 2), -100));
		break;
	case LANE_3:
		SetPosition(Vector2D(LANETHREECENTER - (m_Texture->GetWidth() / 2), -100));
		break;
	default:
		break;
	}

	m_Facing_Direction = FACING_UP;
	m_Rotation = 0.0;
	m_CollisionRadius = 20;
}

Obstacle::~Obstacle()
{
	m_TextureManager = nullptr;
}

void Obstacle::Render()
{
	m_Texture->Render(m_Position, m_Texture->GetFlip(), m_Rotation);
}

void Obstacle::Update(float deltaTime, SDL_Event e)
{
	if(IsOffScreen())
	{
		SetTexture(m_TextureManager->GetRandomTexture());
		SetPosition(Vector2D(GetPosition().x, -100));
		SetSpeed(random(MINOBJECTSPEED, MAXOBJECTSPEED));
	}
	else 
	{
		MoveDown(deltaTime);
		m_Rotation += (m_Speed / 10) * deltaTime;
	}
}

void Obstacle::SetTexture(Texture2D* newTexture)
{
	m_Texture = newTexture;
}

void Obstacle::SetSpeed(int speed)
{
	m_Speed = speed;
}

void Obstacle::MoveDown(float deltaTime)
{
	SetPosition(Vector2D(GetPosition().x, GetPosition().y + deltaTime * m_Speed));
}

bool Obstacle::IsOffScreen()
{
	if (m_Position.y > SCREEN_HEIGHT) 
	{
		return true;
	}

	return false;
}
