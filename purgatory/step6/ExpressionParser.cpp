#include <cstdio>
#include <iostream>
#include "ExpressionParser.hpp"

ExpressionParser::ExpressionParser(std::string const &pattern) : m_pattern(pattern)
{
}

ExpressionParser::~ExpressionParser()
{
}

FSA ExpressionParser::getDFA() const
{
	m_is.str(m_pattern);

	return this->subExpr().subset();
}

FSA ExpressionParser::subExpr() const
{
	FSA expr;
	char c;
	bool paren = false;
	bool expressionDone = false;

	if (m_is.peek() == '(')
	{
		paren = true;
		m_is.get(c);
	}

	while (m_is.peek() != EOF)
	{
		char peek = m_is.peek();

		switch (peek)
		{
		case ')':
			if (!paren)
			{
				std::cerr << "Unmatching parenthesis in pattern: \"" << m_pattern << '"' << std::endl;
				throw std::exception();
			}
			m_is.get(c);
			paren = false;
			expressionDone = true;
			break;
		case '(':
			expr += this->subExpr();
			break;
		case '|':
			m_is.get(c);
			expr |= this->subExpr();
			expressionDone = true;
			break;
		default:
			expr += this->singleLetter();
			break;
		}
		if (expressionDone)
		{
			if (m_is.peek() != '|')
			{
				break;
			}
			expressionDone = false;
		}
	}

	return expr;
}

FSA ExpressionParser::singleLetter() const
{
	FSA expr;
	char c;

	m_is.get(c);

	State initial = State::create();
	State final = State::create();

	expr.addInitial(initial);
	expr.add(final);

	expr[initial.name()].linkTo(final, c);

	if (m_is.peek() == '|')
	{
		expr |= this->subExpr();
	}

	return expr;
}