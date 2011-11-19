#include <fdk/String.h>
#include <stdarg.h>

namespace fdk
{
	FDK_API std::string format(const char* fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
#pragma warning(disable: 4996)
		vsnprintf(__buffer__, __bufferSize__, fmt, ap);
#pragma warning(default: 4996)
		va_end(ap);
		return __buffer__;	
	}

	FDK_API void format_out(std::string& output, const char* fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
#pragma warning(disable: 4996)
		vsnprintf(__buffer__, __bufferSize__, fmt, ap);
#pragma warning(default: 4996)
		va_end(ap);
		output = __buffer__;
	}

	FDK_API size_t replace(std::string& s, const std::string& from, const std::string& to)
	{
		std::string::size_type pos = 0;
		size_t found = 0;
		while (1)
		{
			pos = s.find(from, pos);
			if (pos == std::string::npos)
			{
				break;
			}
			s.replace(pos, from.length(), to);
			pos += from.length();
			++found;
		}
		return found;
	}
}
