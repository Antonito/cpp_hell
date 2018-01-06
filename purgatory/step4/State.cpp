#include <sstream>
#include <iostream>
#include "State.hpp"

State::State() :
	m_name(""),
	m_final(false),
	m_nextState(""),
	m_charToNext('\0')
{
}

State::State(std::string const &name) :
	m_name(name),
	m_final(false),
	m_nextState(""),
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
	if (c == '\0')
	{
		std::cerr << "You cannot link over character '\\0'" << std::endl;
		throw std::exception();
	}
	if (m_charToNext != '\0' && m_charToNext != c)
	{
		std::cerr << "This state is already linked over an other letter ('" << m_charToNext << '\'' << std::endl;
		throw std::exception();
	}
	for (std::size_t i = 0; i < m_nextState.size(); ++i)
	{
		if (m_nextState[i] == s.name())
		{
			return ;
		}
	}
	m_nextState.push_back(s.name());
	m_charToNext = c;
}

void State::lambdaLink(State &s)
{
	this->linkTo(s, -1);
}

bool State::isLambda() const
{
	return m_charToNext == -1;
}