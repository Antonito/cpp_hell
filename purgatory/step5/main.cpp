#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"

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

	std::ofstream evilFile("dot/original_evil.dot");
	std::ofstream evianFile("dot/original_evian.dot");
	std::ofstream criminelFile("dot/original_criminel.dot");
	std::ofstream mechantFile("dot/original_mechant.dot");
	std::ofstream concatenation1("dot/concatenation1.dot");
	std::ofstream concatenation2("dot/concatenation2.dot");
	std::ofstream join1("dot/join1.dot");
	std::ofstream join2("dot/join2.dot");
	std::ofstream join_multiple("dot/join_multiple.dot");
	std::ofstream combination1("dot/combination1.dot");
	std::ofstream combination2("dot/combination2.dot");
	std::ofstream combinationDfa("dot/combination_dfa.dot");

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
