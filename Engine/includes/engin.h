#pragma once
#include <string>
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IAudio.h"
#include "IWorld.h"
#include "ICollider.h"
namespace homer {
	class Engin final {
	public:
		/// <summary>
		/// Singleton of the engine
		/// </summary>
		/// <returns></returns>
		static Engin* Get()
		{
			static Engin* m_Instance;
			if (m_Instance == nullptr)
			{
				m_Instance = new Engin();
			}
			return m_Instance;
		}
		/// <summary>
		/// Function init where everything is initialise
		/// </summary>
		/// <param name="name"></param>
		/// <param name="w"></param>
		/// <param name="h"></param>
		/// <returns></returns>
		bool Init(const char* name, int w, int h);
		/// <summary>
		/// /// Function Start with the delta time and the 60 fps
		/// </summary>
		/// <param name=""></param>
		void Start(void);
		IAudio& Audio() const { return *m_Audio;  }
		IInput& Input() const { return *m_Input; }
		ILogger& Logger() const { return *m_Logger; }
		IWorld& World() const { return *m_World; }
		IGraphics& Graphics() const { return *m_Graphics; }
		ICollider& Collider() const { return *m_Collider; }
		/// <summary>
		/// Close the engine
		/// </summary>
		void Quit();
	private:
		void ProcessInput(void);
		/// <summary>
		/// Where everything is updated
		/// </summary>
		/// <param name="dt"></param>
		void Update(float dt);
		/// <summary>
		/// Render the texture,string and the rectangle
		/// </summary>
		/// <param name=""></param>
		void Render(void);
		/// <summary>
		/// Shutdown everything
		/// </summary>
		/// <param name=""></param>
		void ShutDown(void);
	private:
		bool m_IsRunning = false;
		IInput* m_Input = nullptr;
		bool m_IsInit = false;
		ILogger* m_Logger = nullptr;
		IGraphics* m_Graphics = nullptr;
		IAudio* m_Audio = nullptr;
		IWorld* m_World = nullptr;
		ICollider* m_Collider = nullptr;
	};
}