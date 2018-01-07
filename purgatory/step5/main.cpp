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
	std::vector<FSA> fsas;
	std::vector<std::string> words;

	words.push_back("evil");
	words.push_back("evian");
	words.push_back("criminel");
	words.push_back("mechant");

	for (std::size_t i = 0; i < words.size(); ++i)
	{
		fsas.push_back(FSA());

		FSA &fsa = fsas.back();
		std::string prev;

		for (std::size_t j = 0; j < words[i].length() + 1; ++j)
		{
			State cur = State::create();

			if (j > 0)
			{
				fsa.add(cur);
				fsa[prev].linkTo(cur, words[i][j - 1]);
			}
			else
			{
				fsa.addInitial(cur);
			}
			prev = cur.name();
		}
	}

	FSA &evil = fsas[0];
	FSA &evian = fsas[1];
	FSA &criminel = fsas[2];
	FSA &mechant = fsas[3];

	std::ofstream evilFile("original_evil.txt");
	std::ofstream evianFile("original_evian.txt");
	std::ofstream criminelFile("original_criminel.txt");
	std::ofstream mechantFile("original_mechant.txt");
	std::ofstream concatenation1("concatenation1.txt");
	std::ofstream concatenation2("concatenation2.txt");
	std::ofstream join1("join1.txt");
	std::ofstream join2("join2.txt");
	std::ofstream join_multiple("join_multiple.txt");
	std::ofstream combination1("combination1.txt");
	std::ofstream combination2("combination2.txt");
	std::ofstream combinationDfa("combination_dfa.txt");

	evilFile << evil;
	evianFile << evian;
	criminelFile << criminel;
	mechantFile << mechant;

	concatenation1 << (evil + evian);
	concatenation2 << (evian + mechant + criminel + evil);

	join1 << (evil ^ criminel);
	join2 << (mechant | criminel);
	join_multiple << ((evil | mechant | evian) ^ criminel);

	FSA combination = ((criminel + (evil ^ evian)) | mechant);

	combination1 << combination;
	combination2 << ((evil + mechant) | (criminel + evian));

	combinationDfa << combination.subset();

	return EXIT_SUCCESS;
}
