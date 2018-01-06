#include <cstdlib>
#include <iostream>
#include <string>
#include <functional>
#include "Function.hpp"

class Callable
{
public:
	void operator()() {
		std::cout << "Callable Object" << std::endl;
	}
};

void zeroFunction()
{
	std::cout << "Hello World" << std::endl;
}

void oneFunction(std::string const &str)
{
	std::cout << str << std::endl;
}

int twoFunction(int a, int b)
{
	std::cout << "a + b = " << a + b << std::endl;
	return a + b;
}

int threeFunction(std::string const &str, int a, int b)
{
	std::cout << str << ": " << a * b << std::endl;
	return a * b;
}

double fourFunction(std::string const &str, int value, double value2, double value3)
{
	std::cout << str << ": " << value << " and " << value2 << std::endl;
	return value2 + value3;
}

int main()
{
	Function<void ()> f0 = &zeroFunction;
	f0();

	Function<void (std::string const &)> f1 = &oneFunction;
	f1("Hello World !");

	Function<int (int, int)> f2 = &twoFunction;
	int resI = f2(123, 7);
	std::cout << "Res: " << resI << std::endl;

	Function<int (std::string const &, int, int)> f3 = &threeFunction;
	resI = f3("Whaou ", 5, 4);
	std::cout << "Res: " << resI << std::endl;

	Function<double (std::string const &, int, double, double)> f4 = &fourFunction;
	double resD = f4("Double", 5, 6, 14);
	std::cout << "Res: " << resD << std::endl;

#if __cplusplus >= 201103L
	Function<int (int, int)> b1 = std::bind(&threeFunction, "Bind", std::placeholders::_1, std::placeholders::_2);
	resI = b1(2, 3);
	std::cout << "Res: " << resI << std::endl;
#endif

	Callable callableObject;
	Function<void ()> c1 = callableObject;
	c1();

	return EXIT_SUCCESS;
}

