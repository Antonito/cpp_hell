#include <string>
#include <iostream>

#include "Bind.hpp"

void simpleTest();

static std::string zeroParam()
{
	return "Hello World";
}

static int oneParam(int value)
{
	return value * 2;
}

static int twoParams(int v1, int v2)
{
	return v1 * v2;
}

static double threeParams(int a, int b, double c)
{
	std::cout << "(" << a << " + " << b
		<< ") / " << c << ": ";
	return (a + b) / c;
}

static int fourParams(int a, int b, int c, int d)
{
	return (a * b) + (c * d);
}

static double fiveParams(double a, int b, int c, int d, int e)
{
	return a * bind(&fourParams, b, c, d, e)();
}

static double sixParams(double a, double b, int c, int d, int e, int f)
{
	return bind(&fiveParams, b, c, d, e, f)() / a;
}

void simpleTest()
{
	std::cout << "=== Simple bind test ===\n"
	<< "-- ZeroParam --\n"
	<< bind(&zeroParam)() << '\n'
	<< "-- OneParam --\n"
	<< "5 * 2 -> " << bind(&oneParam, 5)() << '\n'
	<< "-- TwoParams --\n"
	<< "5 * 10 -> " << bind(&twoParams, 5, 10)() << '\n'
	<< "-- ThreeParams --\n"
	<< bind(&threeParams, 1335, 2, 1.2)() << '\n'
	<< "-- FourParams --\n"
	<< bind(&fourParams, 2, 3, 4, 5)() << '\n'
	<< "-- FiveParams --\n"
	<< bind(&fiveParams, 8, 9, 23, 34, 1)() << '\n'
	<< "-- SixParams --\n"
	<< bind(&sixParams, 2, 4, 6, 1, 3, 5)() << '\n';
}
