#ifndef REFERENCE_WRAPPER_HPP_
#define REFERENCE_WRAPPER_HPP_

template <typename T>
class ReferenceWrapper
{
public:
	typedef T type;

	ReferenceWrapper(T &ref) : _refAddr(&ref)
	{
	}

	operator T&() const 
	{
		return *_refAddr;
	}

	T &get()
	{
		return *_refAddr;
	}

	T const &get() const
	{
		return *_refAddr;
	}

	T *getPtr() const
	{
		return _refAddr;
	}

private:
	T	*_refAddr;
};

template<typename T>
ReferenceWrapper<T> ref(T &t)
{
	return ReferenceWrapper<T>(t);
}

template<typename T>
ReferenceWrapper<T const> const cref(T const &t)
{
	return ReferenceWrapper<T const>(t);
}

#endif
