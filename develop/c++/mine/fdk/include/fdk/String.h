#ifndef __FDK_STRING_H_INCLUDE__
#define __FDK_STRING_H_INCLUDE__
#include "Base.h"
#include <string>
#include <sstream>

namespace fdk
{	
	FDK_API void trim(std::string& s);
	FDK_API std::string trim_copy(const std::string& s);
	FDK_API std::string format(const char* fmt, ...);
	FDK_API void format_out(std::string& output, const char* fmt, ...);	
	FDK_API size_t replace(std::string& s, const std::string& from, const std::string& to);

	template <class T>
	bool toType(T& output, const std::string & s)
	{
		std::stringstream ss;
		ss << s;
		if (!(ss >> output))
		{
			return false;
		}
		char c;
		return !ss.get(c);
	};

	template <class T>
	bool isType(const std::string & s)
	{
		T t;
		return toType(t, s);
	};
}

#endif
