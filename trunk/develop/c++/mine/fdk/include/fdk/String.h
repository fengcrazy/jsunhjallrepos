#ifndef __FDK_STRING_H_INCLUDE
#define __FDK_STRING_H_INCLUDE
#include "Base.h"
#include <string>

namespace fdk
{	
	FDK_API std::string format(const char* fmt, ...);
	FDK_API void format_out(std::string& output, const char* fmt, ...);	
	FDK_API size_t replace(std::string& s, const std::string& from, const std::string& to);
}

#endif
