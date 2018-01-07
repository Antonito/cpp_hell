#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
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
		case '[':
			expr += this->filterModifier(this->parseRange());
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

FSA ExpressionParser::parseRange() const
{
	FSA range;
	char c;
	State initialState = State::create();
	State finalState = State::create();
	std::string initial = initialState.name();
	std::string final = finalState.name();

	finalState.setIsFinal(true);

	range.addInitial(initialState);
	range.add(finalState);

	m_is.get(c);
	m_is.get(c);

	bool first = true;
	char last;

	while (c != ']')
	{
		if (c == EOF)
		{
			std::cerr << "Missing ']' or empty []" << std::endl;
			throw std::exception();
		}

		if ((c == '-' && (first || m_is.peek() == ']')) ||
			(c == ']' && first))
		{
			addRangeChar(c, range, initial, final);
		}
		else if (c == '-')
		{
			char next;

			m_is.get(next);
			if (last >= next)
			{
				std::cerr << "Range values reversed " << last << '-' << next << std::endl;
				throw std::exception();
			}
			for (char ch = last + 1; ch <= next; ++ch)
			{
				addRangeChar(ch, range, initial, final);
			}
		}
		else
		{
			addRangeChar(c, range, initial, final);
		}

		if (first)
		{
			first = false;
		}
		last = c;
		m_is.get(c);
	}

	return range;
}

void ExpressionParser::addRangeChar(char c, FSA &range, std::string const &initial, std::string const &final) const
{
	State s = State::create();
	State s2 = State::create();

	range.add(s);
	range.add(s2);

	range[initial].lambdaLink(range[s.name()]);
	range[s.name()].linkTo(range[s2.name()], c);
	range[s2.name()].lambdaLink(range[final]);
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