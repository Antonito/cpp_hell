#include <cstdlib>
#include <iostream>
#include "Lexer.hpp"

static void integer(std::string const &token)
{
	std::cout << "- Integer: " << token << std::endl;
}

static void criminel(std::string const &token)
{
	std::cout << "- Evil: \"" << token << '"' << std::endl;
}

int main()
{
	Lexer l;

	l.addLexer("-?[0-9]+", &integer)
		.addLexer("(me+cha+nt)|(criminels*)", &criminel);

	l.consume("Super meeeechaaaaaaaaaant42");
	l.consume("Nothing to see here");
	l.consume("A smooth criminel");
	l.consume("We can also be more criminelssssss hehe, like 50000 or maybe 11990283");
	l.consume("10+80-200");
	return EXIT_SUCCESS;
}
