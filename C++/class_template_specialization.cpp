/*
 * Adopted from http://www.cplusplus.com/doc/tutorial/templates/
 */
#include <iostream>
using namespace std;

template <class T>
class MyContainer {
		T element;
	public:
		MyContainer(T arg) {
			element = arg;
		}
		T increase() {
			return ++element;
		}
};

template <>
class MyContainer <char> {
		char element;
	public:
		MyContainer(char arg) {
			element = arg;
		}
		char uppercase() {
			if ((element > 'a') && (element <='z'))
				element += 'A'-'a';
			return element;
		}
};


int main() {
	MyContainer<int> my_int(7);
	MyContainer<char> my_char('j');

	cout << my_int.increase() << endl;
	cout << my_char.uppercase() << endl;
	return 0;
}
