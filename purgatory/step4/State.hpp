#ifndef STATE_HPP_
#define STATE_HPP_

#include <string>
#include <vector>

class State
{
public:
	State();
	State(std::string const &name);
	State(State const &other);
	~State();

	State &operator=(State const &other);

	bool operator==(State const &rhs) const;
	bool operator!=(State const &rhs) const;
	bool operator>(State const &rhs) const;
	bool operator<(State const &rhs) const;
	bool operator>=(State const &rhs) const;
	bool operator<=(State const &rhs) const;

	static State create();

	void linkTo(State &s, char c);
	void lambdaLink(State &s);

	bool isLambda() const;

	std::string const &name() const
	{
		return m_name;
	}

	bool isFinal() const
	{
		return m_final;
	}

	void setFinal(bool isFinal)
	{
		m_final = isFinal;
	}

	std::vector<std::string> const &getLinks() const
	{
		return m_nextState;
	}

	char getLinkLetter() const
	{
		return m_charToNext;
	}

private:
	std::string m_name;
	bool m_final;
	std::vector<std::string> m_nextState;
	char m_charToNext;
};

#endif // !STATE_HPP_