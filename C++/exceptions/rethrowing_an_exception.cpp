/*
 * adopted from C++ How to Program, Fifth Edition
 */
#include <iostream>
#include <exception>
using namespace std;

void throwException() {
	try {
		cout << "   Funtion throwException throws an exception\n";
		throw exception();
	} catch (exception &) {
		cout << "   Exception handled in funtion throwException" 
			<< "\n    Funtion throwException rethrow exception";
		throw;
	}
	cout << "This also should not print \n";
}

int main (int argc, char const* argv[])
{
	try {
		cout << "\nmain invokes fntion throwException\n";
		throwException();
		cout << "This should not print\n";
	} catch (exception &) {
		cout << "\n\nException handled in main\n";
	}
	cout << "Program control continues after catch in main\n";
	return 0;
}

