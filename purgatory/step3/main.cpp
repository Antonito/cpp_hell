#include <cstdlib>
#include <iostream>
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

int main()
{
	FSA fsa;

	fsa.addInitial(State::create());
	fsa.add(State::create());
	fsa.add(State::create());
	fsa.add(State::create());
	fsa.add(State::create());

	fsa["S0"].linkTo(fsa["S1"], 'e');
	fsa["S1"].linkTo(fsa["S2"], 'v');
	fsa["S2"].linkTo(fsa["S3"], 'i');
	fsa["S3"].linkTo(fsa["S4"], 'l');

	fsa["S4"].setFinal(true);

	Matcher m(fsa);
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
