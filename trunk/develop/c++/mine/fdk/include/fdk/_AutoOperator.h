//< ������������Զ�ʵ��: ��ҪTʵ��==��<
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
