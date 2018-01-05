#include <cstdlib>
#include <iostream>
#include <string>
#include "Function.hpp"

int zeroFunction()
{
	std::cout << "Yeah" << std::endl;
	return 0;
}

int oneFunction(std::string const &str)
{
	std::cout << str << std::endl;
	return 0;
}

int main()
{
	Function<int()> const f0(&zeroFunction);
	
	f0();

	Function<int(std::string const &)> f1(&oneFunction);

	f1("Hello world!");
	return EXIT_SUCCESS;
}
