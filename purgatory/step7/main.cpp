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

	matcher.find(str, count);
}

static void printTheTokenAndMore(std::string const &token)
{
	std::cout << "  -> The token \"" << token << "\" was found !\n";
}

static void printTitle(std::string const &title)
{
	std::string s(5, '=');

	std::cout << '\n' << s << ' ' << title << ' ' << s << '\n';
	std::cout << std::string(s.length() * 2 + 2 + title.length(), '-') << '\n';
}

int main()
{
	ExpressionParser ep("(evi(l)|(an))|(mechant)");

	FSA dfa = ep.getDFA();
	std::vector<std::string> finalStates = dfa.finalStates();

	for (std::size_t i = 0; i < finalStates.size(); ++i)
	{
		dfa[finalStates[i]].setCallback(&printTheTokenAndMore);
	}

	Matcher m(dfa);

	printTitle("2 Matches");
	testInput(m, "I am a criminel mechant, and I drink some evian");

	printTitle("Evil match");
	testInput(m, "I am a so evil");

	printTitle("No match");
	testInput(m, "I am alone...");

	std::cout << std::endl;
	return EXIT_SUCCESS;
}
