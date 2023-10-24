#include "FileLogger.h"

homer::FileLogger::FileLogger()
{
}

homer::FileLogger::~FileLogger()
{
    if (m_LogFile.is_open())
    {
        m_LogFile.close();
    }
}

void homer::FileLogger::LogMessage(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << message << std::endl;
    }
}

void homer::FileLogger::LogError(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << message << std::endl;
    }
}

void homer::FileLogger::LogWarning(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << "WARNING : " << message << std::endl;
    }
}


