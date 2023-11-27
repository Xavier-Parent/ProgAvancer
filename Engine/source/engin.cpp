#pragma once
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
#include "SpriteRenderer.h"
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
	if (m_Input->IsKeyDown(EKey::EKEY_KP_ENTER))
	{
		m_World->Load("Game Scene");
	}
	if (m_Input->IsKeyDown(EKey::EKEY_1))
	{
		//m_Graphics->FillRect(100, 100, 10, 10, Color::Red);

		Entity* pacMan = m_World->Create("pacMan");
		pacMan->AddComponent<SpriteRenderer>()->Init("assets/sprite/pacman1.png", 500, 500);
	}

	if (m_Input->IsKeyDown(EKey::EKEY_ESCAPE))
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
	m_World->Update(dt);

#ifdef _DEBUG
	if (m_Input->IsKeyDown(EKey::EKEY_ESCAPE))
	{
		ShutDown();
	}
#endif	
}

void Engin::Render(void)
{
	m_Graphics->Clear();
	m_World->Draw();
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
