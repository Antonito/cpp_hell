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
	m_is.str('(' + m_pattern + ')');

	return this->_subExpr().subset();
}

FSA ExpressionParser::_subExpr() const
{
	FSA expr;
	char c;
	bool paren = false;

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
			if (paren)
			{
				m_is.get(c);
			}
			return expr;
		case '(':
			expr += this->subExpr();
			break;
		case '|':
			m_is.get(c);
			expr |= this->subExpr();
			break;
		case '?':
		case '*':
		case '+':
			std::cerr << "Unexpected symbol: '" << peek << '\'' << std::endl;
			throw std::exception();
		default:
			expr += this->filterModifier(this->singleLetter());
			break;
		}
	}

	return expr;
}

FSA ExpressionParser::subExpr() const
{
	return this->filterModifier(this->_subExpr());
}

FSA ExpressionParser::singleLetter() const
{
	FSA expr;
	char c;

	m_is.get(c);

	State initial = State::create();
	State final = State::create();

	final.setIsFinal(true);

	expr.addInitial(initial);
	expr.add(final);

	expr[initial.name()].linkTo(final, c);

	return expr;
}

FSA ExpressionParser::filterModifier(FSA expr) const
{
	if (expr.hasInitial())
	{
		switch (m_is.get())
		{
		case '?':
			this->zeroOrOneMod(expr);
			break;
		case '*':
			this->zeroOrMoreMod(expr);
			break;
		case '+':
			this->oneOrMoreMod(expr);
			break;
		default:
			m_is.unget();
			break;
		}
	}
	return expr;
}

void ExpressionParser::zeroOrOneMod(FSA &expr) const
{
	std::string initial = expr.initial();
	std::vector<std::string> finals = expr.finalStates();

	State s = State::create();

	expr.addInitial(s);
	expr[s.name()].lambdaLink(expr[initial]);

	for (std::size_t i = 0; i < finals.size(); ++i)
	{
		expr[s.name()].lambdaLink(expr[finals[i]]);
	}
}

void ExpressionParser::zeroOrMoreMod(FSA &expr) const
{
	std::string initial = expr.initial();
	std::vector<std::string> finals = expr.finalStates();

	State s = State::create();
	State s2 = State::create();

	s2.setIsFinal(true);

	expr.addInitial(s);
	expr.add(s2);

	expr[s.name()].lambdaLink(expr[initial]);
	expr[s.name()].lambdaLink(s2);

	for (std::size_t i = 0; i < finals.size(); ++i)
	{
		expr[finals[i]].setIsFinal(false);
		expr[finals[i]].lambdaLink(expr[initial]);
		expr[finals[i]].lambdaLink(expr[s2.name()]);
	}
}

void ExpressionParser::oneOrMoreMod(FSA &expr) const
{
	FSA copy = expr.clone();

	this->zeroOrMoreMod(copy);
	expr += copy;
}