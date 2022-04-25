#pragma once
#include <stdexcept>


class InstancesKingException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};