/*
 * Adopted from C++ How to programm book
 */
#include <iostream>
using namespace std;
int main()
{
	const char *const word = "again";
	cout << "Value of word is: " << word << endl
	 << "Value of static_cast< void * >( word ) is: "
	 << static_cast< void * >( word ) << endl;
} // end main
	

