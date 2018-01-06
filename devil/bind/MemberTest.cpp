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
		std::cout << "Value is now " << _value << std::endl;
	}

	void addParam(int toAdd)
	{
		_value += toAdd;
		std::cout << "Value is now " << _value << std::endl;
	}

	void addParamTwo(int toAdd, int toAdd2)
	{
		_value += toAdd + toAdd2;
		std::cout << "Value is now " << _value << std::endl;
	}

	void addParamThree(int toAdd, int toAdd2, int toAdd3)
	{
		_value += toAdd + toAdd2 + toAdd3;
		std::cout << "Value is now " << _value << std::endl;
	}

	void addParamFour(int toAdd, int toAdd2, int toAdd3, int toAdd4)
	{
		_value += toAdd + toAdd2 + toAdd3 + toAdd4;
		std::cout << "Value is now " << _value << std::endl;
	}

	void addParamFive(int toAdd, int toAdd2, int toAdd3, int toAdd4,
				int toAdd5)
	{
		_value += toAdd + toAdd2 + toAdd3 + toAdd4 + toAdd5;
		std::cout << "Value is now " << _value << std::endl;
	}

	void addParamSix(int toAdd, int toAdd2, int toAdd3, int toAdd4,
				int toAdd5, int toAdd6)
	{
		_value += toAdd + toAdd2 + toAdd3 + toAdd4 + toAdd5 + toAdd6;
		std::cout << "Value is now " << _value << std::endl;
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

static void memberTestNonConst()
{
	Foo foo(5);

	std::cout << "-- Non const method, no parameter --\n";
	bind(&Foo::addTwo, &foo)();
	std::cout << "-- Non const method, 1 parameter --\n";
	bind(&Foo::addParam, &foo, 5)();
	std::cout << "-- Non const method, 2 parameter --\n";
	bind(&Foo::addParamTwo, &foo, 5, 10)();
	std::cout << "-- Non const method, 3 parameter --\n";
	bind(&Foo::addParamThree, &foo, 5, 10, 3)();
	std::cout << "-- Non const method, 4 parameter --\n";
	bind(&Foo::addParamFour, &foo, 5, 10, 3, 9)();
	std::cout << "-- Non const method, 5 parameter --\n";
	bind(&Foo::addParamFive, &foo, 5, 10, 3, 9, -8)();
	std::cout << "-- Non const method, 6 parameter --\n";
	bind(&Foo::addParamSix, &foo, 5, 10, 3, 9, -8, 42)();
}

static void memberTestConst()
{
	Foo const foo(5);

	std::cout << "-- Const method, no parameter --\n";
	std::cout << bind(&Foo::getValue, &foo)() << '\n';
	std::cout << "-- Const method, 1 parameter --\n";
	std::cout << "-- Const method, 2 parameter --\n";
	std::cout << "-- Const method, 3 parameter --\n";
	std::cout << "-- Const method, 4 parameter --\n";
	std::cout << "-- Const method, 5 parameter --\n";
	std::cout << "-- Const method, 6 parameter --\n";
}

void memberTest()
{
	Foo foo(5);

	std::cout << "=== Member function pointers bind test ===\n";
	std::cout << "-- Static method --\n";
	bind(&Foo::sayHello)();
	memberTestNonConst();
	memberTestConst();
}