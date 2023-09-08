#pragma once

#include <string>
#include "IInput.h"
namespace homer {
	class Engin final {
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() { return *m_Input; };
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void ShutDown(void);

	private:
		IInput* m_Input;
		bool m_IsRunning = false;
		bool m_IsInit = false;
	};
}