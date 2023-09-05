#pragma once

#include <string>
namespace homer {
	class engin final {
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void ShutDown(void);

	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;
	};
}