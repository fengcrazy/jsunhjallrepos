#ifndef __FDK_RANGE_H_INCLUDE
#define __FDK_RANGE_H_INCLUDE

namespace fdk
{
	template <class T>
	class MinMaxRange
	{
		MinMaxRange();
		MinMaxRange(const T& l_min, const T& l_max);
		void reset(const T& l_min, const T& l_max);
		bool inRange(const T& o) const;
		T m_min;
		T m_max;
	};

	template <class T>
	inline MinMaxRange<T>::MinMaxRange()
		: m_min()
		, m_max()
	{
	}

	template <class T>
	inline MinMaxRange<T>::MinMaxRange(const T& l_min, const T& l_max)
		: m_min(l_min)
		, m_max(l_max)
	{
	}

	template <class T>
	inline void fdk::MinMaxRange<T>::reset(const T& l_min, const T& l_max)
	{
		m_min = l_min;
		m_max = l_max;
	}

	template <class T>
	inline bool fdk::MinMaxRange<T>::inRange(const T& o) const
	{
		return o >= m_min && o <= m_max;
	}
};

#endif
