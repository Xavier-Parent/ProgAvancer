#pragma once
#include<string>

namespace homer {

	class ILogger {
	public:
		/// <summary>
		/// Destructor by default
		/// </summary>
		virtual ~ILogger() = default;
		/// <summary>
		/// Function to LogMessage
		/// </summary>
		/// <param name="message">The message to be send in the Logger</param>
		virtual void LogMessage(const std::string& message) = 0;
		/// <summary>
		/// Function log an error
		/// </summary>
		/// <param name="message">The error you want to be put in the Logger</param>
		virtual void LogError(const std::string& message) = 0;
		/// <summary>
		/// Function to log a warning
		/// </summary>
		/// <param name="message">The warning you want to be write in the logger</param>
		virtual void LogWarning(const std::string& message) = 0;
	};
}
