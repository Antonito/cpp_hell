#ifndef ENABLE_IF_HPP_
#define ENABLE_IF_HPP_

template <bool C, typename T = void>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
	typedef T value;
};

#endif
