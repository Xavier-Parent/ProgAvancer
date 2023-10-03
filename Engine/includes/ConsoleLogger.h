#pragma once
#include "ILogger.h"

namespace homer {

class ConsoleLogger : public ILogger {
public:
	ConsoleLogger();
	~ConsoleLogger();
	virtual void Log(const char* message) override;
private:

};
}