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
