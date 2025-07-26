#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

Texture2D::~Texture2D()
{
	//Free up memory
	Free();

	m_Renderer = nullptr;
}

bool Texture2D::LoadFromFile(std::string path)
{
	//Remove memory used for a previous texture
	Free();

	//Load the image
	SDL_Surface* p_Surface = IMG_Load(path.c_str());

	if (p_Surface != nullptr)
	{
		//Colour key the image to be transparent
		SDL_SetColorKey(p_Surface, SDL_TRUE, SDL_MapRGB(p_Surface->format, 0, 0XFF, 0XFF));

		//Create the texture from the pixels on the surface
		m_Texture = SDL_CreateTextureFromSurface(m_Renderer, p_Surface);
		if (m_Texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}
		else
		{
			m_Width = p_Surface->w;
			m_Height = p_Surface->h;
		}

		//Remove the loaded surface now that we have a texture
		SDL_FreeSurface(p_Surface);
	}
	else
	{
		cout << "Unable to create texture from surfacew. Error: " << IMG_GetError();
	}

	return m_Texture != nullptr;
}

void Texture2D::Free()
{
	//Check if the texture exists before removing it
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;

		m_Width = 0;
		m_Height = 0;
	}
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//Set where to render the texture
	SDL_Rect renderLocation = { new_position.x, new_position.y, m_Width, m_Height };

	//Render to screen
	SDL_RenderCopyEx(m_Renderer, m_Texture, nullptr, &renderLocation, angle, nullptr, flip);

	SetFlip(flip);
}

void Texture2D::SetWidth(int width)
{
	m_Width = width;
}

void Texture2D::SetHeight(int height)
{
	m_Height = height;
}

void Texture2D::SetFlip(SDL_RendererFlip flip)
{
	m_Flip = flip;
}
