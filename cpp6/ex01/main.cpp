#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data;
	data.num = 42;
	data.str = "Hello, world!";
	data.ptr = "bruh";

	uintptr_t raw = Serializer::serialize(&data);

	Data* dataPtr = Serializer::deserialize(raw);
	
	std::cout << "raw: " << raw << std::endl;
	if (dataPtr == &data) {
		std::cout << "Serialization and deserialization successful!\n";
	} else {
		std::cout << "Serialization and deserialization failed.\n";
	}
	return 0;
}
