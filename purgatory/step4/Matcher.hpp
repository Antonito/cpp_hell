#ifndef MATCHER_HPP_
# define MATCHER_HPP_

# include "FSA.hpp"

class Matcher
{
public:
	explicit Matcher(FSA &fsa);

	bool find(std::string const &str);
	bool find(std::string const &str, std::size_t &count);

private:
	FSA &m_fsa;
};

#endif // !MATCHER_HPP_
