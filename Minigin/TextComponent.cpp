#include "MiniginPCH.h"
#include "Renderer.h"
#include "TextComponent.h"
#include "Texture2D.h"

proxy::TextComponent::TextComponent(const std::string& txt, const std::shared_ptr<Font> font, const Float4& col)
	:TextureComponent()
	, m_Text(txt), m_pFont(font), m_Color(col)
{
}

std::string proxy::TextComponent::GetText() const
{
	return m_Text;
}

void proxy::TextComponent::SetText(const std::string& txt)
{
	m_Text = txt;
}

proxy::Font& proxy::TextComponent::GetFont() const
{
	return *m_pFont;
}

void proxy::TextComponent::SetFont(const std::shared_ptr<Font>& font)
{
	m_pFont = font;
}

proxy::Float4 proxy::TextComponent::GetColor() const
{
	return m_Color;
}

void proxy::TextComponent::SetColor(const Float4& col)
{
	m_Color = col;
}

void proxy::TextComponent::Texture()
{
	SDL_Color col = {
		Uint8(m_Color._x * 255.0f),
		Uint8(m_Color._y * 255.0f),
		Uint8(m_Color._z * 255.0f)
	};

	// Surface Render
	auto render = TTF_RenderText_Blended(m_pFont->GetFont(), m_Text.c_str(), col);
	if (!render)
	{throw SDL_GetError();}
	
	// Texture creation
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), render);
	if (!texture)
	{throw SDL_GetError();}

	SDL_FreeSurface(render);
	m_pTexture2D = std::make_shared<Texture2D>(texture);
}

void proxy::TextComponent::Update()
{
}
