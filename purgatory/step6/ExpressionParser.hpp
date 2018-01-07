#ifndef EXPRESSIONPARSER_HPP_
# define EXPRESSIONPARSER_HPP_

# include <string>
# include <sstream>
# include "FSA.hpp"

class ExpressionParser
{
public:
	explicit ExpressionParser(std::string const &pattern);
	~ExpressionParser();

	FSA getDFA() const;
private:
	FSA subExpr() const;
	FSA singleLetter() const;

	std::string m_pattern;
	mutable std::istringstream m_is;
};

#endif // !EXPRESSIONPARSER_HPP_
