#ifndef MATCHER_HPP_
# define MATCHER_HPP_

# include "FSA.hpp"
# include "ExpressionParser.hpp"

class Matcher
{
public:
	explicit Matcher(FSA const &fsa);
	explicit Matcher(std::string const &pattern);

	bool find(std::string const &str);
	bool find(std::string const &str, std::size_t &count);

	template <typename T>
	void setMatchCallback(T t)
	{
		std::vector<std::string> finals = m_fsa.finalStates();

		for (std::size_t i = 0; i < finals.size(); ++i)
		{
			m_fsa[finals[i]].setCallback(t);
		}
	}

private:
	FSA m_fsa;
};

#endif // !MATCHER_HPP_
