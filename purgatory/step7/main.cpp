#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"
#include "ExpressionParser.hpp"

void testInput(Matcher &matcher, std::string const &str)
{
	std::cout << "Input: \"" << str << "\"\n";

	if (matcher.find(str))
	{
		std::cout << "Found !\n";
	}
	else
	{
		std::cout << "Not found\n";
	}
	std::cout << std::endl;
}

void testInputCount(Matcher &matcher, std::string const &str)
{
	std::size_t count;
	std::cout << "Input: \"" << str << "\"\n";

	if (matcher.find(str, count))
	{
		std::cout << "Found " << count << " times\n";
	}
	else
	{
		std::cout << "Not found\n";
	}
	std::cout << std::endl;
}

std::string s(int n)
{
	std::stringstream ss;

	ss << 'S' << n;
	return ss.str();
}

int main()
{
	ExpressionParser ep("(evi(l)|(an))|(mechant)");

	std::ofstream out("dfa.txt");

	out << ep.getDFA();

	Matcher m("(evil|(an))|(mechant)|(criminel)");

	testInputCount(m, "I am an evil criminel mechant, and I drink some evian");
	return EXIT_SUCCESS;
}
