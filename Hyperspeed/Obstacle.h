#pragma once
#include "GameObject.h"
#include "ObstacleTextureManager.h"

#include "Commons.h"

class Obstacle : public GameObject
{
public:

	Obstacle(SDL_Renderer* renderer, string obstacleName, LANES assignedLane, ObstacleTextureManager* textureManager);
	~Obstacle();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	void SetTexture(Texture2D* newTexture);
	void SetSpeed(int speed);

private:
	FACING m_Facing_Direction;
	LANES m_AssignedLane;
	double m_Rotation;
	int m_Speed;

	ObstacleTextureManager* m_TextureManager = nullptr;

protected:

	virtual void MoveDown(float deltaTime);
	virtual bool IsOffScreen();
};

