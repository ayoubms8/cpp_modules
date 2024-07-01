#pragma once
#include <cstdint>
#include "Data.hpp"
#include <string>

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &copy);
	Serializer &operator=(Serializer const &copy);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
