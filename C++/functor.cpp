/*
 * Adopted from http://stackoverflow.com/a/356992/225052 lisenced under cc-by-sa 3.0
 * keyword: functors, function object
 */
#include <iostream>

class MyFunctor {
	public:
		int operator()(int x) {
			return x*2;
		}
};

int main() {

	MyFunctor doubler;
	int x = doubler(5);
	std::cout << x << std::endl;

	return 0;
}
