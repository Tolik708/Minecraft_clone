#include "Debug.hpp"

#include "Header.hpp"

namespace Tolik
{
const std::unordered_map<LogType, std::string> Debug::LogTypeName = 
{
  { LogType::Debug,   "DEBUG" },
  { LogType::Info,    "INFO" },
  { LogType::Warning, "WARNING" },
  { LogType::Error,   "ERROR" }
};
const std::unordered_map<LogType, uint32_t> Debug::LogTypeColor = 
{
  { LogType::Debug,   0 },
  { LogType::Info,    8 },
  { LogType::Warning, 14 },
  { LogType::Error,   12 }
};
const std::string Debug::numbers = "0123456789";

Debug::Debug() : m_paternIdentifier
({
  { 'T', [this]() { return PrintTime(); } }
})
{
	ResetPattern();
  m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}


void Debug::LogInfo(const PaternType &patern)
{
	for (uint32_t i = 0; i < patern.size(); i++)
	{
		Print(patern[i].first);
		if (patern[i].second != nullptr)
			patern[i].second();
	}
}

inline void Debug::PrintTime()
{
	std::time_t seconds = time(NULL);
	std::tm *buf = localtime(&seconds);
	Print(std::put_time(buf, "%H:%M:%S"));
}


void Debug::SetPattern(const std::string &newPatern)
{
	PaternType *patern = &m_patern;
	uint32_t paternIndex = 0;
	bool message = false;

	patern->clear();
	patern->emplace_back();
	for (uint32_t stringPos = 0; stringPos < newPatern.length(); stringPos++)
	{
		if (newPatern[stringPos] == '@')
		{
			if (stringPos + 1 >= newPatern.length())
			{
				(*patern)[paternIndex].first += newPatern[stringPos];
				break;
			}

			if(newPatern[stringPos + 1] == 'M' && !message)
			{
				patern = &m_postPatern;
				patern->clear();
				patern->emplace_back();
				paternIndex = 0;
				stringPos++;
				message = true;
				continue;
			}

			std::unordered_map<char, std::function<void(void)>>::const_iterator it = m_paternIdentifier.find(newPatern[stringPos + 1]);
			if (it != m_paternIdentifier.end()) 
			{
				(*patern)[paternIndex].second = it->second;
				patern->emplace_back();
				paternIndex++;
				stringPos++;
				continue;
			}
		}
		(*patern)[paternIndex].first += newPatern[stringPos];
	}
}
void Debug::ResetPattern()
{
	SetPattern("[@T] @M\n");
}
}