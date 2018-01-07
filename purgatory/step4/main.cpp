#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"

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

	std::ofstream file("nfa.txt");

	file << nfa;

	FSA *dfa = nfa.subset();

	std::ofstream file2("dfa.txt");

	file2 << *dfa;


	Matcher m(*dfa);
	std::size_t count;

	testInput(m, "");
	testInput(m, "evil is at the beggining");
	testInput(m, "the end is criminel");
	testInput(m, "mechant is at the beggining and the end is evil");
	testInput(m, "the evil within");
	testInput(m, "nothing malicious here");
	testInput(m, "is Evil found ?");
	testInputCount(m, "");
	testInputCount(m, "evil is at the beggining");
	testInputCount(m, "the end is mechant");
	testInputCount(m, "evian is at the beggining and the end is evil");
	testInputCount(m, "the evil within");
	testInputCount(m, "nothing malicious here");
	testInputCount(m, "is Evil found ?");
	testInputCount(m, "The criminel devil is evil like maybe 3 or 4 time, if he's really mechant");
	testInputCount(m, "is Evil found ? No, but criminel or evian...");

	delete dfa;

	return EXIT_SUCCESS;
}
