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
    return false;
}

void SDLGraphics::Shutdown()
{
	SDL_DestroyWindow(m_Window);
    TTF_Quit();
}

void SDLGraphics::SetColor(const Color& color)
{
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

void SDLGraphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
    SDL_Rect _rect = { x, y, w, h };
    SDL_RenderDrawRect(m_Renderer, &_rect);
}

void SDLGraphics::DrawRect(const RectF& rect, const Color& color)
{
}

void SDLGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
}

void SDLGraphics::FillRect(const RectF& rect, const Color& color)
{
}

void SDLGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
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

}

void SDLGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	
	if (m_TextureMap.count(id) > 0)
	{
		SDL_Rect* _destination = new SDL_Rect();
		_destination->x = dst.x;
		_destination->y = dst.y;
		_destination->w = dst.w;
		_destination->h = dst.h;

		SDL_Rect* _rect = new SDL_Rect();
		GetTextureSize(id, &_rect->w, &_rect->h);
		SDL_RenderCopy(m_Renderer, m_TextureMap[id],_rect ,_destination );
	}

}

void SDLGraphics::DrawTexture(size_t id, const Color& color)
{
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
		_destination->x = x;
		_destination->y = y;
		GetTextSize(text,fontId,&_destination->w,&_destination->h);
		SDL_Color* _color = new SDL_Color();
		_color->r = color.red;


		TTF_Font* _font = m_FontMap[fontId];
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), *_color);
		g_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);
		SDL_RenderCopy(m_Renderer, g_TextureBuffer, nullptr, _destination);
		SDL_FreeSurface(_surface);
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
