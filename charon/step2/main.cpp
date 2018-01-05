#include <cstdlib>
#include <iostream>
#include "Function.hpp"

int zeroFunction()
{
	std::cout << "Yeah" << std::endl;
	return 0;
}

int main()
{
	Function<int()> f0;
	f0 = &zeroFunction;
	
	f0();
	return EXIT_SUCCESS;
}
