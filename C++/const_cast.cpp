#include <iostream>

void print(char* str) {
	std::cout << str << std::endl;
}

int main() {
	const char* c = "Sample Text";

//	print(c);  Compiler Error
	print(const_cast<char*>(c));

	return 0;
}
