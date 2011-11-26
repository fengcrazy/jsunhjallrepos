#ifndef __FDKWIN_ICONV_H_INCLUDE
#define __FDKWIN_ICONV_H_INCLUDE
#include "Base.h"
#include <string>

namespace fdkwin
{
	// 本模块的unicode都是指utf16
	FDKWIN_API void ansi_to_unicode(std::wstring& output, const std::string& input);
	FDKWIN_API void unicode_to_ansi(std::string& output, const std::wstring& input);
	FDKWIN_API void utf8_to_unicode(std::wstring& output, const std::string& input);
	FDKWIN_API void unicode_to_utf8(std::string& output, const std::wstring& input);
	FDKWIN_API void ansi_to_utf8(std::string& output, const std::string& input);
	FDKWIN_API void utf8_to_ansi(std::string& output, const std::string& input);
}

#endif
