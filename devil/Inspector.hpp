#ifndef INSPECTOR_HPP_
#define INSPECTOR_HPP_

#include "EnableIf.hpp"

template<typename S, typename O>
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
	static yes &isPrintable(typename IsPrintableWrap<sizeof((*reinterpret_cast<S *>(NULL)) << (*reinterpret_cast<C *>(NULL)))>::value value);

	template <typename>
	static no &isPrintable(...);

public:
	enum { Value = sizeof(isPrintable<O>(NULL)) == sizeof(yes) };
};

template<typename S>
struct PrintImpl
{
	template<typename O>
	static void print(S &stream, O const &object, typename enable_if<is_printable<S, O>::Value>::type = 0)
	{
		stream << object << std::endl;
	}

	template<typename O>
	static void print(S &stream, O const &object, typename enable_if<!is_printable<S, O>::Value>::type = 0)
	{
		stream << typeid(object).name() << std::endl;
	}
};

template<typename O>
void inspect(O const &object)
{
	PrintImpl<std::ostream>::print(std::cout, object);
}

#endif