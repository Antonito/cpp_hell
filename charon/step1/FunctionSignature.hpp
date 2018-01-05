#ifndef FUNCTION_SIGNATURE_HPP_
#define FUNCTION_SIGNATURE_HPP_

template <typename R, typename Arg1 = void, typename Arg2 = void, typename Arg3 = void, typename Arg4 = void>
struct FunctionSignature;

template <typename T>
struct _FunctionSignatureImpl
{
	typedef T type;
};

template <typename R>
struct FunctionSignature<R()>
{
	typedef R(*type)();
};

template <typename R, typename Arg1>
struct FunctionSignature<R(Arg1)>
{
	typedef R(*type)(Arg1);
};

template <typename R, typename Arg1, typename Arg2>
struct FunctionSignature<R(Arg1, Arg2)>
{
	typedef R(*type)(Arg1, Arg2);
};

template <typename R, typename Arg1, typename Arg2, typename Arg3>
struct FunctionSignature<R(Arg1, Arg2, Arg3)>
{
	typedef R(*type)(Arg1, Arg2, Arg3);
};

template <typename R, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
struct FunctionSignature<R(Arg1, Arg2, Arg3, Arg4)>
{
	typedef R(*type)(Arg1, Arg2, Arg3, Arg4);
};

#endif
