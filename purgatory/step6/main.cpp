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
	std::cout << "  \"" << str << "\"\n";

	if (matcher.find(str))
	{
		std::cout << "  -> Found !\n\n";
	}
	else
	{
		std::cout << "  -> Not found\n\n";
	}
}

static void testInputCount(Matcher &matcher, std::string const &str)
{
	std::size_t count;
	std::cout << "  \"" << str << "\"\n";

	if (matcher.find(str, count))
	{
		std::cout << "  -> Found " << count << " times\n\n";
	}
	else
	{
		std::cout << "  -> Not found\n\n";
	}
}

static void printTitle(std::string const &title)
{
	std::string s(5, '=');

	std::cout << s << ' ' << title << ' ' << s << '\n';
	std::cout << std::string(s.length() * 2 + 2 + title.length(), '-') << '\n';
}

static std::string s(int n)
{
	std::stringstream ss;

	ss << 'S' << n;
	return ss.str();
}

int main()
{
	std::string expr = "(evil|(an))|(mechant)|(criminel)";
	Matcher m(expr);

	std::cout << "Expression: " << expr << "\n\n";

	printTitle("Match all 4 of the string");
	testInputCount(m, "I am an evil criminel mechant, and I drink some evian");

	printTitle("No match");
	testInputCount(m, "No match there");

	printTitle("Sneaky match");
	testInputCount(m, "The 666 beast is really deviant");

	return EXIT_SUCCESS;
}
