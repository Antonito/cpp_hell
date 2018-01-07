#ifndef TYPE_LIST_HPP_
# define TYPE_LIST_HPP_

# include "Value.hpp"
# include "Storage.hpp"
# include "TypeTraits.hpp"

namespace Placeholder
{
	template <std::size_t>
	struct PlaceholderWrapper
	{
	};

	static PlaceholderWrapper<1>	_1;
	static PlaceholderWrapper<2>	_2;
	static PlaceholderWrapper<3>	_3;
	static PlaceholderWrapper<4>	_4;
	static PlaceholderWrapper<5>	_5;
	static PlaceholderWrapper<6>	_6;
}

class TypeList0 : private Storage0
{
public:
	typedef Storage0 BaseClass;
	
	TypeList0() : BaseClass()
	{
	}

	template <typename T>
	T &operator[](T value) const
	{
		return value.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &)
	{
		return call();
	}
};

template <typename T1>
class TypeList1;

template <typename T1>
class TypeList1<Value<T1> > : private Storage1<Value<T1> >
{
public:
	typedef Storage1<Value<T1> > BaseClass;
	
	TypeList1(Value<T1> t1) : BaseClass(t1)
	{
	}

	T1 &operator[](Value<Placeholder::PlaceholderWrapper<1> > &)
	{
		return BaseClass::_t1.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list)
	{
		return call(list[BaseClass::_t1]);
	}
};

template <typename T1, typename T2>
class TypeList2;

template <typename T1, typename T2>
class TypeList2<Value<T1>, Value<T2> > : private Storage2<Value<T1>, Value<T2> >
{
public:
	typedef Storage2<Value<T1>, Value<T2> > BaseClass;
	
	TypeList2(Value<T1> const &t1, Value<T2> const &t2) : BaseClass(t1, t2)
	{
	}

	T1 &operator[](Value<Placeholder::PlaceholderWrapper<1> > &)
	{
		return BaseClass::_t1.get();
	}

	T2 &operator[](Value<Placeholder::PlaceholderWrapper<2> > &)
	{
		return BaseClass::_t2.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list)
	{
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2]);
	}
};

template <typename T1, typename T2, typename T3>
class TypeList3;

template <typename T1, typename T2, typename T3>
class TypeList3<Value<T1>, Value<T2>, Value<T3> > :
	private Storage3<Value<T1>, Value<T2>, Value<T3> >
{
public:
	typedef Storage3<Value<T1>, Value<T2>, Value<T3> > BaseClass;
	
	TypeList3(Value<T1> const &t1, Value<T2> const &t2,
			Value<T3> const &t3) : BaseClass(t1, t2, t3)
	{
	}

	T1 &operator[](Value<Placeholder::PlaceholderWrapper<1> > &)
	{
		return BaseClass::_t1.get();
	}

	T2 &operator[](Value<Placeholder::PlaceholderWrapper<2> > &)
	{
		return BaseClass::_t2.get();
	}

	T3 &operator[](Value<Placeholder::PlaceholderWrapper<3> > &)
	{
		return BaseClass::_t3.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list)
	{
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2],
				list[BaseClass::_t3]);
	}
};

template <typename T1, typename T2, typename T3, typename T4>
class TypeList4;

template <typename T1, typename T2, typename T3, typename T4>
class TypeList4<Value<T1>, Value<T2>, Value<T3>, Value<T4> > :
	private Storage4<Value<T1>, Value<T2>, Value<T3>, Value<T4> >
{
public:
	typedef Storage4<Value<T1>, Value<T2>, Value<T3>, Value<T4> > BaseClass;
	
	TypeList4(Value<T1> const &t1, Value<T2> const &t2,
		Value<T3> const &t3, Value<T4> const &t4) :
		BaseClass(t1, t2, t3, t4)
	{
	}

	T1 &operator[](Value<Placeholder::PlaceholderWrapper<1> > &)
	{
		return BaseClass::_t1.get();
	}

	T2 &operator[](Value<Placeholder::PlaceholderWrapper<2> > &)
	{
		return BaseClass::_t2.get();
	}

	T3 &operator[](Value<Placeholder::PlaceholderWrapper<3> > &)
	{
		return BaseClass::_t3.get();
	}

	T4 &operator[](Value<Placeholder::PlaceholderWrapper<4> > &)
	{
		return BaseClass::_t4.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list)
	{
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2], list[BaseClass::_t3],
				list[BaseClass::_t4]);
	}
};

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5;

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5> > :
	private Storage5<Value<T1>, Value<T2>, Value<T3>, Value<T4>,
		Value<T5> >
{
public:
	typedef Storage5<Value<T1>, Value<T2>, Value<T3>,
		Value<T4>, Value<T5> > BaseClass;

	TypeList5(Value<T1> const &t1, Value<T2> const &t2,
			Value<T3> const &t3, Value<T4> const &t4,
			Value<T5> const &t5) : BaseClass(t1, t2, t3, t4, t5)
	{
	}

	T1 &operator[](Value<Placeholder::PlaceholderWrapper<1> > &)
	{
		return BaseClass::_t1.get();
	}

	T2 &operator[](Value<Placeholder::PlaceholderWrapper<2> > &)
	{
		return BaseClass::_t2.get();
	}

	T3 &operator[](Value<Placeholder::PlaceholderWrapper<3> > &)
	{
		return BaseClass::_t3.get();
	}

	T4 &operator[](Value<Placeholder::PlaceholderWrapper<4> > &)
	{
		return BaseClass::_t4.get();
	}

	T5 &operator[](Value<Placeholder::PlaceholderWrapper<5> > &)
	{
		return BaseClass::_t5.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list)
	{
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2], list[BaseClass::_t3],
				list[BaseClass::_t4], list[BaseClass::_t5]);
	}
};

template <typename T1, typename T2, typename T3, typename T4, typename T5,
	typename T6>
class TypeList6;

template <typename T1, typename T2, typename T3, typename T4, typename T5,
	typename T6>
class TypeList6<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5>,
		Value<T6> > :
	private Storage6<Value<T1>, Value<T2>, Value<T3>, Value<T4>,
		Value<T5>, Value<T6> >
{
public:
	typedef Storage6<Value<T1>, Value<T2>, Value<T3>, Value<T4>,
		Value<T5>, Value<T6> > BaseClass;

	TypeList6(Value<T1> const &t1, Value<T2> const &t2,
		Value<T3> const &t3, Value<T4> const &t4,
		Value<T5> const &t5, Value<T6> const &t6) :
		BaseClass(t1, t2, t3, t4, t5, t6)
	{
	}

	T1 &operator[](Value<Placeholder::PlaceholderWrapper<1> > &)
	{
		return BaseClass::_t1.get();
	}

	T2 &operator[](Value<Placeholder::PlaceholderWrapper<2> > &)
	{
		return BaseClass::_t2.get();
	}

	T3 &operator[](Value<Placeholder::PlaceholderWrapper<3> > &)
	{
		return BaseClass::_t3.get();
	}

	T4 &operator[](Value<Placeholder::PlaceholderWrapper<4> > &)
	{
		return BaseClass::_t4.get();
	}

	T5 &operator[](Value<Placeholder::PlaceholderWrapper<5> > &)
	{
		return BaseClass::_t5.get();
	}

	T6 &operator[](Value<Placeholder::PlaceholderWrapper<6> > &)
	{
		return BaseClass::_t6.get();
	}

	template <typename T>
	T &operator[](Value<T> &value) const
	{
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list)
	{
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2], list[BaseClass::_t3],
				list[BaseClass::_t4], list[BaseClass::_t5],
				list[BaseClass::_t6]);
	}
};

#endif
