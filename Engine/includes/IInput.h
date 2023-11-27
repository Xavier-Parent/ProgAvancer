#pragma once

namespace homer{
	enum class EKey {
		EKEY_A = 4,
		EKEY_D = 7,
		EKEY_S = 22,
		EKEY_W = 26,

		EKEY_1 = 30,
		EKEY_2 = 31,
		EKEY_3 = 32,
		EKEY_4 = 33,
		EKEY_5 = 34,
		EKEY_6 = 35,
		EKEY_7 = 36,
		EKEY_8 = 37,
		EKEY_9 = 38,
		EKEY_0 = 39,

		EKEY_RETURN = 40,
		EKEY_ESCAPE = 41,
		EKEY_BACKSPACE = 42,
		EKEY_SPACE = 44,
		EKEY_TAB = 43,
		EKEY_RIGHT = 79,
		EKEY_LEFT = 80,
		EKEY_DOWN = 81,
		EKEY_UP = 82,
		EKEY_KP_ENTER = 88,
	};

	class IInput
	{
	public:
		/// <summary>
		/// Destructor by default
		/// </summary>
		virtual ~IInput() = default;
		/// <summary>
		/// Function to recognise the key pressed on the keyboard
		/// </summary>
		/// <param name="key">The name of the key that is pressed</param>
		/// <returns></returns>
		virtual bool IsKeyDown(EKey key) = 0;
		/// <summary>
		/// Function to recognise the mouse button
		/// </summary>
		/// <param name="button">Button of the mouse that is pressed</param>
		/// <returns></returns>
		virtual bool IsButtonDown(int button) = 0;
		/// <summary>
		/// Function to get the mouse position in the scene
		/// </summary>
		/// <param name="x">Horizontal position of the mouse</param>
		/// <param name="y">Vertical position of the mouse</param>
		virtual void GetMousePosition(int* x, int* y) = 0;
	protected:

		friend class Engin;
		virtual void Update() = 0;
	};
}
