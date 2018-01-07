#ifndef STATE_HPP_
# define STATE_HPP_

# include <string>
# include <map>
# include <vector>
# include "Function.hpp"

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

	bool hasCallback() const
	{
		return m_function != NULL;
	}

	void execCallback(std::string const &str) const
	{
		if (m_function)
		{
			(*m_function)(str);
		}
	}

private:
	typedef Function<void(std::string const &)> func_t;

public:
	template <typename T>
	void setCallback(T t)
	{
		func_t *f = new func_t(t);

		addFunction(f);
		m_function = f;
	}

private:
	static std::map<func_t *, int> m_functions;
	static void addFunction(func_t *);
	static void removeFunction(func_t *);
	std::string m_name;
	std::vector<std::pair<char, std::string> > m_links;
	bool m_isLambda;
	func_t *m_function;
};

#endif // !STATE_HPP_
