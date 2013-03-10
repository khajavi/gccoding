/*
 * adopted from http://www.geeksforgeeks.org/g-fact-26/
 */
#include <iostream>
using namespace std;

class myInteger {
	private:
		int value;

		myInteger(int v) {
			value = v;
		}
};

int main() {
	myInteger i; //Error: The compiler doesn't create default constructor
	getchar();
	return 0;
}
