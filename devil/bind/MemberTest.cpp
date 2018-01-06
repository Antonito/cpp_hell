#include <iostream>

#include "Bind.hpp"

class Foo
{
public:
	Foo(int value) : _value(value)
	{
	}

	void addTwo()
	{
		_value += 2;
	}

	void addParam(int toAdd)
	{
		_value += toAdd;
	}

	int getValue() const 
	{
		return _value;
	}

	static void sayHello() 
	{
		std::cout << "Hello from static method" << std::endl;
	}

private:
	int _value;
};

void memberTest()
{
	Foo foo(5);

	std::cout << "=== Member function pointers bind test ===\n";
	std::cout << "-- Static method --\n";
	bind(&Foo::sayHello)();
	std::cout << "-- Non const method, no parameter --\n";
	bind(&Foo::addTwo, &foo)();
	std::cout << "-- Non const method, parameter --\n";
	bind(&Foo::addParam, &foo, 5)();
	std::cout << "-- Const method --\n";
	//std::cout << bind(&Foo::getValue, &foo)();
}