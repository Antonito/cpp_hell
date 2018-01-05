#include <cstdlib>
#include <iostream>
#include <string>
#include "FunctionSignature.hpp"

int zeroFunction()
{
	std::cout << "Yes" << std::endl;
	return 0;
}

int oneFunction(const std::string &str)
{
	std::cout << str << std::endl;
	return 0;
}

void twoFunction(int value, double value2)
{
	std::cout << value << " and " << value2 << std::endl;
}

void threeFunction(std::string const &str, int value, double value2)
{
	std::cout << str << ": " << value << " and " << value2 << std::endl;
}

double fourFunction(std::string const &str, int value, double value2, double value3)
{
	std::cout << str << ": " << value << " and " << value2 << std::endl;
	return value2 + value3;
}

int main()
{
	FunctionSignature<int ()>::type f0 = &zeroFunction;
	f0();

	FunctionSignature<int (const std::string &str)>::type f1 = &oneFunction;
	f1("Hello World !");

	FunctionSignature<void (int, double)>::type f2 = &twoFunction;
	f2(42, 84.0);

	FunctionSignature<void (const std::string &, int, double)>::type f3 = &threeFunction;
	f3("Nope", 21, 42.0);

	FunctionSignature<double (const std::string &str, int, double, double)>::type f4 = &fourFunction;
	double res = f4("Yep", 42, 21.0, 84.0);

	std::cout << "Res: " << res << std::endl;

	return EXIT_SUCCESS;
}