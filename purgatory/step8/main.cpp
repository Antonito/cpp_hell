#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"
#include "ExpressionParser.hpp"

static void testInput(Matcher &matcher, std::string const &str)
{
	std::size_t count;

	std::cout << str << " : ";
	if (matcher.find(str, count))
	{
		std::cout << "OK (" << count << " time" << (count > 1 ? "s" : "") << ")" << std::endl;
	}
	else
	{
		std::cout << "KO" << std::endl;
	}
}

int main(int ac, char **av)
{
	std::string regex = "[-a-z0-9._]+@[-a-z0-9]+.[a-z][a-z]";

	Matcher m(regex);

	std::cout << "Input pattern: " << regex << '\n' << std::endl;

	if (ac > 1)
	{
		testInput(m, av[1]);
	}
	else
	{
		testInput(m, "e-mail.test@epitech.eu");
		testInput(m, "e-mail.test_42@epitech.eu and second_email@wanadoo.fr");
		testInput(m, "e-mail.test_42@epitech.e and secondemail@wanadoofr");
		testInput(m, "e-mail.test epitech.eu");
		testInput(m, "e-mail.test@.eu");
		testInput(m, "@a.eu");
		testInput(m, "e@a.e");
		testInput(m, "e@a.it");
	}

	return EXIT_SUCCESS;
}
