#ifndef FSA_HPP_
#define FSA_HPP_

#include <string>
#include <map>
#include "State.hpp"

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

private:
	std::map<std::string, State> m_state;
	State *m_initial;
};

#endif // !FSA_HPP_