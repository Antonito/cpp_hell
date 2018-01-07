#ifndef TRAITS_HPP_
# define TRAITS_HPP_

# include "TypeList.hpp"

struct Traits0
{
	typedef TypeList0 type;
};

template <typename T1>
struct Traits1
{
	typedef typename get_type<T1>::type TypeParam1;
	typedef TypeList1<TypeParam1> type;
};

template <typename T1, typename T2>
struct Traits2
{
	typedef typename get_type<T1>::type TypeParam1;
	typedef typename get_type<T2>::type TypeParam2;
	typedef TypeList2<TypeParam1, TypeParam2> type;
};

template <typename T1, typename T2, typename T3>
struct Traits3
{
	typedef typename get_type<T1>::type TypeParam1;
	typedef typename get_type<T2>::type TypeParam2;
	typedef typename get_type<T3>::type TypeParam3;
	typedef TypeList3<TypeParam1, TypeParam2, TypeParam3> type;
};

template <typename T1, typename T2, typename T3, typename T4>
struct Traits4
{
	typedef typename get_type<T1>::type TypeParam1;
	typedef typename get_type<T2>::type TypeParam2;
	typedef typename get_type<T3>::type TypeParam3;
	typedef typename get_type<T4>::type TypeParam4;
	typedef TypeList4<TypeParam1, TypeParam2,
				TypeParam3, TypeParam4> type;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5>
struct Traits5
{
	typedef typename get_type<T1>::type TypeParam1;
	typedef typename get_type<T2>::type TypeParam2;
	typedef typename get_type<T3>::type TypeParam3;
	typedef typename get_type<T4>::type TypeParam4;
	typedef typename get_type<T5>::type TypeParam5;
	typedef TypeList5<TypeParam1, TypeParam2,
				TypeParam3, TypeParam4,
				TypeParam5> type;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5,
	typename T6>
struct Traits6
{
	typedef typename get_type<T1>::type TypeParam1;
	typedef typename get_type<T2>::type TypeParam2;
	typedef typename get_type<T3>::type TypeParam3;
	typedef typename get_type<T4>::type TypeParam4;
	typedef typename get_type<T5>::type TypeParam5;
	typedef typename get_type<T6>::type TypeParam6;
	typedef TypeList6<TypeParam1, TypeParam2,
				TypeParam3, TypeParam4,
				TypeParam5, TypeParam6> type;
};

#endif
