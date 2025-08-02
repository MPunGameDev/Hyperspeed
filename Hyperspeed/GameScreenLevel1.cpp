#include "GameScreenLevel1.h"
#include "Constants.h"

#include "Texture2D.h"
#include "Collisions.h"
#include <iostream>

using namespace std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer, GameScreenManager* manager, bool renderMainMenu) : GameScreen(renderer, manager)
{
	m_DisplayMainMenu = renderMainMenu;
	m_MainMenuFlag = renderMainMenu;
	m_IsRunning = !renderMainMenu;

	SDL_SetRenderDrawColor(m_Renderer, 0x000000, 0x000000, 0x000000, 0x000000);

	//Player Setup
	my_Character = new Character(m_Renderer, "Images/Player/PlayerSprite.png", WINDOWCENTER);

	//Obstacle Setup
	m_ObstacleTextures = new ObstacleTextureManager(m_Renderer);
	m_ObstaclePool = new ObstaclePool(m_Renderer, m_ObstacleTextures);

	//Background Setup
	m_BackgroundTextureManager = new BackgroundTextureManager(m_Renderer);
	m_StarBackgroundPool0 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 140, 60);
	m_StarBackgroundPool1 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 100, 100);
	m_StarBackgroundPool2 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 60, 180);

	m_UITextureManager = new UITextureManager(m_Renderer);

	//Main Menu Text
	m_Title = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 35);
	m_ControlsTitle = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 30);
	m_MoveLeft = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_MoveRight = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_InsertCoin = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 15);

	//Distance Travelled Text
	m_Distance = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);

	m_LeftIcon = new UIObject(m_Renderer, "MoveLeft", Vector2D(LANETHREECENTER, 350), m_UITextureManager);
	m_RightIcon = new UIObject(m_Renderer, "MoveRight", Vector2D(LANETHREECENTER, 400), m_UITextureManager);
	m_Coin = new UIObject(m_Renderer, "Coin", Vector2D(LANETWOCENTER, 450), m_UITextureManager);

	//Set size of Move Right Icon
	m_RightIcon->GetTexture()->SetHeight(m_RightIcon->GetTexture()->GetHeight() / 2.5);
	m_RightIcon->GetTexture()->SetWidth(m_RightIcon->GetTexture()->GetWidth() / 2.5);

	//Set size of Move Left Icon
	m_LeftIcon->GetTexture()->SetHeight(m_LeftIcon->GetTexture()->GetHeight() / 2.5);
	m_LeftIcon->GetTexture()->SetWidth(m_LeftIcon->GetTexture()->GetWidth() / 2.5);

	m_ExplosionAudio = new Audio("Sounds/Explosion.wav", 1);
	m_BackgroundMusic = new Audio("Sounds/BackgroundMusic.wav", 2);

	//Set posiiton of Character to top of screen and slow down stars if on main menu
	if (m_DisplayMainMenu)
	{
		my_Character->SetPosition(Vector2D(my_Character->GetPosition().x, 100));
		m_StarBackgroundPool0->SetStarPoolSpeed(30);
		m_StarBackgroundPool1->SetStarPoolSpeed(50);
		m_StarBackgroundPool2->SetStarPoolSpeed(90);
	}

	m_BackgroundMusic->Play(-1);
}

GameScreenLevel1::~GameScreenLevel1()
{
	//Memory Cleanup

	delete my_Character;
	my_Character = nullptr;

	delete m_ObstaclePool;
	m_ObstaclePool = nullptr;

	delete m_ObstacleTextures;
	m_ObstacleTextures = nullptr;

	delete m_StarBackgroundPool0;
	m_StarBackgroundPool0 = nullptr;

	delete m_StarBackgroundPool1;
	m_StarBackgroundPool1 = nullptr;

	delete m_StarBackgroundPool2;
	m_StarBackgroundPool2 = nullptr;

	delete m_BackgroundTextureManager;
	m_BackgroundTextureManager = nullptr;

	delete m_Title;
	m_Title = nullptr;

	delete m_ControlsTitle;
	m_ControlsTitle = nullptr;

	delete m_MoveLeft;
	m_MoveLeft = nullptr;

	delete m_MoveRight;
	m_MoveRight = nullptr;

	delete m_LeftIcon;
	m_LeftIcon = nullptr;

	delete m_RightIcon;
	m_RightIcon = nullptr;

	delete m_UITextureManager;
	m_UITextureManager = nullptr;

	delete m_Coin;
	m_Coin = nullptr;

	delete m_Distance;
	m_Distance = nullptr;

	delete m_InsertCoin;
	m_InsertCoin = nullptr;

	delete m_ExplosionAudio;
	m_ExplosionAudio = nullptr;

	delete m_BackgroundMusic;
	m_BackgroundMusic = nullptr;
}

void GameScreenLevel1::Render()
{
	//Game Loop
	if (m_IsRunning)
	{
		m_StarBackgroundPool0->Render();
		m_StarBackgroundPool1->Render();
		m_StarBackgroundPool2->Render();
		m_ObstaclePool->Render();
		m_Distance->RenderAt(to_string(m_DistanceTravelled) + " P", LANETWOCENTER, 100);
		my_Character->Render();
	}

	//Main Menu Loop
	if (m_DisplayMainMenu)
	{
		m_StarBackgroundPool0->Render();
		m_StarBackgroundPool1->Render();
		m_StarBackgroundPool2->Render();
		m_Title->RenderAt("HyperSpeed", LANETWOCENTER, 200);
		m_ControlsTitle->RenderAt("Controls", LANETWOCENTER, 275);
		m_MoveLeft->RenderAt("Move Left", LANEONECENTER + 50, 350);
		m_MoveRight->RenderAt("MoveRight", LANEONECENTER + 50, 400);
		m_LeftIcon->Render();
		m_RightIcon->Render();
		m_Coin->Render();
		m_InsertCoin->RenderAt("Insert Coin to Play (A or B)", LANETWOCENTER, 550);
		my_Character->Render();
	}
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//For Testing Purposes
	if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			m_DisplayMainMenu = false;
			m_IsRunning = true;
			break;
		case SDLK_BACKSPACE:
			break;
		}
	}

	//For Testing Purposes
	if (e.type == SDL_JOYBUTTONUP)
	{
		switch (e.jbutton.button)
		{
		case 11:
			m_DisplayMainMenu = false;
			m_IsRunning = true;
			break;
		case 12:
			m_DisplayMainMenu = false;
			m_IsRunning = true;
			break;
		}
	}

	//Main Menu Update
	if (m_DisplayMainMenu)
	{
		m_StarBackgroundPool0->Update(deltaTime, e);
		m_StarBackgroundPool1->Update(deltaTime, e);
		m_StarBackgroundPool2->Update(deltaTime, e);
	}

	//Game Update
	if (m_IsRunning)
	{
		//If playing from the main menu
		if (m_MainMenuFlag)
		{
			//Check if the player is in position
			if (my_Character->GetPosition().y < PLAYERHEIGHTPOS)
			{
				//Flag for if stars have been sped up
				bool starsSpedUp = false;

				//Set the character position over time to the game position.
				my_Character->SetPosition(Vector2D(my_Character->GetPosition().x, my_Character->GetPosition().y + ((deltaTime * MOVEMENTSPEED)  * 3)));

				//Speed up stars if not already done
				if (!starsSpedUp)
				{
					m_StarBackgroundPool0->SetStarPoolSpeed(60);
					m_StarBackgroundPool1->SetStarPoolSpeed(100);
					m_StarBackgroundPool2->SetStarPoolSpeed(180);

					starsSpedUp = true;
				}
			}
			else
			{
				//Finished, set main menu flag to false
				m_MainMenuFlag = false;
			}
		}

		//Update distance travelled
		m_DistanceTravelled++;

		//Update Stars, Character and Obstacle Pool
		m_StarBackgroundPool0->Update(deltaTime, e);
		m_StarBackgroundPool1->Update(deltaTime, e);
		m_StarBackgroundPool2->Update(deltaTime, e);
		my_Character->Update(deltaTime, e);
		m_ObstaclePool->Update(deltaTime, e);

		//Iterate over Obstacle Pool and check for collision
		std::vector<GameObject*>::iterator itr;

		for (itr = m_ObstaclePool->GetPool().begin(); itr != m_ObstaclePool->GetPool().end(); ++itr)
		{
			if (Collisions::Instance()->Circle(my_Character, (*itr)))
			{
				//If collided stop running
				m_IsRunning = false;
			}
		}

	}
	//If not running and not in main menu change screen to death screen.
	else if(!m_IsRunning && !m_DisplayMainMenu)
	{
		m_ExplosionAudio->Play(0);
		m_BackgroundMusic->Pause();
		m_GameScreenManager->SetHighScore(m_DistanceTravelled);
		m_GameScreenManager->ChangeScreen(SCREEN_DEATHSCREEN, m_GameScreenManager);
	}


}
