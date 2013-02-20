/*
 * Adopted from http://www.cplusplus.com/doc/tutorial/templates/
 */
#include <iostream>
using namespace std;

template <class T>
class mypair {
		T a, b;
	public:
		mypair(T first, T second) {
			a = first;
			b = second;
		}
		T get_max();
};

template <class T>
T mypair<T>::get_max() {
	T retval;
	retval = a > b ? a : b;
	return retval;
}

int main() {

	mypair<int> myobject(115, 36);
	mypair<double> myflout(3.0, 7.18);

	cout << myobject.get_max();
	cout << endl;
	cout << myflout.get_max();

	return 0;
}
