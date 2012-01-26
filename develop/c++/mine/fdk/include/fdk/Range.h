#ifndef __FDK_RANGE_H_INCLUDE__
#define __FDK_RANGE_H_INCLUDE__
#include <fdk/Base.h>

namespace fdk
{
	template <class T>
	class MinMaxRange
	{
	public:
		MinMaxRange();
		MinMaxRange(const T& l_min, const T& l_max);
		void reset(const T& l_min, const T& l_max);
		const T& getMin() const;
		const T& getMax() const;
		bool inRange(const T& o) const;
	private:
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
	{
		reset(l_min, l_max);
	}

	template <class T>
	inline void fdk::MinMaxRange<T>::reset(const T& l_min, const T& l_max)
	{
		m_min = minValue(l_min, l_max);
		m_max = maxValue(l_min, l_max);
	}

	template <class T>
	inline const T& MinMaxRange<T>::getMin() const
	{
		return m_min;
	}

	template <class T>
	inline const T& MinMaxRange<T>::getMax() const
	{
		return m_max;
	}

	template <class T>
	inline bool fdk::MinMaxRange<T>::inRange(const T& o) const
	{
		return o >= m_min && o <= m_max;
	}
};

#endif
