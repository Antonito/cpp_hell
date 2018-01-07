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

	std::string const &initial() const
	{
		return m_initial;
	}

	std::vector<std::string> finalStates() const;

	std::vector<std::string> closure(std::string const &name) const;
	std::vector<std::string> closure(std::vector<std::string> const &set) const;
	std::vector<std::string> move(std::vector<std::string> const &set, char c) const;
	FSA subset() const;

	std::string toDotFormat() const;

	FSA operator|(FSA const &right) const;
	FSA operator^(FSA const &right) const;
	FSA operator+(FSA const &second) const;

	FSA &operator|=(FSA const &right);
	FSA &operator^=(FSA const &right);
	FSA &operator+=(FSA const &second);

	static FSA join(FSA const &left, FSA const &right, bool joinOuput = true);
	static FSA concatenate(FSA const &first, FSA const &second);

	bool empty() const
	{
		return m_state.empty();
	}

	std::size_t size() const
	{
		return m_state.size();
	}

	bool hasInitial() const
	{
		return m_hasInitial;
	}

private:
	std::string getAlphabet() const;
	std::map<std::string, State> m_state;
	bool m_hasInitial;
	std::string m_initial;
};

std::ostream &operator<<(std::ostream &os, FSA const &fsa);

#endif // !FSA_HPP_
