#include "engin.h"
#include "SDL.h"
#include <time.h>
#include "SDLInput.h"
#include "Windows.h"
#include "FileLogger.h"
#include "ConsoleLogger.h"

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

#ifdef _DEBUG
	m_Logger = new ConsoleLogger();
#endif

	m_Logger = new FileLogger();
#ifdef NDEBUG
	//mettre le file logger ici ^
#endif
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
		float _dt = (_start - _end) * 0.001f;
		ProcessInput();
		Update(_dt);
		Render();

		float elapse = _end - _start * 16.666f;
		if(elapse < 0)
		{
			Sleep(elapse * 0.001f);
		}
		_end = _start;
		
	}
	ShutDown();
}

void Engin::ProcessInput(void)
{
	m_Input->Update();

}

static float x = 0.0f;
static float y = 0.0f;
static float speed = 100;
void Engin::Update(float dt)
{
	if (m_Input->IsKeyDown(7)) {
		x += speed * dt;
	}
	if (m_Input->IsKeyDown(4)) {
		x -= speed * dt;
	}
	if (m_Input->IsKeyDown(26)) {
		y -= speed * dt;
	}
	if (m_Input->IsKeyDown(22)) {
		y += speed * dt;
	}
	if (m_Input->IsKeyDown(42)) {
		m_Logger->Log("BackSpace");
	}
	if (m_Input->IsKeyDown(44)) {
		m_Logger->Log("SpaceBar");
	}

#ifdef _DEBUG
	if (m_Input->IsKeyDown(41))
	{
		ShutDown();
	}
#endif
	
}

void Engin::Render(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = y;
	get_rect.h = 100;
	get_rect.w = 100;
	SDL_RenderDrawRect(_renderer,&get_rect);

	SDL_RenderPresent(_renderer);
}

void Engin::ShutDown(void)
{
	//if (m_Input != nullptr)
	//{
	//	delete m_Input;
	//}
	m_IsRunning = false;
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
