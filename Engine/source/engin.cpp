#include "engin.h"
#include "SDL.h"
#include <time.h>
#include "SDLInput.h"
#include "Window.h"

static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;
using namespace homer;
bool Engin::Init(const char* name, int w, int h) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log(SDL_GetError());
		return false; 
		
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_TOOLTIP;
	_window = SDL_CreateWindow(name, _x, _y, w, h, _flag);
	if (!_window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	Uint32 _flag2 = SDL_RENDERER_ACCELERATED;
	_renderer = SDL_CreateRenderer(_window, -1, _flag2);

	if (!_renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}
	m_Input = new SdlInput();
	m_IsInit = true;

	return true;
}

void Engin::Start(void) {
	if (!m_IsInit) {
		if (!Init("Unknow title",800,600)) {
			return;
		}
	}
	m_IsRunning = true;
	clock_t _end = clock();

	while (m_IsRunning) {
		const clock_t _start = clock();
		float dt = (_start - _end) * 0.001f;
		ProcessInput();
		Update(dt);
		Render();

		_end = _start;
	}
	//ShutDown();
}

void Engin::ProcessInput(void)
{
	m_Input->Update();

}

static float x = 0.0f;
static float y = 0.0f;
void Engin::Update(float dt)
{
	if (m_Input->IsKeyDown(SDL_SCANCODE_D)) {
		x += 100 * dt;
	}
	if (m_Input->IsKeyDown(SDL_SCANCODE_A)) {
		x -= 100 * dt;
	}
	if (m_Input->IsKeyDown(SDL_SCANCODE_W)) {
		y += 100 * dt;
	}
	if (m_Input->IsKeyDown(SDL_SCANCODE_S)) {
		y -= 100 * dt;
	}
}

void Engin::Render(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = 100;
	get_rect.h = 100;
	get_rect.w = 100;
	SDL_RenderDrawRect(_renderer,&get_rect);

	SDL_RenderPresent(_renderer);
}

void Engin::ShutDown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
