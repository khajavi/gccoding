#include <iostream>
using namespace std;

int main (int argc, char const* argv[])
{
	int character;
	const int EOF = cin.eof();

	cout << "Before input, cin.eof() is " << cin.eof() << endl 
		<< "Enter a sentence followed by end-of-file: " << endl;

	while ( ( character = cin.get() ) != EOF )
		cout.put( character );

	return 0;
}
