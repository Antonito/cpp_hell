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
	Function(T t) : m_callable(new Callable<T>(t))
	{
	}

	~Function()
	{
		delete m_callable;
	}

	template <typename T>
	Function &operator=(T t)
	{
		delete m_callable;
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

	~Function()
	{
		delete m_callable;
	}
	
	template <typename T>
	Function &operator=(T t)
	{
		delete m_callable;
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

private:
	ICallable *m_callable;
};

template <typename R, typename Arg1, typename Arg2>
class Function<R(Arg1, Arg2)>
{
public:
	class ICallable
	{
	public:
		virtual ~ICallable() {}
		virtual R Invoke(Arg1, Arg2) = 0;
	};

	template <typename T>
	class Callable : public ICallable
	{
	public:
		Callable(T t) : m_t(t) {}
		virtual ~Callable() {}
		R Invoke(Arg1 a, Arg2 b)
		{
			return m_t(a, b);
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

	~Function()
	{
		delete m_callable;
	}

	template <typename T>
	Function &operator=(T t)
	{
		delete m_callable;
		m_callable = new Callable<T>(t);
		return *this;
	}

	R operator()(Arg1 a, Arg2 b)
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke(a, b);
	}

private:
	ICallable *m_callable;
};

template <typename R, typename Arg1, typename Arg2, typename Arg3>
class Function<R(Arg1, Arg2, Arg3)>
{
public:
	class ICallable
	{
	public:
		virtual ~ICallable() {}
		virtual R Invoke(Arg1, Arg2, Arg3) = 0;
	};

	template <typename T>
	class Callable : public ICallable
	{
	public:
		Callable(T t) : m_t(t) {}
		virtual ~Callable() {}
		R Invoke(Arg1 a, Arg2 b, Arg3 c)
		{
			return m_t(a, b, c);
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

	~Function()
	{
		delete m_callable;
	}

	template <typename T>
	Function &operator=(T t)
	{
		delete m_callable;
		m_callable = new Callable<T>(t);
		return *this;
	}

	R operator()(Arg1 a, Arg2 b, Arg3 c)
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke(a, b, c);
	}

private:
	ICallable *m_callable;
};

template <typename R, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class Function<R(Arg1, Arg2, Arg3, Arg4)>
{
public:
	class ICallable
	{
	public:
		virtual ~ICallable() {}
		virtual R Invoke(Arg1, Arg2, Arg3, Arg4) = 0;
	};

	template <typename T>
	class Callable : public ICallable
	{
	public:
		Callable(T t) : m_t(t) {}
		virtual ~Callable() {}
		R Invoke(Arg1 a, Arg2 b, Arg3 c, Arg4 d)
		{
			return m_t(a, b, c, d);
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

	~Function()
	{
		delete m_callable;
	}

	template <typename T>
	Function &operator=(T t)
	{
		delete m_callable;
		m_callable = new Callable<T>(t);
		return *this;
	}

	R operator()(Arg1 a, Arg2 b, Arg3 c, Arg4 d)
	{
		if (!m_callable)
		{
			throw std::exception();
		}
		return m_callable->Invoke(a, b, c, d);
	}

private:
	ICallable *m_callable;
};
#endif
