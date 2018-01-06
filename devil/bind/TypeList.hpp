#ifndef TYPE_LIST_HPP_
#define TYPE_LIST_HPP_

#include "Value.hpp"
#include "Storage.hpp"
#include "TypeTraits.hpp"

class TypeList0 : private Storage0
{
public:
	typedef Storage0 BaseClass;
	
	TypeList0() : BaseClass()
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &) {
		return call();
	}
};

template <typename T1>
class TypeList1 : private Storage1<T1>
{
public:
	typedef Storage1<T1> BaseClass;
	
	TypeList1(T1 t1) : BaseClass(t1)
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list) {
		return call(list[BaseClass::_t1]);
	}
};

template <typename T1, typename T2>
class TypeList2 : private Storage2<T1, T2>
{
public:
	typedef Storage2<T1, T2> BaseClass;
	
	TypeList2(T1 t1, T2 t2) : BaseClass(t1, t2)
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list) {
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2]);
	}
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
public:
	typedef Storage4<T1, T2, T3, T4> BaseClass;
	
	TypeList4(T1 t1, T2 t2, T3 t3, T4 t4) : BaseClass(t1, t2, t3, t4)
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list) {
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2], list[BaseClass::_t3],
				list[BaseClass::_t4]);
	}
};

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5 : private Storage5<T1, T2, T3, T4, T5>
{
public:
	typedef Storage5<T1, T2, T3, T4, T5> BaseClass;

	TypeList5(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) :
		BaseClass(t1, t2, t3, t4, t5)
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list) {
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2], list[BaseClass::_t3],
				list[BaseClass::_t4], list[BaseClass::_t5]);
	}
};

template <typename T1, typename T2, typename T3, typename T4, typename T5,
	typename T6>
class TypeList6 : private Storage6<T1, T2, T3, T4, T5, T6>
{
public:
	typedef Storage6<T1, T2, T3, T4, T5, T6> BaseClass;

	TypeList6(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) :
		BaseClass(t1, t2, t3, t4, t5, t6)
	{
	}

	template <typename T>
	T &operator[](Value<T> &value) {
		return value.get();
	}

	template<typename ReturnType, typename Callable, typename List>
	ReturnType operator()(TypeTraits<ReturnType>, Callable &call, List &list) {
		return call(list[BaseClass::_t1],
				list[BaseClass::_t2], list[BaseClass::_t3],
				list[BaseClass::_t4], list[BaseClass::_t5],
				list[BaseClass::_t6]);
	}
};

#endif
