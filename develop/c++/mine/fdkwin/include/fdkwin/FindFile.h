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

	// �����.��..���ļ�(��)���������������ļ�(��)�򷵻�true
	FDKWIN_API bool findFile(const CString& pattern, FindFileHandler& handler);
}

#endif
