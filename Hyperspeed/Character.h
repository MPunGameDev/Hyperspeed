#pragma once

#include "GameObject.h"
#include "MathsHelper.h"
#include "Audio.h"

using namespace std;

class Character : public GameObject
{
public:

	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition);
	~Character();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	virtual void SetSpeed(int speed) override;

private:
	FACING m_Facing_Direction;
	LANES m_currentLane;
	double m_Rotation;

protected:
	bool m_Moving_Left;
	bool m_Moving_Right;
	bool m_Moving;
	bool m_HitYTarget;

	string m_imagePath;

	int m_YTarget;

	virtual void MoveIntoLane(float deltaTime, LANES laneToMoveTo, int laneXPos, FACING direction);

	virtual void ResetRotationOverTime(float deltaTime);

	Audio* m_MovementWhoosh = nullptr;
};
