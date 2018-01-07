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
	FSA _subExpr() const;
	FSA subExpr() const;
	FSA singleLetter() const;
	FSA parseRange() const;
	void addRangeChar(char c, FSA &range, std::string const &initial, std::string const &final) const;
	FSA filterModifier(FSA expr) const;
	void zeroOrOneMod(FSA &expr) const;
	void zeroOrMoreMod(FSA &expr) const;
	void oneOrMoreMod(FSA &expr) const;

	std::string m_pattern;
	mutable std::istringstream m_is;
};

#endif // !EXPRESSIONPARSER_HPP_
