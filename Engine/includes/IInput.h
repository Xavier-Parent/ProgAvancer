#pragma once

namespace homer{
	enum class EKey {
		EKEY_A = 4,
		EKEY_D = 7,
		EKEY_S = 22,
		EKEY_W = 26,
		EKEY_RETURN = 40,
		EKEY_ESCAPE = 41,
		EKEY_BACKSPACE = 42,
		EKEY_SPACE = 44,
		EKEY_TAB = 43,
		EKEY_RIGHT = 79,
		EKEY_LEFT = 80,
		EKEY_DOWN = 81,
		EKEY_UP = 82,
	};

	class IInput
	{
	public:
		virtual ~IInput() = default;
		virtual bool IsKeyDown(int key) = 0;
		virtual bool IsButtonDown(int button) = 0;
		virtual void GetMousePosition(int* x, int* y) = 0;
	protected:

		friend class Engin;
		virtual void Update() = 0;
	};
}
