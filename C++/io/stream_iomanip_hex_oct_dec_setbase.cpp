#include <iostream>
#include <iomanip>
using namespace std;

int main (int argc, char const* argv[])
{
	int number;

	cout << "Enter a decimal number: ";
	cin >> number;

	cout << number << " in hexadecimal is: " << hex
		<< number << endl;

	return 0;
}
