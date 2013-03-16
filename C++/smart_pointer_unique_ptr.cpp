#include <iostream>
#include <memory>

class Foo {
	public:
		Foo() {
			std::cout << "Foo is cunstructed." << std::endl;
		}

		~Foo() {
			std::cout << "Foo is destructed." << std::endl;
		}
};

int main (int argc, char const* argv[]) {

	std::unique_ptr<Foo> foo_ptr(new Foo());
	
	return 0;
}

