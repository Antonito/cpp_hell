#ifndef STATE_HPP_
# define STATE_HPP_

# include <string>
# include <map>
# include <vector>

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

	bool has(char link) const;
	std::string const &operator[](char c) const;

	std::vector<std::pair<char, std::string> > const &getLinks() const;
	std::vector<std::string> getLinkedStates() const;
	std::vector<char> getLinkLetters() const;

	bool isLambda() const
	{
		return m_isLambda;
	}

	std::string const &name() const
	{
		return m_name;
	}

	bool isFinal() const
	{
		return m_links.size() == 0;
	}

private:
	std::string m_name;
	std::vector<std::pair<char, std::string> > m_links;
	bool m_isLambda;
};

#endif // !STATE_HPP_
