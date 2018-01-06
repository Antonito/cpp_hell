#ifndef BIND_HPP_
#define BIND_HPP_

#include "Caller.hpp"
#include "TypeTraits.hpp"
#include "TypeList.hpp"
#include "Traits.hpp"

template <typename ReturnType, typename X1, typename X2, typename X3, 
	typename Param1, typename Param2, typename Param3>
Caller<ReturnType, ReturnType(*)(X1, X2, X3), 
	typename Traits3<Param1, Param2, Param3>::type> 
	bind(ReturnType (*func)(X1, X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
	typedef typename get_type<Param1>::type P1;
	typedef typename get_type<Param2>::type P2;
	typedef typename get_type<Param3>::type P3;
	typedef TypeList3<P1, P2, P3> ListType;

	ListType list(p1, p2, p3);
	return Caller<ReturnType, ReturnType(*)(X1, X2, X3), ListType>(func,
									list);
}

#endif
