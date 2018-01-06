#include <iostream>
#include <string>

#include "Bind.hpp"

void threeParams(std::string const &str, int a, int b)
{
	std::cout << str << ": " <<  a + b << std::endl;
}

int main()
{
	std::string s1 = "Hello";

	bind(&threeParams, s1, 1, 2)();
	return 0;
}