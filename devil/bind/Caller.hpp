#ifndef CALLER_HPP_
#define CALLER_HPP_

#include "TypeTraits.hpp"

template <typename ReturnType, typename Callable, typename List>
class Caller
{
public:
	Caller(Callable const &call, List const &list) : _callable(call), _list(list) 
	{
	}

	template <typename T1, typename T2, typename T3>
	ReturnType operator()(T1 t1, T2 t2, T3 t3)
	{
		typedef typename get_type<T1>::type P1;
		typedef typename get_type<T2>::type P2;
		typedef typename get_type<T3>::type P3;
		typedef TypeList3<P1, P2, P3> ListType;

		ListType arguments(t1, t2, t3);
		return _list(TypeTraits<ReturnType>(), _callable, _list, arguments);
	}

private:
	Callable _callable;
	List _list;
};

#endif
