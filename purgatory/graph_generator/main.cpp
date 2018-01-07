#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <sstream>
#include "ExpressionParser.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		try
		{
			std::time_t result = std::time(NULL);
			std::stringstream name;
			
			name << "output/graph_hell_" << result << '.';

			ExpressionParser ep(av[1]);
			std::string filename = name.str() + "dot";
			std::ofstream of(filename.c_str());

			of << ep.getNFA();

			of.close();

			std::system(("dot " + filename + " -Tpng -o " + name.str() + "png").c_str());
		}
		catch (...)
		{
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
