#include "MiniginPCH.h"
#include "Texture2D.h"
#include <SDL.h>

proxy::Texture2D::Texture2D(SDL_Texture* texture)
	: m_Texture(texture)
{
	SDL_QueryTexture(m_Texture, &m_Format, &m_Access, &m_Width, &m_Height);
}

proxy::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

int proxy::Texture2D::GetTextWidth() const
{
	return m_Width;
}

int proxy::Texture2D::GetTextHeight() const
{
	return m_Height;
}

SDL_Texture* proxy::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

