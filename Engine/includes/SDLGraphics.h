#pragma once
#include "IGraphics.h"
#include "SDL_image.h"
#include <map>
#include "SDL_ttf.h"
class SDLGraphics : public IGraphics
{
public:

	SDLGraphics();
	virtual void DrawLine(int x0, int y0, int x1, int y1) override;

	virtual bool Initialize(const std::string& title, int w, int h) override;

	virtual void Shutdown() override;

	virtual void SetColor(const Color& color) override;

	virtual void Clear() override;

	virtual void Present() override;

	virtual void DrawRect(int x, int y, int w, int h, const Color& color) override;

	virtual void DrawRect(const RectF& rect, const Color& color) override;

	virtual void FillRect(float x, float y, float w, float h, const Color& color) override;

	virtual void FillRect(const RectF& rect, const Color& color) override;

	virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;

	virtual size_t LoadTexture(const std::string& filename) override;

	virtual void DrawTexture(size_t id, const RectF& src, const RectF& dst, double angle, const Flip& flip, const Color& color) override;

	virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;

	virtual void DrawTexture(size_t id, const Color& color) override;

	virtual void GetTextureSize(size_t id, int* w, int* h) override;

	virtual size_t LoadFont(const std::string& filename, int fontSize) override;

	virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) override;

	virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;

private:
	std::map<size_t, SDL_Texture*> m_TextureMap;
	std::map<size_t, TTF_Font*> m_FontMap;

	void SetColorMode(size_t id, const Color& color);
	SDL_Renderer* m_Renderer = nullptr;
	SDL_Window* m_Window = nullptr;
	SDL_Texture* m_TextureBuffer = nullptr;

};

