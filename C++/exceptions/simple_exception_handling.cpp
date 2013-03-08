#include <iostream>
#include <stdexcept>
using namespace std;

class FooException: public runtime_error {
	public:
		FooException():
			runtime_error("exception message") {
			}
};

void foo() {
	throw FooException();
}

int main (int argc, char const* argv[])
{
	try {
		foo();
	} catch (FooException &fooException) {
		cout << "Exception occurred: " << 
			fooException.what() << endl;
	}

	return 0;
}
