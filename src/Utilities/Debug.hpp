#ifndef _LOGGER
#define _LOGGER

#include "Header.hpp"

namespace Tolik
{
enum class LogType
{
  Debug = 0,
  Info,
  Warning,
  Error
};

class Debug
{
public:
  using PaternType = std::vector<std::pair<std::string, std::function<void(void)>>>;

  Debug();

  template<typename... Args> inline void Log    (const std::string &format, Args&&... args) { m_sender = 1; m_logType = LogType::Debug;   LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void Warning(const std::string &format, Args&&... args) { m_sender = 1; m_logType = LogType::Warning; LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void Error  (const std::string &format, Args&&... args) { m_sender = 1; m_logType = LogType::Error;   LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void Info   (const std::string &format, Args&&... args) { m_sender = 1; m_logType = LogType::Info;    LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }

  template<typename... Args> inline void CoreInfo(const std::string &format, Args&&... args)    { m_sender = 1; m_logType = LogType::Info;    LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void CoreWarning(const std::string &format, Args&&... args) { m_sender = 1; m_logType = LogType::Warning; LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void CoreError(const std::string &format, Args&&... args)   { m_sender = 1; m_logType = LogType::Error;   LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  
  void SetPattern(const std::string &newPatern);
  void ResetPattern();
private:
  void LogInfo(const PaternType &patern);
  inline void PrintTime();

  template<typename... Args> void LogMessage(const std::string &format, Args&&... args);
  template<typename T, typename... Args> void Iterate(std::vector<std::string> &container, T &&t, Args&&... args);
  void inline Iterate(std::vector<std::string> &container) {}
 
  template<typename T, typename... Args> void Print(T &&t, Args&&... args);
  template<typename... Args> void Print(uint8_t t, Args&&... args) { Print(static_cast<int>(t), args...); }
  template<typename... Args> void Print(uint16_t t, Args&&... args) { Print(static_cast<int>(t), args...); }
  template<typename... Args> void Print(uint32_t t, Args&&... args) { Print(static_cast<int>(t), args...); }
  template<typename... Args> void Print(uint64_t t, Args&&... args) { Print(static_cast<int>(t), args...); }
  void Print() {}


  LogType m_currentLogType = LogType::Debug;
  LogType m_logType = LogType::Debug;
  int m_sender = 0;
  HANDLE m_hConsole;
  std::ostringstream m_stream;
  PaternType m_patern;
  PaternType m_postPatern;
  const std::unordered_map<char, std::function<void(void)>> m_paternIdentifier;

  
  static const std::unordered_map<LogType, std::string> LogTypeName;
  static const std::unordered_map<LogType, uint32_t> LogTypeColor;
  static const std::string numbers;
};

// template functions

template<typename T, typename... Args> void Debug::Print(T &&t, Args&&... args)
{
  std::cout << std::move(t);
  Print(args...);
}

template<typename T, typename... Args> void Debug::Iterate(std::vector<std::string> &container, T &&t, Args&&... args)
{
  m_stream << std::move(t);
  container.push_back(m_stream.str());
  m_stream.str(std::string());
  Iterate(container, args...);
}


template<typename... Args> void Debug::LogMessage(const std::string &format, Args&&... args)
{
  std::vector<std::string> convertedArguments;
  Iterate(convertedArguments, args...);

  uint32_t lastPos = 0;
  uint32_t position = format.find('@', 0);

  if (position == std::string::npos)
  {
    Print(format, args...);
    return;
  }

  for (; position != std::string::npos; position++, position = format.find('@', position))
  {
    uint32_t numberLength = 0;
    while (numbers.find(format[position + numberLength + 1]) != std::string::npos) numberLength++;
    if (numberLength == 0)
      continue;
    
    Print(format.substr(lastPos, position - lastPos));
    
    //we know that std::stoi won't fail because number length shows us that it is numbers
    int index = std::stoi(format.substr(position + 1, numberLength));
    if (index < static_cast<int>(convertedArguments.size()) && index >= 0)
      Print(convertedArguments[index]);
    
    lastPos = position + numberLength + 1;
  }
}
}

#endif