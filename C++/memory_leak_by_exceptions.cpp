#include <iostream>
#include <stdexcept>

int main() {
	int *ptr = new int;
	throw std::runtime_error("Error");
	std::cout << "delete ptr will not be execute" << std::endl;
	delete ptr;

	return 0;
}
