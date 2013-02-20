/*
 * Adopted from http://www.cplusplus.com/doc/tutorial/templates/
 */
#include <iostream>
using namespace std;

template <class T>
T get_max( T a, T b ) {
	T result;
	result = (a > b) ? a : b;
	return result;
}

int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;

	k = get_max<int>(i, j);
	n = get_max<long>(l, m);
	cout << k << endl;
	cout << n << endl;
	
	int p;
	long q;
	float f;
	p = get_max(4, 9); //implicit method same as get_max<int>(4, 9)
	q = get_max(5L, 3L);
	f = get_max(6., 1.);
	
	cout << p << endl;
	cout << q << endl;
	cout << f << endl;

	return 0;
}
