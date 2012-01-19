#ifndef __FDK_MISC_H_INCLUDE
#define __FDK_MISC_H_INCLUDE
#include "Base.h"
#include <stdlib.h>
#include <string>

namespace fdk
{
	inline bool isBigEndian()
	{
		int n = 1;
		return *(char*)&n == 0;
	}
	
	// 需要先调srand(time(0));
	template <class T>
	inline T rand(const T& a, const T& b)
	{
		const T& minVal = minValue(a, b);
		const T& maxVal = maxValue(a, b);
		return (::rand()/RAND_MAX+1.0)*(maxValue-minVal+1) + minVal;
	}

	FDK_API const char* toHexString(byte_t c);
	FDK_API std::string toHexString(const void* buffer, size_t size);
}

#endif
