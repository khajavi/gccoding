#include <iostream>
#include <stdexcept>

class Foo {
	public:
		int* bar;
		Foo() {
			bar = new int;
			throw std::runtime_error("Foo::Foo() failed");
		}

		~Foo() {
			std::cout << "before delete bar" << std::endl;
			delete bar;
			std::cout << "after delete bar" << std::endl;
		}
};


int main (int argc, char const* argv[]) {
	Foo *foo = new Foo();
	std::cout << "before delete foo" << std::endl;
	delete foo;
	std::cout << "after delete foo" << std::endl;

	return 0;
}
