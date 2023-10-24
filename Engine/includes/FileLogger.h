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

		virtual void LogMessage(const std::string& message) override;
        virtual void LogError(const std::string& message) override;
        virtual void LogWarning(const std::string& message) override;
	private:
		std::ofstream m_LogFile;
	};
}