#ifndef LEXER_HPP_
# define LEXER_HPP_

# include <vector>
# include "Matcher.hpp"

class Lexer
{
public:
	template <typename T>
	Lexer &addLexer(std::string const &regex, T callback)
	{
		m_matchers.push_back(Matcher(regex));
		m_matchers.back().setMatchCallback(callback);
		return *this;
	}

	Lexer &addLexer(std::string const &regex);

	void consume(std::string const &input);
private:
	std::vector<Matcher> m_matchers;
};

#endif // !LEXER_HPP_
