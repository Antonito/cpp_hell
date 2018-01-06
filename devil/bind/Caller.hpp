#ifndef CALLER_HPP_
#define CALLER_HPP_

template <ReturnType, Callable, List>
class Caller
{
public:
	Caller(Callable const &call, List const &list) : _callable(call), _list(list) 
	{
	}

	ReturnType operator()()
	{
		return _callable<ReturnType>(callable, _list);
	}

private:
	Callable _callable;
	List _list;
};

#endif
