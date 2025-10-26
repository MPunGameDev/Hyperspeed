#include "SDL.h"
#include "Constants.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include "Texture2D.h"
#include "Commons.h"

#include "GameScreenManager.h"

#include <iostream>
#include <SDL_ttf.h>

using namespace std;

SDL_Window* g_Window = nullptr;
SDL_Renderer* g_Renderer = nullptr;

SDL_Surface* g_Icon = nullptr;

SDL_Texture* g_RenderTex = nullptr;

GameScreenManager* game_Screen_Manager = nullptr;
Uint32 g_Old_Time;

//Function prototypes
bool InitSDL();
void CloseSDL();
bool Update();

void Render();

int main(int argc, char* argv[])
{
	if (InitSDL())
	{
		game_Screen_Manager = new GameScreenManager(g_Renderer);
		game_Screen_Manager->ChangeScreen(SCREEN_LEVEL1, game_Screen_Manager);

		//Set the time
		g_Old_Time = SDL_GetTicks();

		//Flag to check if we wish to quit
		bool quit = false;

		//Game Loop
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}

	CloseSDL();

	return 0;
}

bool InitSDL()
{
	//Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_EVENTS) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else 
	{
		//Setup passed so create window
		g_Window = SDL_CreateWindow("Hyperspeed",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		//Set Window Icon
		g_Icon = IMG_Load("Images/WindowIcon/Icon.png");
		SDL_SetWindowIcon(g_Window, g_Icon);

		//Did the window get created?
		if (g_Window == nullptr)
		{
			//Window failed
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}

		g_Renderer = SDL_CreateRenderer(g_Window, -1, SDL_RENDERER_ACCELERATED);

		if (g_Renderer != nullptr)
		{
			//Init PNG Loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
				return false;
			}
		}
		else 
		{
			cout << "Renderer could not initialise. Error: " << SDL_GetError();
			return false;
		}

		SDL_JoystickOpen(1);
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Mixer could not init" << Mix_GetError() << endl;
	}

	g_RenderTex = SDL_CreateTexture(g_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
	return true;
}

void CloseSDL()
{
	//Release the renderer
	SDL_DestroyRenderer(g_Renderer);
	g_Renderer = nullptr;

	//Release the window
	SDL_DestroyWindow(g_Window);
	g_Window = nullptr;

	//Destroy the game screen manager
	delete game_Screen_Manager;
	game_Screen_Manager = nullptr;

	SDL_DestroyTexture(g_RenderTex);
	g_RenderTex = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

bool Update()
{
	Uint32 new_Time = SDL_GetTicks();

	//Event handler
	SDL_Event e;

	//Get events
	SDL_PollEvent(&e);

	//Handle the events
	switch (e.type)
	{
	case SDL_QUIT:
		return true;
	}

	game_Screen_Manager->Update((float)(new_Time - g_Old_Time) / 1000.0f, e);

	g_Old_Time = new_Time;

	return false;
}

void Render()
{
	//Clear the screen
	SDL_SetRenderTarget(g_Renderer, g_RenderTex);
	SDL_RenderClear(g_Renderer);

	game_Screen_Manager->Render();

	static int angle = 0;

	SDL_SetRenderTarget(g_Renderer, NULL);
	SDL_RenderClear(g_Renderer);
	SDL_RenderCopyEx(g_Renderer, g_RenderTex, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

	//Update the screen
	SDL_RenderPresent(g_Renderer);
}

