#ifndef VALUE_HPP_
#define VALUE_HPP_

template <typename T>
class Value
{
public:
	T &get()
	{
		return _param;
	}

	T const &get() const
	{
		return _param;
	}

private:
	T	_param;
};

#endif