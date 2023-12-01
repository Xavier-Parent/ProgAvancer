#include "IInput.h"
namespace homer {
	class SdlInput final : public IInput
	{
	public:
		/// <summary>
		/// Destructor by default
		/// </summary>
		virtual ~SdlInput() = default;
		/// <summary>
		/// Update Function
		/// </summary>
		virtual void Update() override;
		/// <summary>
		/// Function to recognise the key pressed on the keyboard
		/// </summary>
		/// <param name="key">The name of the key that is pressed</param>
		/// <returns></returns>
		virtual bool IsKeyDown(EKey keycode) override;
		/// <summary>
		/// Function to recognise the mouse button
		/// </summary>
		/// <param name="button">Button of the mouse that is pressed</param>
		/// <returns></returns>
		virtual bool IsButtonDown(int button) override;
		/// <summary>
		/// Function to get the mouse position in the scene
		/// </summary>
		/// <param name="x">Horizontal position of the mouse</param>
		/// <param name="y">Vertical position of the mouse</param>
		virtual void GetMousePosition(int* x, int* y) override;
	private:
		const unsigned char* m_KeyStates = nullptr;
		int m_MouseX = 0;
		int m_MouseY = 0;
		bool m_MouseStates[3]{ false, false, false };
	};
}
