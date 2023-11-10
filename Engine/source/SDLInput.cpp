#include "SDLInput.h"
#include <SDL.h>
#include "engin.h"

using namespace homer;
void SdlInput::Update()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			homer::Engin::Get()->Quit();
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			m_MouseStates[_buttonDown.button] = true;
			break;

		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			m_MouseStates[_buttonUp.button] = true;
			break;

		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			m_MouseX = _motion.x;
			m_MouseY = _motion.y;
			break;

		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

bool SdlInput::IsKeyDown(EKey keycode)
{
	if (m_KeyStates != nullptr)
	{
		return m_KeyStates[static_cast<int>(keycode)] == 1;
	}

	return false;
}

bool SdlInput::IsButtonDown(int button)
{
	return m_MouseStates[button];
}

void SdlInput::GetMousePosition(int* x, int* y)
{
	*x = m_MouseX;
	*y = m_MouseY;
}
