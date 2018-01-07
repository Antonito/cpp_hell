#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "FSA.hpp"

FSA::FSA() :
	m_state(),
	m_hasInitial(false),
	m_initial("")
{
}

FSA::~FSA()
{
}

State &FSA::operator[](std::string const &name)
{
	return m_state.at(name);
}

State const &FSA::operator[](std::string const &name) const
{
	return m_state.at(name);
}

void FSA::add(State const &state)
{
	m_state[state.name()] = state;
}

void FSA::addInitial(State const &state)
{
	this->add(state);
	this->setInitial(state.name());
}

void FSA::setInitial(std::string const &name)
{
	m_initial = name;
	m_hasInitial = true;
}

std::vector<std::string> FSA::closure(std::string const &name) const
{
	State const &s = m_state.at(name);
	std::vector<std::string> res;

	res.push_back(name);

	if (s.isLambda())
	{
		for (std::size_t i = 0; i < res.size(); ++i)
		{
			State const &t = m_state.at(res[i]);

			if (t.isLambda())
			{
				std::vector<std::string> tmp = t.getLinkedStates();

				for (std::size_t j = 0; j < tmp.size(); ++j)
				{
					if (std::find(res.begin(), res.end(), tmp[j]) == res.end())
					{
						res.push_back(tmp[j]);
					}
				}
			}
		}
	}

	std::sort(res.begin(), res.end());
	return res;
}

std::vector<std::string> FSA::closure(std::vector<std::string> const &set) const
{
	std::vector<std::string> res;

	for (std::size_t k = 0; k < set.size(); ++k)
	{
		std::string const &name = set[k];
		State const &s = m_state.at(name);

		res.push_back(name);

		if (s.isLambda())
		{
			for (std::size_t i = 0; i < res.size(); ++i)
			{
				State const &t = m_state.at(res[i]);

				if (t.isLambda())
				{
					std::vector<std::string> tmp = t.getLinkedStates();

					for (std::size_t j = 0; j < tmp.size(); ++j)
					{
						if (std::find(res.begin(), res.end(), tmp[j]) == res.end())
						{
							res.push_back(tmp[j]);
						}
					}
				}
			}
		}
	}

	std::sort(res.begin(), res.end());
	return res;
}

std::vector<std::string> FSA::move(std::vector<std::string> const &set, char c) const
{
	std::vector<std::string> res;

	for (std::size_t i = 0; i < set.size(); ++i)
	{
		State const &s = m_state.at(set[i]);

		if (s.isLambda() == false && s.has(c))
		{
			std::string const &link = s[c];

			if (std::find(res.begin(), res.end(), link) == res.end())
			{
				res.push_back(link);
			}
		}
	}

	std::sort(res.begin(), res.end());
	return res;
}

FSA FSA::subset() const
{
	std::vector<State> dfaStates;
	std::vector<std::vector<std::string> > dfaSets;
	std::vector<std::string> initial = this->closure(m_initial);
	std::queue<std::vector<std::string> > processing;
	std::string alphabet = this->getAlphabet();

	processing.push(initial);
	dfaSets.push_back(initial);
	dfaStates.push_back(State::create());
	while (processing.size() != 0)
	{
		std::vector<std::string> current = processing.front();
		std::size_t curPos = std::find(dfaSets.begin(), dfaSets.end(), current) - dfaSets.begin();

		processing.pop();

		for (std::size_t i = 0; i < alphabet.length(); ++i)
		{
			std::vector<std::string> state = this->move(current, alphabet[i]);

			if (state.size() == 0)
			{
				continue;
			}

			std::vector<std::string> closure = this->closure(state);

			if (closure.size() == 0)
			{
				continue;
			}

			std::vector<std::vector<std::string> >::iterator found =
				std::find(dfaSets.begin(), dfaSets.end(), closure);
			std::size_t foundPos = found - dfaSets.begin();

			if (found == dfaSets.end())
			{
				dfaSets.push_back(closure);
				dfaStates.push_back(State::create());
				processing.push(closure);
			}

			dfaStates[curPos].linkTo(dfaStates[foundPos], alphabet[i]);
		}
	}

	FSA res;

	res.addInitial(dfaStates[0]);
	for (std::size_t i = 1; i < dfaStates.size(); ++i)
	{
		res.add(dfaStates[i]);
	}

	return res;
}

std::string FSA::toDotFormat() const
{
	std::stringstream ss;

	ss << "digraph {\n";

	for (std::map<std::string, State>::const_iterator it = m_state.begin();
		it != m_state.end(); ++it)
	{
		std::vector<std::pair<char, std::string> > const &links = it->second.getLinks();

		if (it != m_state.begin())
		{
			ss << '\n';
		}

		if (it->second.isFinal())
		{
			ss << '\t' << it->second.name() << "[fillcolor=red style=filled];\n";
		}

		for (std::size_t i = 0; i < links.size(); ++i)
		{
			ss << '\t' << it->second.name() << " -> " << links[i].second << " [label=";
			if (links[i].first != -1)
			{
				ss << links[i].first;
			}
			else
			{
				ss << "LAMBDA";
			}
			ss << "];\n";
		}
	}

	ss << '}';
	return ss.str();
}

FSA FSA::operator|(FSA const &right) const
{
	return FSA::join(*this, right, true);
}

FSA FSA::operator^(FSA const &right) const
{
	return FSA::join(*this, right, false);
}

FSA FSA::operator+(FSA const &second) const
{
	return FSA::concatenate(*this, second);
}

FSA &FSA::operator|=(FSA const &right)
{
	return *this = FSA::join(*this, right, true);
}

FSA &FSA::operator^=(FSA const &right)
{
	return *this = FSA::join(*this, right, false);
}

FSA &FSA::operator+=(FSA const &second)
{
	return *this = FSA::concatenate(*this, second);
}

FSA FSA::join(FSA const &left, FSA const &right, bool joinOutput)
{
	FSA res;
	std::vector<std::string> outs;
	State initial = State::create();

	if (!left.hasInitial() && !right.hasInitial())
	{
		return res;
	}
	else if (!left.hasInitial())
	{
		return right;
	}
	else if (!right.hasInitial())
	{
		return left;
	}

	res.addInitial(initial);

	for (std::map<std::string, State>::const_iterator it = left.m_state.begin();
		it != left.m_state.end(); ++it)
	{
		if (it->second.isFinal())
		{
			outs.push_back(it->first);
		}
		res.add(it->second);
	}
	res[initial.name()].lambdaLink(res[left.initial()]);

	for (std::map<std::string, State>::const_iterator it = right.m_state.begin();
		it != right.m_state.end(); ++it)
	{
		if (it->second.isFinal())
		{
			outs.push_back(it->first);
		}
		res.add(it->second);
	}
	res[initial.name()].lambdaLink(res[right.initial()]);

	if (joinOutput)
	{
		State output = State::create();
		std::string const &name = output.name();

		res.add(output);

		for (std::size_t i = 0; i < outs.size(); ++i)
		{
			res[outs[i]].lambdaLink(res[name]);
		}
	}
	return res;
}

FSA FSA::concatenate(FSA const &first, FSA const &second)
{
	FSA res;
	std::vector<std::string> outs;

	if (!first.hasInitial() && !second.hasInitial())
	{
		return res;
	}
	else if (!first.hasInitial())
	{
		return second;
	}
	else if (!second.hasInitial())
	{
		return first;
	}

	for (std::map<std::string, State>::const_iterator it = first.m_state.begin();
		it != first.m_state.end(); ++it)
	{
		if (it->second.isFinal())
		{
			outs.push_back(it->first);
		}
		res.add(it->second);
	}

	res.setInitial(first.initial());

	for (std::map<std::string, State>::const_iterator it = second.m_state.begin();
		it != second.m_state.end(); ++it)
	{
		res.add(it->second);
	}

	for (std::size_t i = 0; i < outs.size(); ++i)
	{
		res[outs[i]].lambdaLink(res[second.initial()]);
	}
	return res;
}

std::string FSA::getAlphabet() const
{
	std::string alphabet;

	for (std::map<std::string, State>::const_iterator it = m_state.begin(); it != m_state.end(); ++it)
	{
		std::vector<char> l = it->second.getLinkLetters();

		for (std::size_t i = 0; i < l.size(); ++i)
		{
			if (l[i] > 0 && std::find(alphabet.begin(), alphabet.end(), l[i]) == alphabet.end())
			{
				alphabet += l[i];
			}
		}
	}

	std::sort(alphabet.begin(), alphabet.end());
	return alphabet;
}

std::ostream & operator<<(std::ostream & os, FSA const & fsa)
{
	os << fsa.toDotFormat();

	return os;
}
