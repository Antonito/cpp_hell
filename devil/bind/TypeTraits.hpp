#ifndef TYPE_TRAITS_HPP_
# define TYPE_TRAITS_HPP_

# include "Value.hpp"

template <typename T>
struct get_type
{
	typedef Value<T> type;
};

template <typename T>
struct TypeTraits
{
};

#endif