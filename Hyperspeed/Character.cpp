#include "Character.h"
#include "Texture2D.h"

#include "Constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition) : GameObject(renderer, imagePath, startPosition)
{
	m_imagePath = imagePath;
	m_Facing_Direction = FACING_UP;
	m_Rotation = 0.0;

	m_currentLane = LANE_2;
	m_HitYTarget = false;

	m_Position = Vector2D(GetPosition().x, PLAYERHEIGHTPOS);
	m_YTarget = random(PLAYERHEIGHTMIN, PLAYERHEIGHTMAX);

	m_CollisionRadius = 15;

	m_MovementWhoosh = new Audio("Sounds/Whoosh_1.wav", 3);
}

Character::~Character()
{
	delete m_MovementWhoosh;
	m_MovementWhoosh = nullptr;
}


void Character::Render()
{
	m_Texture->Render(m_Position, m_Texture->GetFlip(), m_Rotation);
}

void Character::Update(float deltaTime, SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:

			if (!m_Moving)
			{
				m_Moving_Left = true;
				m_Moving = true;
			}

			if (m_Moving)
			{
				m_MovementWhoosh->Play(0);
			}
			break;
		case SDLK_RIGHT:

			if (!m_Moving)
			{
				m_Moving_Right = true;
				m_Moving = true;
			}
			if (m_Moving)
			{
				m_MovementWhoosh->Play(0);
			}

			break;
		default:
			m_Moving = false;
			break;
		}
	}

	//Handle Evercade input
	if (e.type == SDL_JOYBUTTONDOWN)
	{
		switch (e.jbutton.button)
		{
		case 11:
			m_Moving_Left = true;
			m_Moving = true;

			if (m_Moving)
			{
				m_MovementWhoosh->Play(0);
			}
			break;
		case 12:
			m_Moving_Right = true;
			m_Moving = true;

			if (m_Moving)
			{
				m_MovementWhoosh->Play(0);
			}

			break;
		default:
			m_Moving = false;
			break;
		}
	}

	if (m_Moving_Left)
	{
		switch (m_currentLane)
		{
		case LANE_1:
			m_Moving_Left = false;
			m_Moving = false;
			break;
		case LANE_2:
			MoveIntoLane(deltaTime, LANE_1, LANEONECENTER, FACING_LEFT);
			break;
		case LANE_3:
			MoveIntoLane(deltaTime, LANE_2, LANETWOCENTER, FACING_LEFT);
			break;
		default:
			break;
		}
	}
	else if (m_Moving_Right)
	{
		switch (m_currentLane)
		{
		case LANE_1:
			MoveIntoLane(deltaTime, LANE_2, LANETWOCENTER, FACING_RIGHT);
			break;
		case LANE_2:
			MoveIntoLane(deltaTime, LANE_3, LANETHREECENTER, FACING_RIGHT);
			break;
		case LANE_3:
			m_Moving_Right = false;
			m_Moving = false;
			break;
		default:
			break;
		}
	}
	else if (!m_Moving)
	{
		ResetRotationOverTime(deltaTime);
	}

	//Handle Randomisation of Y position for "change" in character speed
	if (!m_HitYTarget)
	{

		float currentY = 0;

		if (m_YTarget < GetPosition().y)
		{
			SetPosition(Vector2D(GetPosition().x, GetPosition().y - ((deltaTime * MOVEMENTSPEED) / 8)));
			currentY = roundf(GetPosition().y);

			if (currentY == m_YTarget)
			{
				m_HitYTarget = true;
			}

		}
		else if(m_YTarget > GetPosition().y) 
		{
			SetPosition(Vector2D(GetPosition().x, GetPosition().y + ((deltaTime * MOVEMENTSPEED) / 8)));
			currentY = roundf(GetPosition().y);

			if (currentY == m_YTarget)
			{
				m_HitYTarget = true;
			}

		}
	}
	else 
	{
		if (m_YTarget < PLAYERHEIGHTPOS)
		{
			m_YTarget = random(PLAYERHEIGHTPOS, PLAYERHEIGHTMAX);
		}
		else if(m_YTarget > PLAYERHEIGHTPOS)
		{
			m_YTarget = random(PLAYERHEIGHTMIN, PLAYERHEIGHTPOS);
		}
		else 
		{
			m_YTarget = random(PLAYERHEIGHTMIN, PLAYERHEIGHTMAX);
		}

		m_HitYTarget = false;
	}
}

void Character::SetSpeed(int speed)
{
	m_Speed = speed;
}

void Character::MoveIntoLane(float deltaTime, LANES laneToMoveTo, int laneXPos, FACING direction)
{
	switch (direction)
	{
	case FACING_LEFT:
		if (roundf(GetPosition().x) > laneXPos - (m_Texture->GetWidth() / 2)) //Check if the character is not yet in the target lane
		{
			SetPosition(Vector2D(GetPosition().x - deltaTime * MOVEMENTSPEED, GetPosition().y)); //Move the character towards the target lane over time

			if (m_Rotation > -MAXPLAYERROTATION)
			{
				m_Rotation -= 0.1;
			}
		}
		else
		{
			m_currentLane = laneToMoveTo;
			m_Moving = false;
			m_Moving_Left = false;
		}
		break;
	case FACING_RIGHT:
		if (roundf(GetPosition().x) < laneXPos - (m_Texture->GetWidth() / 2)) //Check if the character is not yet in the target lane
		{
			SetPosition(Vector2D(GetPosition().x + deltaTime * MOVEMENTSPEED, GetPosition().y)); //Move the character towards the target lane over time

			if (m_Rotation < MAXPLAYERROTATION)
			{
				m_Rotation += 0.1;
			}
		}
		else
		{
			m_currentLane = laneToMoveTo;
			m_Moving = false;
			m_Moving_Right = false;
		}
		break;
	default:
		break;
	}
}

void Character::ResetRotationOverTime(float deltaTime)
{
	if (m_Rotation < 0)
	{
		m_Rotation += deltaTime * MOVEMENTSPEED;
	}
	else if (m_Rotation > 0)
	{
		m_Rotation -= deltaTime * MOVEMENTSPEED;
	}
}
