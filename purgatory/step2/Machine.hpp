#ifndef MACHINE_HPP_
# define MACHINE_HPP_

# include <string>

enum State
{
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7,
	STATE_ERROR
};

enum Action
{
	MA,
	HR,
	ACTION_ERROR
};

extern State stateTable[5][5];
extern Action actionTable[5][5];

class Machine
{
public:
	Machine();
	Machine(Machine const &other);
	~Machine();

	Machine &operator=(Machine const &other);
	void check(std::string const &str);
private:
	void reset();

	std::string m_word;
	State m_current;
	std::size_t m_count;
	std::string m_token;
};

#endif
