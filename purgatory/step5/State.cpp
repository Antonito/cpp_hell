#include <sstream>
#include <iostream>
#include "State.hpp"

State::State() :
	m_name(""),
	m_links(),
	m_isLambda(false)
{
}

State::State(std::string const &name) :
	m_name(name),
	m_links(),
	m_isLambda(false)
{
}

State::State(State const &other) :
	m_name(other.m_name),
	m_links(other.m_links),
	m_isLambda(other.m_isLambda)
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
		m_links = other.m_links;
		m_isLambda = other.m_isLambda;
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
	if (c == -1 && !m_isLambda)
	{
		std::cerr << "This link is not a lambda" << std::endl;
		throw std::exception();
	}
	if (c != -1 && m_isLambda)
	{
		std::cerr << "State \"" << m_name << "\": This link is a lambda" << std::endl;
		throw std::exception();
	}

	if (m_isLambda == false)
	{
		for (std::size_t i = 0; i < m_links.size(); ++i)
		{
			if (m_links[i].first == c)
			{
				std::cerr << "State \"" << m_name << "\": This edge ('" << c << "') is already attributed" << std::endl;
				throw std::exception();
			}
		}
	}
	m_links.push_back(std::make_pair(c, s.name()));
}

bool State::has(char link) const
{
	for (std::size_t i = 0; i < m_links.size(); ++i)
	{
		if (m_links[i].first == link)
		{
			return true;
		}
	}
	return false;
}

std::string const &State::operator[](char c) const
{
	for (std::size_t i = 0; i < m_links.size(); ++i)
	{
		if (m_links[i].first == c)
		{
			return m_links[i].second;
		}
	}
	std::cerr << "State \"" << m_name << "\": There is no edge ('" << c << "')" << std::endl;
	throw std::exception();
}

void State::lambdaLink(State &s)
{
	if (m_links.empty())
	{
		m_isLambda = true;
	}
 	this->linkTo(s, -1);
}

std::vector<std::pair<char, std::string> > const &State::getLinks() const
{
	return m_links;
}

std::vector<std::string> State::getLinkedStates() const
{
	std::vector<std::string> res;

	res.reserve(m_links.size());

	for (std::size_t i = 0; i < m_links.size(); ++i)
	{
		res.push_back(m_links[i].second);
	}

	return res;
}

std::vector<char> State::getLinkLetters() const
{
	std::vector<char> res;

	res.reserve(m_links.size());

	for (std::size_t i = 0; i < m_links.size(); ++i)
	{
		res.push_back(m_links[i].first);
	}

	return res;
}