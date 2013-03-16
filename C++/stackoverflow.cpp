#include <iostream>
#include <cstdlib>

using namespace std;


void f(int a) {
	cout << a << ", ";
	f(++a);
}

int main (int argc, char const* argv[]) {
	
	f(0);

	return 0;
}
