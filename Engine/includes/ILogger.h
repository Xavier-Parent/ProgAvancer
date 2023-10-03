#pragma once


namespace homer {

	class ILogger {
	public:
		virtual ~ILogger() = default;
		virtual void Log(const char* message) = 0;
	};
}
