#include "MiniginPCH.h"
#include "Font.h"

TTF_Font* proxy::Font::GetFont() const {
	return mFont;
}

proxy::Font::Font(const std::string& fullPath, unsigned size) : mFont(nullptr), mSize(size)
{
	mFont = TTF_OpenFont(fullPath.c_str(), size);
	if (mFont == nullptr) 
	{
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
	}
}

proxy::Font::~Font()
{
	TTF_CloseFont(mFont);
}
