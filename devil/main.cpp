#include <iostream>
#include <vector>
#include "Inspector.hpp"

struct test {};
struct lol {};

static std::ostream &operator<<(std::ostream &out, const lol &)
{
	out << "Lol instance given";
	return out;
}

static void testIsPrintable()
{
	test	t;
	lol	l;
	std::string str = "koala";
	std::vector<test> vec;

	std::cout << "==== IsPrintable ====" <<std::endl;
	std::cout << "test              -> " << 
		is_printable<std::ostream, test>::Value << std::endl;
	std::cout << "lol               -> " << 
		is_printable<std::ostream, lol>::Value << std::endl;
	std::cout << "std::string       -> " << 
		is_printable<std::ostream, std::string>::Value << std::endl;
	std::cout << "std::vector<test> -> " << 
		is_printable<std::ostream, std::vector<test> >::Value
		<< std::endl;
}

int main ()
{
	test	t;
	lol	l;
	std::string str = "koala";
	std::vector<test> vec;

	std::cout << "==== Inspect ====" <<std::endl;
	std::cout << "test              -> ";
	inspect(t);
	std::cout << "lol               -> ";
	inspect(str);
	std::cout << "std::string       -> ";
	inspect(l);
	std::cout << "std::vector<test> -> ";
	inspect(vec);

	return 0;
}