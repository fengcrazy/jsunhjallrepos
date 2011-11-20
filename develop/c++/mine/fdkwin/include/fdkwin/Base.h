#ifndef __FDKWIN_BASE_H_INCLUDE
#define __FDKWIN_BASE_H_INCLUDE

#ifdef FDKWIN_EXPORTS
#define FDKWIN_API __declspec(dllexport)
#else
#define FDKWIN_API __declspec(dllimport)
#endif

#ifndef _AFXDLL
#define _AFXDLL
#endif

#include <afx.h>

namespace fdkwin
{
}

#endif
