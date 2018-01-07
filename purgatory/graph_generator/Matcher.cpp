#include <iostream>
#include "Matcher.hpp"

Matcher::Matcher(FSA const &fsa) : m_fsa(fsa)
{
}

Matcher::Matcher(std::string const &pattern) :
	m_fsa(ExpressionParser(pattern).getDFA())
{
}

bool Matcher::find(std::string const &str)
{
	if (!m_fsa.hasInitial())
	{
		return false;
	}

	std::string state = m_fsa.initial();
	std::string token;

	for (std::size_t pos = 0; pos < str.length() + 1; ++pos)
	{
		State const &s = m_fsa[state];

		if (s.has(str[pos]))
		{
			state = s[str[pos]];
			token += str[pos];
		} 
		else if (m_fsa[state].isFinal())
		{
			m_fsa[state].execCallback(token);
			return true;
		}
		else
		{
			state = m_fsa.initial();
			token = "";
		}
	}
	return false;
}

bool Matcher::find(std::string const &str, std::size_t &count)
{
	count = 0;

	if (!m_fsa.hasInitial())
	{
		return false;
	}

	std::string state = m_fsa.initial();
	std::string token;
	bool found = false;

	for (std::size_t pos = 0; pos < str.length() + 1; ++pos)
	{
		State const &s = m_fsa[state];

		if (s.has(str[pos]))
		{
			state = s[str[pos]];
			token += str[pos];
		}
		else if (m_fsa[state].isFinal())
		{
			m_fsa[state].execCallback(token);
			++count;
			found = true;
			state = m_fsa.initial();
			token = "";
		}
		else
		{
			state = m_fsa.initial();
			token = "";
		}
		
	}
	return found;
}
