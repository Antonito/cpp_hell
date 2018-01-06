#ifndef INSPECTOR_HPP_
#define INSPECTOR_HPP_

#include "IsPrintable.hpp"
#include "EnableIf.hpp"

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
