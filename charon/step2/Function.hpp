#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

template <typename R, typename Arg1 = void, typename Arg2 = void, typename Arg3 = void, typename Arg4 = void>
class Function;

template <typename R>
class Function<R()>
{
public:
	class ICallable
	{
	public:
		virtual ~ICallable() {}
		virtual R Invoke() = 0;
	};

	template <typename T>
	class Callable : public ICallable
	{
	public:
		Callable(T t) : m_t(t) {}
		virtual ~Callable() {}
		R Invoke()
		{
			return m_t();
		}
	private:
		T m_t;
	};
	
	Function() : m_callable(NULL)
	{
	}

	template <typename T>
	Function(T t) : m_callable(new Callable(t))
	{
	}

	template <typename T>
	Function &operator=(T t)
	{
		if (!m_t)
		{
			throw std::exception();
		}
		return (*t)();
	}
private:
	ICallable *m_callable;
};
//
//template <typename R, typename Arg1>
//class Function<R(Arg1)>
//{
//};
//
//template <typename R, typename Arg1, typename Arg2>
//class Function<R(Arg1, Arg2)>
//{
//};
//
//template <typename R, typename Arg1, typename Arg2, typename Arg3>
//class Function<R(Arg1, Arg2, Arg3)>
//{
//};
//
//template <typename R, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
//class Function<R(Arg1, Arg2, Arg3, Arg4)>
//{
//};

#endif
