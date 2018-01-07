#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"

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
	FSA nfa;
	std::vector<std::string> words;
	std::size_t fullLength = 0;

	words.push_back("evil");
	words.push_back("evian");
	words.push_back("criminel");
	words.push_back("mechant");

	nfa.addInitial(State::create());
	for (std::size_t i = 0; i < words.size(); ++i)
	{
		fullLength += words[i].size() + 1;
		for (std::size_t j = 0; j < words[i].length() + 1; ++j)
		{
			nfa.add(State::create());
		}
	}
	nfa.add(State::create());

	int n = 1;

	for (std::size_t i = 0; i < words.size(); ++i)
	{
		nfa["S0"].lambdaLink(nfa[s(n)]);
		for (std::size_t j = 0; j < words[i].length(); ++j)
		{
			nfa[s(n)].linkTo(nfa[s(n + 1)], words[i][j]);
			++n;
		}
		nfa[s(n)].lambdaLink(nfa[s(fullLength + 1)]);
		++n;
	}

	FSA *dfa = nfa.subset();

	Matcher m(*dfa);

	printTitle("Empty string");
	testInput(m, "");

	printTitle("One match at the beggining");
	testInput(m, "evil is at the beggining");

	printTitle("One match at then end");
	testInput(m, "the end is evil");

	printTitle("One at the beggining and one at the end");
	testInput(m, "evil is at the beggining and the end is evil");

	printTitle("One match within the string");
	testInput(m, "the evil within the input");

	printTitle("No match");
	testInput(m, "nothing malicious here");

	printTitle("Case test (should not be found)");
	testInput(m, "is Evil found ?");

	printTitle("Empty string");
	testInputCount(m, "");

	printTitle("One match at the beggining");
	testInputCount(m, "evil is at the beggining");

	printTitle("One match at then end");
	testInputCount(m, "the end is evil");

	printTitle("One at the beggining and one at the end");
	testInputCount(m, "evil is at the beggining and the end is evil");

	printTitle("One match within the string");
	testInputCount(m, "the evil within the input");

	printTitle("No match");
	testInputCount(m, "nothing malicious here");

	printTitle("Case test (should not be found)");
	testInputCount(m, "is Evil found ?");

	printTitle("4 matches");
	testInputCount(m, "The evil devil is evil like maybe 3 or 4 time, if he's really evil");

	delete dfa;

	return EXIT_SUCCESS;
}
