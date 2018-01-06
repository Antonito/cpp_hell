#include <iostream>
#include "Inspector.hpp"

struct test {}; 
struct lol {};

std::ostream &operator<<(std::ostream &out, const lol &)
{
	out << "Lol instance given";
	return out; 
}

int main ()
{
	test	t;
	lol	l;
	std::string str = "koala";

#if 1
	std::cout << "IsPrintable ?" <<std::endl;
	std::cout << "test        -> " << is_printable<std::ostream, test>::Value << std::endl;
	std::cout << "lol         -> " << is_printable<std::ostream, lol>::Value << std::endl;
	std::cout << "std::string -> " << is_printable<std::ostream, std::string>::Value << std::endl;
#else
	inspect(t);
	inspect(str);
	inspect(l);
#endif
	return 0;
}