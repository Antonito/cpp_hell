#include <cstdlib>
#include <iostream>
#include "FunctionSignature.hpp"

int oneFunction(const std::string &str)
{
	std::cout << str << std::endl;
	return 0;
}

int main()
{
	FunctionSignature<int (const std::string &str)>::type f = &oneFunction;

	f("Hello World !");
	return EXIT_SUCCESS;
}