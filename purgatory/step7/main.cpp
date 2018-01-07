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
	std::cout << "Input: \"" << str << "\"\n";

	matcher.find(str);
}

static std::string s(int n)
{
	std::stringstream ss;

	ss << 'S' << n;
	return ss.str();
}

static void printTheTokenAndMore(std::string const &token)
{
	std::cout << "The token \"" << token << "\" was found !" << std::endl;
}

int main()
{
	ExpressionParser ep("(evi(l)|(an))|(mechant)");

	FSA dfa = ep.getDFA();
	std::vector<std::string> finalStates = dfa.finalStates();

	dfa[finalStates[0]].setCallback(&printTheTokenAndMore);

	Matcher m(dfa);

	testInput(m, "I am a criminel mechant, and I drink some evian");
	testInput(m, "I am a so evil");
	return EXIT_SUCCESS;
}
