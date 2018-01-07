#include <cstdlib>
#include <iostream>
#include "Lexer.hpp"

void integer(std::string const &token)
{
	std::cout << "Found the number " << token << std::endl;
}

void criminel(std::string const &token)
{
	std::cout << "Chief ! I found a \"" << token << "\" !!" << std::endl;
}

int main()
{
	Lexer l;

	l.addLexer("-?(0|1|2|3|4|5|6|7|8|9)+", &integer)
		.addLexer("(me+cha+nt)|(criminels*)", &criminel);

	l.consume("Super meeeechaaaaaaaaaant42");
	l.consume("Nothing to see here");
	l.consume("A smooth criminel");
	l.consume("We can also be more criminelssssss hehe, like 50000 or maybe 11990283");
	l.consume("10+80-200");
	return EXIT_SUCCESS;
}
