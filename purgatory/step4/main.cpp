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
	FSA fsa;
	std::vector<std::string> words;
	std::size_t fullLength = 0;

	words.push_back("evil");
	words.push_back("criminel");
	words.push_back("mechant");

	fsa.addInitial(State::create());
	for (std::size_t i = 0; i < words.size(); ++i)
	{
		fullLength += words[i].size() + 1;
		for (std::size_t j = 0; j < words[i].length() + 1; ++j)
		{
			fsa.add(State::create());
		}
	}
	fsa.add(State::create());

	int n = 1;

	for (std::size_t i = 0; i < words.size(); ++i)
	{
		fsa["S0"].lambdaLink(fsa[s(n)]);
		for (std::size_t j = 0; j < words[i].length(); ++j)
		{
			fsa[s(n)].linkTo(fsa[s(n + 1)], words[i][j]);
			++n;
		}
		fsa[s(n)].lambdaLink(fsa[s(fullLength + 1)]);
		++n;
	}

	std::ofstream file("graph.txt");

	file << fsa;

	FSA subset = fsa;

	std::ofstream file2("graph2.txt");

	file2 << subset;

	Matcher m(subset);
	std::size_t count;

	testInput(m, "");
	testInput(m, "evil is at the beggining");
	testInput(m, "the end is evil");
	testInput(m, "evil is at the beggining and the end is evil");
	testInput(m, "the evil within the input");
	testInput(m, "nothing malicious here");
	testInput(m, "is Evil found ?");
	testInputCount(m, "");
	testInputCount(m, "evil is at the beggining");
	testInputCount(m, "the end is evil");
	testInputCount(m, "evil is at the beggining and the end is evil");
	testInputCount(m, "the evil within the input");
	testInputCount(m, "nothing malicious here");
	testInputCount(m, "is Evil found ?");
	testInputCount(m, "The evil devil is evil like maybe 3 or 4 time, if he's really evil");

	return EXIT_SUCCESS;
}
