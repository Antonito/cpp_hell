#include <iostream>
#include "Machine.hpp"

State stateTable[5][5] = {
	{          S1, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR },
	{ STATE_ERROR,          S2, STATE_ERROR, STATE_ERROR, STATE_ERROR },
	{ STATE_ERROR, STATE_ERROR,          S3, STATE_ERROR, STATE_ERROR },
	{ STATE_ERROR, STATE_ERROR, STATE_ERROR,          S4, STATE_ERROR },
	{ STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR }
};

Action actionTable[5][5] = {
	{          MA, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR },
	{ ACTION_ERROR,          MA, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR },
	{ ACTION_ERROR, ACTION_ERROR,          MA, ACTION_ERROR, ACTION_ERROR },
	{ ACTION_ERROR, ACTION_ERROR, ACTION_ERROR,          MA, ACTION_ERROR },
	{ ACTION_ERROR, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR,          HR }
};

Machine::Machine() :
	m_word("evil"),
	m_current(S0),
	m_count(0),
	m_token()
{
}

Machine::Machine(Machine const &other) :
	m_word(other.m_word),
	m_current(S0),
	m_count(0),
	m_token()
{
}

Machine &Machine::operator=(Machine const &other)
{
	if (this != &other)
	{
		m_word = other.m_word;
	}
	return *this;
}

Machine::~Machine()
{
}

void Machine::check(std::string const &str)
{
	this->reset();

	for (std::size_t pos = 0; pos <= str.length(); ++pos)
	{
		if (str[pos] != m_word[m_count])
		{
			m_count = m_word.length();
		}
	
		switch (actionTable[m_current][m_count])
		{
		case MA:
			m_token += str[pos];
			if (m_count != 0 || pos == str.length() || str[pos + 1] != m_word[0])
			{
				m_current = stateTable[m_current][m_count];
				m_count++;
			}
			break;
		case HR:
			std::cout << m_token << std::endl;
			pos--;
		default:
			this->reset();
			break;
		}
	}
}

void Machine::reset()
{
	m_current = S0;
	m_count = 0;
	m_token = "";
}