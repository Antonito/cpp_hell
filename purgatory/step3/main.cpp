#include <cstdlib>
#include <iostream>
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

	return EXIT_SUCCESS;
}
