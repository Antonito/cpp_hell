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

	std::cout << "  \"" << str << "\"\n";
	if (matcher.find(str, count))
	{
		std::cout << "  -> Found " << count << " time" << (count > 1 ? "s" : "") << '\n' << std::endl;
	}
	else
	{
		std::cout << "  -> Not found\n" << std::endl;
	}
}

static void printTitle(std::string const &title)
{
	std::string s(5, '=');

	std::cout << s << ' ' << title << ' ' << s << '\n';
	std::cout << std::string(s.length() * 2 + 2 + title.length(), '-') << '\n';
}

int main(int ac, char **av)
{
	std::string regex = "[-a-z0-9._]+@[-a-z0-9]+.[a-z][a-z]";

	Matcher m(regex);

	std::cout << "Regex: " << regex << '\n' << std::endl;

	if (ac > 1)
	{
		printTitle("User input");
		testInput(m, av[1]);
	}
	else
	{
		printTitle("Valid email");
		testInput(m, "e-mail.test@epitech.eu");

		printTitle("2 valid email");
		testInput(m, "e-mail.test_42@epitech.eu and second_email@wanadoo.fr");
		
		printTitle("2 invalid email");
		testInput(m, "e-mail.test_42@epitech.e and secondemail@wanadoofr");
		
		printTitle("Missing '@'");
		testInput(m, "e-mail.test epitech.eu");
		
		printTitle("Missing domain name");
		testInput(m, "e-mail.test@.eu");
		
		printTitle("Missing left part of the adress");
		testInput(m, "@a.eu");
		
		printTitle("Too short extension");
		testInput(m, "e@a.e");
		
		printTitle("Very short, but valid email");
		testInput(m, "e@a.it");
	}

	return EXIT_SUCCESS;
}
