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
		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

bool SdlInput::IsKeyDown(int keycode)
{
	return m_KeyStates[keycode];
}

bool SdlInput::IsButtonDown(int button)
{
    return false;
}

void SdlInput::GetMousePosition(int* x, int* y)
{
}
