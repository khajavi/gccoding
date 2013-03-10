#include <iostream>
using namespace std;

int main (int argc, char const* argv[])
{
	int a = 2;
	int b = 3;

	/* Nonconstant pointer to Constant Data */
	const int *ptr1; //Read from right to left as “ptr1 is a pointer to an integer constant.”
	// *ptr1 = 4; //Error: cannot modify a const object
	ptr1 = &a; //No Error

	/* Constant Pointer to Nonconstant Data */
	int *const ptr2 = &a;
	// ptr2 = &b; //Error
	*ptr2 = 8; //Allowed

	/* Constant Pointer to Constant Data */
	const int *const ptr3 = &a;
	// *ptr3 = 7; // Error
	// ptr = &a; // Error
	

	return 0;
}
