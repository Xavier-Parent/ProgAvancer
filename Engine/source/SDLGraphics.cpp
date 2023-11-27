#include "SDLGraphics.h"

SDLGraphics::SDLGraphics()
{
}

void SDLGraphics::DrawLine(int x0, int y0, int x1, int y1)
{
    SDL_RenderDrawLine(m_Renderer, x0, y0, x1, y1);
}

bool SDLGraphics::Initialize(const std::string& title, int w, int h)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log(SDL_GetError());
		return false;

	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_TOOLTIP;
	m_Window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, _flag);
	if (!m_Window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	Uint32 _flag2 = SDL_RENDERER_ACCELERATED;
	m_Renderer = SDL_CreateRenderer(m_Window, -1, _flag2);

	if (!m_Renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

    TTF_Init();
    return true;
}

void SDLGraphics::Shutdown()
{
	SDL_DestroyWindow(m_Window);
    TTF_Quit();
}

void SDLGraphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
}

void SDLGraphics::Clear()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
}

void SDLGraphics::Present()
{
	SDL_RenderPresent(m_Renderer);
}

void SDLGraphics::DrawRect(int x, int y, int w, int h, const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
    SDL_Rect _rect = { x, y, w, h };
    SDL_RenderDrawRect(m_Renderer, &_rect);
}

void SDLGraphics::DrawRect(const RectF& rect, const Color& color)
{
	DrawRect(static_cast<int>(rect.x), static_cast<int>(rect.y), static_cast<int>(rect.w), static_cast<int>(rect.h), color);
}

void SDLGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
	SDL_Rect _rect = {
		static_cast<int>(x),
		static_cast<int>(y),
	static_cast<int>(w),
	static_cast<int>(h) };

	SetColor(color);

	SDL_RenderFillRect(m_Renderer, &_rect);
}

void SDLGraphics::FillRect(const RectF& rect, const Color& color)
{
	FillRect(rect.x, rect.y, rect.w, rect.h, color);
}

void SDLGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	SetColor(color);
	SDL_RenderDrawLine(m_Renderer,
		static_cast<int>(x1),
		static_cast<int>(y1),
		static_cast<int>(x2),
		static_cast<int>(y2));
}

size_t SDLGraphics::LoadTexture(const std::string& filename)
{
	const size_t id = std::hash<std::string>()(filename);

	if (m_TextureMap.count(id) > 0)
	{
		return id;
	}
    SDL_Texture* _texture = IMG_LoadTexture(m_Renderer, filename.c_str());
	if (_texture != NULL)
	{
		m_TextureMap[id] = _texture;
	}

    return id;
}

void SDLGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	SDL_Rect _src = {
	static_cast<int>(src.x),
	static_cast<int>(src.y),
	static_cast<int>(src.w),
	static_cast<int>(src.h) };

	SDL_Rect _dst = {
	static_cast<int>(dst.x),
	static_cast<int>(dst.y),
	static_cast<int>(dst.w),
	static_cast<int>(dst.h) };

	int _flip = SDL_FLIP_NONE;
	if (flip.h)
	{
		_flip = SDL_FLIP_HORIZONTAL;
	}

	if (flip.v)
	{
		_flip |= SDL_FLIP_VERTICAL;
	}

	const SDL_RendererFlip _rf = static_cast<SDL_RendererFlip>(_flip);

	SetColorMode(id, color);
	SDL_RenderCopyEx(m_Renderer, m_TextureMap[id], &_src, &_dst, angle, nullptr, _rf);
}

void SDLGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	if (m_TextureMap.count(id) > 0)
	{
		SDL_Rect* _destination = new SDL_Rect();
		_destination->x = static_cast<int>(dst.x);
		_destination->y = static_cast<int>(dst.y);
		_destination->w = static_cast<int>(dst.w);
		_destination->h = static_cast<int>(dst.h);

		SDL_Rect* _rect = new SDL_Rect();
		GetTextureSize(id, &_rect->w, &_rect->h);
		SDL_RenderCopy(m_Renderer, m_TextureMap[id],_rect ,_destination );
	}
}

void SDLGraphics::DrawTexture(size_t id, const Color& color)
{
	SetColorMode(id, color);
	SDL_RenderCopy(m_Renderer, m_TextureMap[id], nullptr, nullptr);
}

void SDLGraphics::GetTextureSize(size_t id, int* w, int* h)
{
	if (m_TextureMap.count(id) > 0)
	{
		SDL_Texture* _tex = m_TextureMap[id];
		SDL_QueryTexture(_tex, nullptr, nullptr, w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}

size_t SDLGraphics::LoadFont(const std::string& filename, int fontSize)
{
	const size_t id = std::hash<std::string>()(filename);

	if (m_FontMap.count(id) > 0)
	{
		return id;
	}
	TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
	if (_font != NULL)
	{
		m_FontMap[id] = _font;
	}
	return id;
}

void SDLGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
	if (m_FontMap.count(fontId) > 0)
	{
		SDL_Rect* _destination = new SDL_Rect();
		_destination->x = static_cast<int>(x);
		_destination->y = static_cast<int>(y);
		GetTextSize(text,fontId,&_destination->w,&_destination->h);
		SDL_Color* _color = new SDL_Color();
		_color->r = color.red;
		TTF_Font* _font = m_FontMap[fontId];
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), *_color);
		m_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);
		SDL_RenderCopy(m_Renderer, m_TextureBuffer, nullptr, _destination);
		SDL_FreeSurface(_surface);
		SDL_DestroyTexture(m_TextureBuffer);
	}
}

void SDLGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
	if (m_FontMap.count(fontId) > 0)
	{
		TTF_Font* fontText = m_FontMap[fontId];
		TTF_SizeText(fontText, text.c_str(), w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}

void SDLGraphics::SetColorMode(size_t id, const Color& color)
{
	SDL_Texture* _tex = m_TextureMap[id];
	SDL_SetTextureBlendMode(_tex, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(_tex, color.alpha);
	SDL_SetTextureColorMod(_tex, color.red, color.green, color.blue);
}
