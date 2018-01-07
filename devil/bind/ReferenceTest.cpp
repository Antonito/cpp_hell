#include <iostream>
#include <ostream>
#include <string>
#include "Bind.hpp"

static void fillStream(std::ostream &stream, std::string const &str)
{
	stream << str << std::endl;
}

static std::ostream &returnStream(std::ostream &stream)
{
	return stream;
}

static void modifierTest(int& n1, int& n2, const int& n3)
{
	std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	++n2;
	std::cout << "Incremented n2 in function ..." << '\n';
}

void referenceTest()
{
	std::string const str = "Hello World";

	std::cout << "=== Reference bind test ===\n";
	std::cout << "-- Reference parameter --\n";
	bind(&fillStream, ::ref(std::cout), str)();
	std::cout << "-- Reference return method --\n";
	bind(&returnStream, ::ref(std::cerr))() << "Impressive!" << std::endl;
	int n1 = 1, n2 = 2, n3 = 3;
	bind(&modifierTest, n1, ::ref(n2), ::cref(n3))();
	std::cout << "After, n2 -> " << n2 << std::endl;
}