#pragma once
#include <string>
#include "IInput.h"
#include "ILogger.h"


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

		}

		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() { return *m_Input; };
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void ShutDown(void);
		ILogger& Logger() { return *m_Logger; }
	private:
		IInput* m_Input;
		bool m_IsRunning = false;
		bool m_IsInit = false;
		ILogger* m_Logger = nullptr;
	};
}