#include <iostream>
#include "Matcher.hpp"

Matcher::Matcher(FSA &fsa) : m_fsa(fsa)
{
}

bool Matcher::find(std::string const &str)
{
	if (!m_fsa.initial())
	{
		return false;
	}

	std::string state = m_fsa.initial()->name();

	for (std::size_t pos = 0; pos < str.length(); ++pos)
	{
		State const &s = m_fsa[state];

		if (s.has(str[pos]))
		{
			state = s[str[pos]];
		} 
		else
		{
			state = m_fsa.initial()->name();
		}
		if (m_fsa[state].isFinal())
		{
			return true;
		}
	}
	return false;
}

bool Matcher::find(std::string const &str, std::size_t &count)
{
	count = 0;

	if (!m_fsa.initial())
	{
		return false;
	}

	std::string state = m_fsa.initial()->name();
	bool found = false;

	for (std::size_t pos = 0; pos < str.length(); ++pos)
	{
		State const &s = m_fsa[state];

		if (s.has(str[pos]))
		{
			state = s[str[pos]];
		}
		else
		{
			state = m_fsa.initial()->name();
		}
		if (m_fsa[state].isFinal())
		{
			++count;
			found = true;
			state = m_fsa.initial()->name();
		}
	}
	return found;
}
