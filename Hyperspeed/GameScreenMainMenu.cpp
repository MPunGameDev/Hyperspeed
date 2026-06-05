#include "GameScreenMainMenu.h"
#include "Constants.h"

GameScreenMainMenu::GameScreenMainMenu(SDL_Renderer* renderer, GameScreenManager* manager) : GameScreen(renderer, manager)
{
	SDL_SetRenderDrawColor(m_Renderer, 0x000000, 0x000000, 0x000000, 0x000000);

	m_Character = new Character(m_Renderer, "Images/Player/PlayerSprite.png", WINDOWCENTER);
	m_Character->SetPosition(Vector2D(m_Character->GetPosition().x, 100));

	m_BackgroundTextureManager = new BackgroundTextureManager(m_Renderer);
	m_StarBackgroundPool0 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 140, 30);
	m_StarBackgroundPool1 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 100, 50);
	m_StarBackgroundPool2 = new StarBackgroundPool(m_Renderer, m_BackgroundTextureManager, 60, 90);

	m_UITextureManager = new UITextureManager(m_Renderer);

	m_Title = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 35);
	m_ControlsTitle = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 30);
	m_MoveLeft = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_MoveRight = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 20);
	m_InsertCoin = new GameText(m_Renderer, "Fonts/CabalBold.ttf", 15);

	m_LeftIcon = new UIObject(m_Renderer, "MoveLeft", Vector2D(LANETHREECENTER, 350), m_UITextureManager);
	m_RightIcon = new UIObject(m_Renderer, "MoveRight", Vector2D(LANETHREECENTER, 400), m_UITextureManager);
	m_LeftIconKB = new UIObject(m_Renderer, "MoveLeftKB", Vector2D(LANETHREECENTER - 70, 353), m_UITextureManager);
	m_RightIconKB = new UIObject(m_Renderer, "MoveRightKB", Vector2D(LANETHREECENTER - 70, 403), m_UITextureManager);
	m_Coin = new UIObject(m_Renderer, "Coin", Vector2D(LANETWOCENTER, 450), m_UITextureManager);

	m_RightIcon->GetTexture()->SetHeight(m_RightIcon->GetTexture()->GetHeight() / 2.5);
	m_RightIcon->GetTexture()->SetWidth(m_RightIcon->GetTexture()->GetWidth() / 2.5);
	m_RightIconKB->GetTexture()->SetHeight(m_RightIconKB->GetTexture()->GetHeight() / 2);
	m_RightIconKB->GetTexture()->SetWidth(m_RightIconKB->GetTexture()->GetWidth() / 2);

	m_LeftIcon->GetTexture()->SetHeight(m_LeftIcon->GetTexture()->GetHeight() / 2.5);
	m_LeftIcon->GetTexture()->SetWidth(m_LeftIcon->GetTexture()->GetWidth() / 2.5);
	m_LeftIconKB->GetTexture()->SetHeight(m_LeftIconKB->GetTexture()->GetHeight() / 2);
	m_LeftIconKB->GetTexture()->SetWidth(m_LeftIconKB->GetTexture()->GetWidth() / 2);

	m_BackgroundMusic = new Audio("Sounds/BackgroundMusic.wav", 2);
	m_BackgroundMusic->Play(-1);
}

GameScreenMainMenu::~GameScreenMainMenu()
{
	delete m_Character;
	m_Character = nullptr;

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

	delete m_InsertCoin;
	m_InsertCoin = nullptr;

	delete m_LeftIcon;
	m_LeftIcon = nullptr;

	delete m_RightIcon;
	m_RightIcon = nullptr;

	delete m_LeftIconKB;
	m_LeftIconKB = nullptr;

	delete m_RightIconKB;
	m_RightIconKB = nullptr;

	delete m_Coin;
	m_Coin = nullptr;

	delete m_UITextureManager;
	m_UITextureManager = nullptr;

	delete m_BackgroundMusic;
	m_BackgroundMusic = nullptr;
}

void GameScreenMainMenu::Render()
{
	m_StarBackgroundPool0->Render();
	m_StarBackgroundPool1->Render();
	m_StarBackgroundPool2->Render();

	m_Title->RenderAt("HyperSpeed", LANETWOCENTER, 200);
	m_ControlsTitle->RenderAt("Controls", LANETWOCENTER, 275);
	m_MoveLeft->RenderAt("Move Left : ", LANEONECENTER + 50, 350);
	m_MoveRight->RenderAt("MoveRight : ", LANEONECENTER + 50, 400);
	m_LeftIcon->Render();
	m_RightIcon->Render();
	m_LeftIconKB->Render();
	m_RightIconKB->Render();
	m_Coin->Render();
	m_InsertCoin->RenderAt("Insert Coin to Play (A/B or Enter)", LANETWOCENTER, 550);
	m_Character->Render();
}

void GameScreenMainMenu::Update(float deltaTime, SDL_Event e)
{
	m_StarBackgroundPool0->Update(deltaTime, e);
	m_StarBackgroundPool1->Update(deltaTime, e);
	m_StarBackgroundPool2->Update(deltaTime, e);

	if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_RETURN)
	{
		m_GameScreenManager->ChangeScreen(SCREEN_LEVEL1, m_GameScreenManager);
	}

	if (e.type == SDL_JOYBUTTONUP && (e.jbutton.button == 11 || e.jbutton.button == 12))
	{
		m_GameScreenManager->ChangeScreen(SCREEN_LEVEL1, m_GameScreenManager);
	}
}
