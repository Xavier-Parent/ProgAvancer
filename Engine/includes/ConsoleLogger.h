#pragma once
#include "ILogger.h"

namespace homer {

class ConsoleLogger : public ILogger {
public:
	/// <summary>
	/// Constructor 
	/// </summary>
	ConsoleLogger();
	/// <summary>
	/// Destructor
	/// </summary>
	~ConsoleLogger();
	/// <summary>
	/// Function to log message
	/// </summary>
	/// <param name="message">The message write in the Console logger</param>
	virtual void LogMessage(const std::string& message) override;
	/// <summary>
	/// Function to Write error in the log
	/// </summary>
	/// <param name="message">The message write in the Console logger</param>
	virtual void LogError(const std::string& message) override;
	/// <summary>
	/// Function to Write Warning in the log
	/// </summary>
	/// <param name="message">The message write in the Console logger</param>
	virtual void LogWarning(const std::string& message) override;
private:

};
}