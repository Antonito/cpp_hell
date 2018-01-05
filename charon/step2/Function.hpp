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
		virtual R Invoke() const = 0;
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
		R Invoke() const
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
	Function(T t) : m_callable(new Callable<T>(t))
	{
	}

	template <typename T>
	Function &operator=(T t)
	{
		m_callable = new Callable<T>(t);
		return *this;
	}

	R operator()()
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke();
	}

	R operator()() const
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke();
	}
private:
	ICallable *m_callable;
};

template <typename R, typename Arg1>
class Function<R(Arg1)>
{
public:
	class ICallable
	{
	public:
		virtual ~ICallable() {}
		virtual R Invoke(Arg1) = 0;
		virtual R Invoke(Arg1) const = 0;
	};

	template <typename T>
	class Callable : public ICallable
	{
	public:
		Callable(T t) : m_t(t) {}
		virtual ~Callable() {}
		R Invoke(Arg1 a)
		{
			return m_t(a);
		}
		R Invoke(Arg1 a) const
		{
			return m_t(a);
		}
	private:
		T m_t;
	};

	Function() : m_callable(NULL)
	{
	}

	template <typename T>
	Function(T t) : m_callable(new Callable<T>(t))
	{
	}

	template <typename T>
	Function &operator=(T t)
	{
		m_callable = new Callable<T>(t);
		return *this;
	}

	R operator()(Arg1 a)
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke(a);
	}

	R operator()(Arg1 a) const
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke(a);
	}
private:
	ICallable *m_callable;
};
#endif
