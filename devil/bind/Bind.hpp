#ifndef BIND_HPP_
#define BIND_HPP_

#include "Caller.hpp"
#include "TypeTraits.hpp"
#include "TypeList.hpp"
#include "Traits.hpp"

template <typename ReturnType>
Caller<ReturnType, ReturnType(*)(void),
	typename Traits0::type>
	bind(ReturnType (*func)(void))
{
	typedef TypeList0 ListType;

	ListType list;
	return Caller<ReturnType, ReturnType(*)(void), ListType>(func, list);
}

template <typename ReturnType, typename X1, typename Param1>
Caller<ReturnType, ReturnType(*)(X1),
	typename Traits1<Param1>::type>
	bind(ReturnType (*func)(X1), Param1 p1)
{
	typedef typename get_type<Param1>::type P1;
	typedef TypeList1<P1> ListType;

	ListType list(p1);
	return Caller<ReturnType, ReturnType(*)(X1), ListType>(func, list);
}

template <typename ReturnType, typename X1, typename X2,
	typename Param1, typename Param2>
Caller<ReturnType, ReturnType(*)(X1, X2),
	typename Traits2<Param1, Param2>::type>
	bind(ReturnType (*func)(X1, X2), Param1 p1, Param2 p2)
{
	typedef typename get_type<Param1>::type P1;
	typedef typename get_type<Param2>::type P2;
	typedef TypeList2<P1, P2> ListType;

	ListType list(p1, p2);
	return Caller<ReturnType, ReturnType(*)(X1, X2), ListType>(func,
									list);
}

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

template <typename ReturnType, typename X1, typename X2, typename X3,
	typename X4, typename Param1, typename Param2, typename Param3,
	typename Param4>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4),
	typename Traits4<Param1, Param2, Param3, Param4>::type>
	bind(ReturnType (*func)(X1, X2, X3, X4), Param1 p1, Param2 p2,
		Param3 p3, Param4 p4)
{
	typedef typename get_type<Param1>::type P1;
	typedef typename get_type<Param2>::type P2;
	typedef typename get_type<Param3>::type P3;
	typedef typename get_type<Param4>::type P4;
	typedef TypeList4<P1, P2, P3, P4> ListType;

	ListType list(p1, p2, p3, p4);
	return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4),
			ListType>(func, list);
}

template <typename ReturnType, typename X1, typename X2, typename X3,
	typename X4, typename X5, typename Param1, typename Param2,
	typename Param3, typename Param4, typename Param5>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5),
	typename Traits5<Param1, Param2, Param3, Param4, Param5>::type>
	bind(ReturnType (*func)(X1, X2, X3, X4, X5), Param1 p1, Param2 p2,
		Param3 p3, Param4 p4, Param5 p5)
{
	typedef typename get_type<Param1>::type P1;
	typedef typename get_type<Param2>::type P2;
	typedef typename get_type<Param3>::type P3;
	typedef typename get_type<Param4>::type P4;
	typedef typename get_type<Param5>::type P5;
	typedef TypeList5<P1, P2, P3, P4, P5> ListType;

	ListType list(p1, p2, p3, p4, p5);
	return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5),
			ListType>(func, list);
}

template <typename ReturnType, typename X1, typename X2, typename X3,
	typename X4, typename X5, typename X6, typename Param1,
	typename Param2, typename Param3, typename Param4,
	typename Param5, typename Param6>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6),
	typename Traits6<Param1, Param2, Param3, Param4, Param5,
				Param6>::type>
	bind(ReturnType (*func)(X1, X2, X3, X4, X5, X6), Param1 p1, Param2 p2,
		Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
	typedef typename get_type<Param1>::type P1;
	typedef typename get_type<Param2>::type P2;
	typedef typename get_type<Param3>::type P3;
	typedef typename get_type<Param4>::type P4;
	typedef typename get_type<Param5>::type P5;
	typedef typename get_type<Param6>::type P6;
	typedef TypeList6<P1, P2, P3, P4, P5, P6> ListType;

	ListType list(p1, p2, p3, p4, p5, p6);
	return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6),
			ListType>(func, list);
}

#endif
