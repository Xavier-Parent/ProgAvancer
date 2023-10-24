#pragma once
#include "ILogger.h"

namespace homer {

class ConsoleLogger : public ILogger {
public:
	ConsoleLogger();
	~ConsoleLogger();

	virtual void LogMessage(const std::string& message) override;
	virtual void LogError(const std::string& message) override;
	virtual void LogWarning(const std::string& message) override;
private:

};
}