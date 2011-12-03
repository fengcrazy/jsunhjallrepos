#ifndef __FDK_BASE_H_INCLUDE
#define __FDK_BASE_H_INCLUDE

#ifdef FDK_EXPORTS
#define FDK_API __declspec(dllexport)
#else
#define FDK_API __declspec(dllimport)
#endif

#include <memory.h>
#include <assert.h>
#include <string>

namespace fdk
{
	typedef unsigned char byte_t;
	typedef unsigned short word_t;
	typedef unsigned long dword_t;
	typedef unsigned long long qword_t;
	
	//< 基本运算符的自动实现: 需要T实现==和<
	template <class T>
	inline bool operator!=(const T& a, const T& b)
	{
		return !(a == b);
	}

	template <class T>
	inline bool operator>(const T& a, const T& b)
	{
		return b < a;
	}

	template <class T>
	inline bool operator<=(const T& a, const T& b)
	{
		return !(b < a);
	}

	template <class T>
	inline bool operator>=(const T& a, const T& b)
	{
		return !(a < b);
	}
	//>

	inline bool isBigEndian()
	{
		int n = 1;
		return *(char*)&n == 0;
	}

	template <class T>
	inline void zeroMemory(T& o)
	{
		memset(&o, 0, sizeof(T));
	}

	template<class T>
	inline const T& minValue(const T& a, const T& b)
	{
		return (a < b) ? a : b;
	}

	template<class T>
	inline const T& maxValue(const T& a, const T& b)
	{
		return (a > b) ? a : b;
	}
	
	FDK_API const char* toHexString(byte_t c);
	FDK_API std::string toHexString(const void* buffer, size_t size);

	const size_t __bufferSize__ = 1024*256;
	extern FDK_API char __buffer__[__bufferSize__+1];
}

#define FDK_NULL 0

#define FDK_DIM(array) (sizeof(array)/sizeof(*(array)))

#define FDK_DELETE(p) do { delete (p); (p) = NULL; } while(0)
#define FDK_DELETE_ARRAY(array) do { delete [](array); (array) = NULL; } while(0)

#define FDK_ASSERT assert

#define FDK_CMP_PTR(CLASS,NAME)\
	char __cmp_inner_buffer_##NAME[sizeof(CLASS)]; \
	CLASS* NAME = reinterpret_cast<CLASS*>(__cmp_inner_buffer_##NAME);

namespace fdk
{
	template <bool> struct CompileTimeAssert
	{
		CompileTimeAssert(...) {};
	};
	template <> struct CompileTimeAssert<false> 
	{
	};
}

#define FDK_COMPILETIME_ASSERT_MSG(expr, msg) \
	{ \
		class _COMPLIE_ASSERT_FAIL__##msg {} _msg; \
		sizeof((fdk::CompileTimeAssert<expr>)(_msg)); \
	}

#define FDK_COMPILETIME_ASSERT(expr) \
	{ \
		class _COMPLIE_ASSERT_FAIL {} _msg; \
		sizeof((fdk::CompileTimeAssert<expr>)(_msg)); \
	}

#ifdef _MSC_VER
	#ifndef  __PRETTY_FUNCTION__
		#define __PRETTY_FUNCTION__ __FUNCTION__
	#endif
#endif

#endif
