#ifndef __FDKWIN_FINDFILE_H_INCLUDE__
#define __FDKWIN_FINDFILE_H_INCLUDE__
#include "Base.h"

namespace fdkwin
{	
	class FDKWIN_API FindFileHandler
	{
	public:
		virtual void handleDirectory(const WIN32_FIND_DATA& findData) = 0;
		virtual void handleFile(const WIN32_FIND_DATA& findData) = 0;
	};

	// 处理非.和..的文件(夹)，若存在这样的文件(夹)则返回true
	FDKWIN_API bool findFile(const CString& pattern, FindFileHandler& handler);
}

#endif
