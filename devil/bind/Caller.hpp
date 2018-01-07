#ifndef CALLER_HPP_
# define CALLER_HPP_

# include "TypeTraits.hpp"
# include "TypeList.hpp"

template <typename ReturnType, typename Callable, typename List>
class Caller
{
public:
	Caller(Callable const &call, List const &list) :
		_callable(call), _list(list)
	{
	}

	ReturnType operator()(void)
	{
		typedef TypeList0 ListType;

		ListType arguments;
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

	template <typename T1>
	ReturnType operator()(T1 t1)
	{
		typedef typename get_type<T1>::type P1;
		typedef TypeList1<P1> ListType;

		ListType arguments(t1);
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

	template <typename T1, typename T2>
	ReturnType operator()(T1 t1, T2 t2)
	{
		typedef typename get_type<T1>::type P1;
		typedef typename get_type<T2>::type P2;
		typedef TypeList2<P1, P2> ListType;

		ListType arguments(t1, t2);
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

	template <typename T1, typename T2, typename T3>
	ReturnType operator()(T1 t1, T2 t2, T3 t3)
	{
		typedef typename get_type<T1>::type P1;
		typedef typename get_type<T2>::type P2;
		typedef typename get_type<T3>::type P3;
		typedef TypeList3<P1, P2, P3> ListType;

		ListType arguments(t1, t2, t3);
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

	template <typename T1, typename T2, typename T3, typename T4>
	ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4)
	{
		typedef typename get_type<T1>::type P1;
		typedef typename get_type<T2>::type P2;
		typedef typename get_type<T3>::type P3;
		typedef typename get_type<T4>::type P4;
		typedef TypeList4<P1, P2, P3, P4> ListType;

		ListType arguments(t1, t2, t3, t4);
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

	template <typename T1, typename T2, typename T3, typename T4,
			typename T5>
	ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5)
	{
		typedef typename get_type<T1>::type P1;
		typedef typename get_type<T2>::type P2;
		typedef typename get_type<T3>::type P3;
		typedef typename get_type<T4>::type P4;
		typedef typename get_type<T5>::type P5;
		typedef TypeList5<P1, P2, P3, P4, P5> ListType;

		ListType arguments(t1, t2, t3, t4, t5);
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

	template <typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6>
	ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6)
	{
		typedef typename get_type<T1>::type P1;
		typedef typename get_type<T2>::type P2;
		typedef typename get_type<T3>::type P3;
		typedef typename get_type<T4>::type P4;
		typedef typename get_type<T5>::type P5;
		typedef typename get_type<T6>::type P6;
		typedef TypeList6<P1, P2, P3, P4, P5, P6> ListType;

		ListType arguments(t1, t2, t3, t4, t5, t6);
		return _list(TypeTraits<ReturnType>(), _callable, arguments);
	}

private:
	Callable _callable;
	List _list;
};

#endif
