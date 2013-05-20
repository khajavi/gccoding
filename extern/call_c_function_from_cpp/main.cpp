#include <iostream>

extern "C" {
	void f();
}

void func( void ) {
	std::cout << "\nbeing used within C++ code\n";
}

int main( void ) {
	f();
	func();
	return 0;
}
