#pragma once
#include <string>
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IAudio.h"

namespace homer {
	class Engin final {
	public:
		static Engin* Get()
		{
			static Engin* m_Instance;
			if (m_Instance == nullptr)
			{
				m_Instance = new Engin();
			}
			return m_Instance;
		}

		bool Init(const char* name, int w, int h);
		void Quit();
		void Start(void);
		IInput& Input() const { return *m_Input; };
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void ShutDown(void);
		ILogger& Logger() { return *m_Logger; }
	private:
		bool m_IsRunning = false;
		IInput* m_Input = nullptr;
		bool m_IsInit = false;
		ILogger* m_Logger = nullptr;
		IGraphics* m_Graphics = nullptr;
		IAudio* m_Audio = nullptr;
	};
}