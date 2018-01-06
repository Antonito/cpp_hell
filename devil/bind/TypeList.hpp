#ifndef TYPE_LIST_HPP_
#define TYPE_LIST_HPP_

#include "Value.hpp"
#include "Storage.hpp"
#include "TypeTraits.hpp"

class TypeList0 : private Storage0
{
};

template <typename T1>
class TypeList1 : private Storage1<T1>
{
};

template <typename T1, typename T2>
class TypeList2 : private Storage2<T1, T2>
{
};

template <typename T1, typename T2, typename T3>
class TypeList3 : private Storage3<T1, T2, T3>
{
public:
	typedef Storage3<T1, T2, T3> BaseClass;
	
	TypeList3(T1 t1, T2 t2, T3 t3) : BaseClass(t1, t2, t3)
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list) {
		return call(list[BaseClass::_t1], 
				list[BaseClass::_t2], 
				list[BaseClass::_t3]);
	}
};

template <typename T1, typename T2, typename T3, typename T4>
class TypeList4 : private Storage4<T1, T2, T3, T4>
{
};

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5 : private Storage5<T1, T2, T3, T4, T4>
{
};

template <typename T1, typename T2, typename T3, typename T4, typename T5,
	typename T6>
class TypeList6 : private Storage6<T1, T2, T3, T4, T5, T6>
{
};

#endif
