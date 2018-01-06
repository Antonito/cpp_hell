#include <iostream>
#include <string>
#include "Bind.hpp"

static void printParameters(std::ostream &stream, std::string const &p1,
				int const p2, double const p3,
				void const *p4, char const p5)
{
	stream << "P1: " << p1 << '\n' <<
	"P2: " << p2 << '\n' <<
	"P3: " << p3 << '\n' <<
	"P4: " << p4 << '\n' <<
	"P5: " << p5 << std::endl;
}

void printInt(int i)
{
	std::cout << i << std::endl;
}

void placeholderTest()
{
	std::string const str = "Hello";
	int const nb1 = 40;
	double const nb2 = 1.2;
	void const *ptr = reinterpret_cast<void const *>(0xBADB002);
	char const c1 = '*';

	std::cout << "=== Placeholder bind test ===\n";
	std::cout << "-- PlacerHolder_1 parameter --\n";
	bind(&printParameters, Placeholder::_1,
		str, nb1, nb2, ptr, c1)(::ref(std::cout));
	std::cout << "-- PlacerHolder_2 parameter --\n";
	bind(&printParameters, Placeholder::_1,
		Placeholder::_2, nb1, nb2, ptr, c1)(::ref(std::cout), str);
	std::cout << "-- PlacerHolder_3 parameter --\n";
	bind(&printParameters, Placeholder::_1,
		Placeholder::_2, Placeholder::_3,
		nb2, ptr, c1)(::ref(std::cout), str, nb1);
	std::cout << "-- PlacerHolder_4 parameter --\n";
	bind(&printParameters, Placeholder::_1,
		Placeholder::_2, Placeholder::_3,
		Placeholder::_4, ptr, c1)(::ref(std::cout), str, nb1, nb2);
	std::cout << "-- PlacerHolder_5 parameter --\n";
	bind(&printParameters, Placeholder::_1,
		Placeholder::_2, Placeholder::_3,
		Placeholder::_4, Placeholder::_5,
		c1)(::ref(std::cout), str, nb1, nb2, ptr);
	std::cout << "-- PlacerHolder_6 parameter --\n";
	bind(&printParameters, Placeholder::_1,
		Placeholder::_2, Placeholder::_3,
		Placeholder::_4, Placeholder::_5,
		Placeholder::_6)(::ref(std::cout), str, nb1, nb2, ptr, c1);
}