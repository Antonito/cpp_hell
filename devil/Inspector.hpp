#ifndef INSPECTOR_HPP_
#define INSPECTOR_HPP_

template<typename T, typename U>
class is_printable
{
private:
	typedef char	yes[1];
	typedef char	no[2];

	template<std::size_t>
	struct IsPrintableWrap {
		typedef void *value;
	};

	template<typename C>
	static yes &isPrintable(typename IsPrintableWrap<sizeof((*reinterpret_cast<T *>(NULL)) << (*reinterpret_cast<C *>(NULL)))>::value value);

	template <typename>
	static no &isPrintable(...);

public:
	enum { Value = sizeof(isPrintable<U>(NULL)) == sizeof(yes) };
};

#endif