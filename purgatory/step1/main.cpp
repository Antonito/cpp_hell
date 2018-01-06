#include <cstdlib>
#include "Machine.hpp"

int main(int ac, char **av)
{
	Machine m;

	if (ac > 1)
	{
		m.check(av[1]);
	}
	return EXIT_SUCCESS;
}
