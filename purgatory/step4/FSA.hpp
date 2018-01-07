#ifndef FSA_HPP_
# define FSA_HPP_

# include <string>
# include <map>
# include "State.hpp"

class FSA
{
public:
	FSA();
	~FSA();

	State &operator[](std::string const &name);
	State const &operator[](std::string const &name) const;

	void add(State const &state);
	void addInitial(State const &state);
	void setInitial(std::string const &name);
	State *initial()
	{
		return m_initial;
	}

	State const *initial() const
	{
		return m_initial;
	}

	std::vector<std::string> closure(std::string const &name) const;
	std::vector<std::string> closure(std::vector<std::string> const &set) const;
	std::vector<std::string> move(std::vector<std::string> const &set, char c) const;
	FSA *subset() const;

	std::string toDotFormat() const;

private:
	std::string getAlphabet() const;
	std::map<std::string, State> m_state;
	State *m_initial;
};

std::ostream &operator<<(std::ostream &os, FSA const &fsa);

#endif // !FSA_HPP_
