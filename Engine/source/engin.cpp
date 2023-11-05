#include "engin.h"
#include "SDL.h"
#include <time.h>
#include "SDLInput.h"
#include "Windows.h"
#include "FileLogger.h"
#include "ConsoleLogger.h"
#include "SDLGraphics.h"
#include "SDLAudio.h"
#include "WorldService.h"

using namespace homer;
bool Engin::Init(const char* name, int w, int h) {
	
	m_Input = new SdlInput();
	m_IsInit = true;
	m_Graphics = new SDLGraphics();
	m_Audio = new SDLAudio();
	m_Graphics->Initialize(name, w, h);
	m_World = new WorldService();

#ifdef _DEBUG
	m_Logger = new ConsoleLogger();
#endif

#ifdef NDEBUG
	m_Logger = new FileLogger("engin.log");
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
	const int TARGET_FPS = 60;
	const int MS_PER_FRAME = 1000 / TARGET_FPS;
	while (m_IsRunning) {
		const clock_t _start = clock();
		float _dt = (_start - _end) * 0.001f;
		ProcessInput();
		Update(_dt);
		Render();

		int _restTime = _start + MS_PER_FRAME - clock();
		if (_restTime > 0)
		{
			Sleep(_restTime);
		}
		_end = _start;
		
	}
	
	ShutDown();
}

void Engin::ProcessInput(void)
{
	m_Input->Update();
#if _DEBUG
	if (m_Input->IsKeyDown(41))
	{
		Quit();
	}
#endif
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
		//BackSpace
		
		m_Audio->PlaySFX(m_Audio->LoadSound("assets/Coin.wav"));

	}
	if (m_Input->IsKeyDown(44)) {
		//Space
		//m_Audio->PlaySFX(m_Audio->LoadSound("assets/Coin.wav"));
		m_Audio->PlaySFX(m_Audio->LoadSound("assets/Error.mp3"));
		m_Audio->PlayMusic(m_Audio->LoadMusic("assets/Victory.mp3"));
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
	m_Graphics->Clear();
	RectF _carre;
	_carre.x = 0;
	_carre.y = 0;
	_carre.h = 500;
	_carre.w = 500;

	m_Graphics->DrawTexture(m_Graphics->LoadTexture("assets/sprite/Candle.png"), _carre,Color::Red);
	m_Graphics->DrawString("allo", m_Graphics->LoadFont("assets/Happy.ttf",50),60,60,Color::Blue);
	m_Graphics->DrawRect(static_cast<int>(x), static_cast<int>(y), 100, 100, Color::Red);

	m_Graphics->Present();
}

void Engin::Quit()
{
	m_IsRunning = false;
}

void Engin::ShutDown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}

	if (m_Audio != nullptr)
	{
		delete m_Audio;
	}

	if (m_Graphics != nullptr)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
	}

	if (m_Logger != nullptr)
	{
		delete m_Logger;
	}
	SDL_Quit();
}
