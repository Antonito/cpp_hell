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
	std::string _alphanum = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::string an;

	an.reserve(2 * _alphanum.size());

	for (std::size_t i = 0; i < _alphanum.size(); ++i)
	{
		if (i)
		{
			an += '|';
		}
		an += _alphanum[i];
	}
	
	std::string regex = "(" + an + "|.)+@(" + an + "|.)+.(" + an + ")(" + an + ")";

	Matcher m(regex);

	std::cout << "Input pattern: " << regex << '\n' << std::endl;

	if (ac > 1)
	{
		testInput(m, av[1]);
	}
	else
	{
		testInput(m, "email.test@epitech.eu");
		testInput(m, "email.test42@epitech.eu and secondemail@wanadoo.fr");
		testInput(m, "email.test42@epitech.eua and secondemail@wanadoofr");
		testInput(m, "email.test epitech.eu");
		testInput(m, "email.test@.eu");
		testInput(m, "@a.eu");
		testInput(m, "e@a.e");
		testInput(m, "e@a.it");
	}

	return EXIT_SUCCESS;
}
