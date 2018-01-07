#include <sstream>
#include "State.hpp"

State::State() :
	m_name(""),
	m_final(false),
	m_nextState(NULL),
	m_charToNext('\0')
{
}

State::State(std::string const &name) :
	m_name(name),
	m_final(false),
	m_nextState(NULL),
	m_charToNext('\0')
{
}

State::State(State const &other) :
	m_name(other.m_name),
	m_final(other.m_final),
	m_nextState(other.m_nextState),
	m_charToNext(other.m_charToNext)
{
}

State::~State()
{
}

State &State::operator=(State const &other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		m_final = other.m_final;
		m_nextState = other.m_nextState;
		m_charToNext = other.m_charToNext;
	}
	return *this;
}

bool State::operator==(State const &other) const
{
	return m_name == other.m_name;
}

bool State::operator!=(State const &other) const
{
	return m_name != other.m_name;
}

bool State::operator>(State const &other) const
{
	return m_name > other.m_name;
}

bool State::operator<(State const &other) const
{
	return m_name < other.m_name;
}

bool State::operator>=(State const &other) const
{
	return m_name >= other.m_name;
}

bool State::operator<=(State const &other) const
{
	return m_name <= other.m_name;
}

State State::create()
{
	static int n = 0;
	std::stringstream ss;

	ss << 'S' << n++;
	return State(ss.str());
}

void State::linkTo(State &s, char c)
{
	m_nextState = &s;
	m_charToNext = c;
}