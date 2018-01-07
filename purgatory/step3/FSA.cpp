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