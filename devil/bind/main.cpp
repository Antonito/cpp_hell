#include <iostream>
#include <string>

#include "Bind.hpp"

void threeParams(std::string const &str, int a, int b)
{
	std::cout << str << ": " <<  a + b << std::endl;
}

int main()
{
	bind(&threeParams, "Hello", 1, 2)();
	return 0;
}