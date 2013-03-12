#include <iostream>
using namespace std;

int main (int argc, char const* argv[])
{
	const int SIZE = 8;
	char buff1[ SIZE ];
	char buff2[ SIZE ];

	cout << "Enter a sentence: " << endl;
	cin >> buff1;

	cout << "\nThe string read with cin was: " << endl
		<<  buff1 << endl << endl;

	cin.get( buff2, SIZE );

	cout << "The string read with cin.get was: " << endl
		<< buff2 << endl;	
	
	return 0;
}
