#pragma once
#include "GameObject.h"
#include "Commons.h"

class Coin : public GameObject
{
public:
	Coin(SDL_Renderer* renderer, Texture2D* texture, LANES assignedLane);
	~Coin();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;
	virtual void SetSpeed(int speed) override { m_Speed = speed; }

	void Collect();

private:
	LANES m_AssignedLane;
	bool m_Collected;

	void MoveDown(float deltaTime);
	bool IsOffScreen();
	void Recycle();
};
