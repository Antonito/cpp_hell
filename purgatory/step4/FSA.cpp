#include <queue>
#include "FSA.hpp"

FSA::FSA() :
	m_state(),
	m_initial(NULL)
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
	m_initial = &m_state[name];
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
				std::vector<std::string> tmp = t.getLinks();

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
					std::vector<std::string> tmp = t.getLinks();

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

	for (std::size_t i = 0; i < res.size(); ++i)
	{
		State const &s = m_state.at(res[i]);

		if (s.isLambda() == false && s.getLinkLetter() == c)
		{
			std::string const &link = s.getLinks()[0];

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
	std::vector<std::vector<std::string>> dfaStates;
	std::vector<std::string> initial = this->closure(m_initial->name());
	std::queue<std::vector<std::string>> processing;
	std::string alphabet = "evil";

	processing.push(initial);
	while (processing.size() != 0)
	{
		std::vector<std::string> current = processing.front();

		processing.pop();

		for (std::size_t i = 0; i < alphabet.length(); ++i)
		{
			std::vector<std::string> state = this->move(current, alphabet[i]);

			std::vector<std::string> closure = this->closure(state);
		}
	}
}