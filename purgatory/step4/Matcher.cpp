#include "Matcher.hpp"

Matcher::Matcher(FSA &fsa) : m_fsa(fsa)
{
}

bool Matcher::find(std::string const &str)
{
	State *state = m_fsa.initial();

	if (!state)
	{
		return false;
	}

	for (std::size_t pos = 0; pos < str.length(); ++pos)
	{
		if (state->getLinkLetter() == str[pos])
		{
			state = state->getLink();

			if (!state)
			{
				state = m_fsa.initial();
			}
		}
		else
		{
			state = m_fsa.initial();
		}
		if (state->isFinal())
		{
			return true;
		}
	}
	return false;
}

bool Matcher::find(std::string const &str, std::size_t &count)
{
	State *state = m_fsa.initial();
	bool found = false;
	
	count = 0;

	if (!state)
	{
		return false;
	}

	for (std::size_t pos = 0; pos < str.length(); ++pos)
	{
		if (state->getLinkLetter() == str[pos])
		{
			state = state->getLink();

			if (!state)
			{
				state = m_fsa.initial();
			}
		}
		else
		{
			state = m_fsa.initial();
		}
		if (state->isFinal())
		{
			found = true;
			count++;
		}
	}
	return found;
}