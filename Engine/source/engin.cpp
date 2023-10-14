#include "engin.h"
#include "SDL.h"
#include <time.h>
#include "SDLInput.h"
#include "Windows.h"
#include "FileLogger.h"
#include "ConsoleLogger.h"
#include "SDLGraphics.h"
#include "SDLAudio.h"

//static SDL_Renderer* _renderer = NULL;
//static SDL_Window* _window = NULL;

using namespace homer;
/// <summary>
/// Function init where everything is initialise
/// </summary>
/// <param name="name"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <returns></returns>
bool Engin::Init(const char* name, int w, int h) {
	
	m_Input = new SdlInput();
	m_IsInit = true;
	m_Graphics = new SDLGraphics();
	m_Audio = new SDLAudio();
	m_Graphics->Initialize(name, w, h);

	// la music ne marche pas?
	//m_Audio->PlayMusic(m_Audio->LoadMusic("assets/Coin.wav"));

#ifdef _DEBUG
	m_Logger = new ConsoleLogger();
#endif

#ifdef NDEBUG
	m_Logger = new FileLogger();
#endif
	return true;
}
/// <summary>
/// Function Start with the delta time and the 60 fps
/// </summary>
/// <param name=""></param>
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

		float elapse = (_end - _start) * 16.666f * 0.001f;
		if(elapse > 0)
		{
			Sleep(static_cast<DWORD>(elapse));
		}
		_end = _start;
		
	}
	
	ShutDown();
}
/// <summary>
/// Where the input are call
/// </summary>
/// <param name=""></param>
void Engin::ProcessInput(void)
{
	m_Input->Update();
}

static float x = 0.0f;
static float y = 0.0f;
static float speed = 100;
/// <summary>
/// Where everuthing is updated
/// </summary>
/// <param name="dt"></param>
void Engin::Update(float dt)
{
	if (m_Input->IsKeyDown(7)) {
		x += speed * dt;
		m_Audio->PlaySFX(m_Audio->LoadSound("assets/Coin.wav"));
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
/// <summary>
/// Render the texture,string and the rectangle
/// </summary>
/// <param name=""></param>
void Engin::Render(void)
{
	m_Graphics->Clear();
	RectF _carre;
	_carre.x = 0;
	_carre.y = 0;
	_carre.h = 500;
	_carre.w = 500;

	m_Graphics->DrawTexture(m_Graphics->LoadTexture("assets/Candle.png"), _carre,Color::Red);
	m_Graphics->DrawString("allo", m_Graphics->LoadFont("assets/Happy.ttf",50),60,60,Color::Blue);
	m_Graphics->DrawRect(static_cast<int>(x), static_cast<int>(y), 100, 100, Color::Red);

	m_Graphics->Present();
}
/// <summary>
/// Close the engine
/// </summary>
void Engin::Quit()
{
	m_IsRunning = false;
}
/// <summary>
/// Shutdown everything
/// </summary>
/// <param name=""></param>
void Engin::ShutDown(void)
{
	m_IsRunning = false;
	//SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();
}
