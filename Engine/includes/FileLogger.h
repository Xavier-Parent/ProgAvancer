#pragma once
#include "ILogger.h"
#include <iostream>
#include <fstream>

namespace homer
{
	class FileLogger : public ILogger
	{
	public:
		FileLogger();
		~FileLogger();
		virtual void Log(const char* message);
	private:
		std::ofstream MyFile;
	};
}