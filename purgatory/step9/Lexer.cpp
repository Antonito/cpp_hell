#include "Lexer.hpp"

Lexer &Lexer::addLexer(std::string const &regex)
{
	m_matchers.push_back(Matcher(regex));
	return *this;
}

void Lexer::consume(std::string const &input)
{
	std::size_t count;

	for (std::size_t i = 0; i < m_matchers.size(); ++i)
	{
		m_matchers[i].find(input, count);
	}
}