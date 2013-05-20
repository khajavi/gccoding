#include <stdio.h>

extern void func( void );

void f( void ) {
	printf( "\nBeing used within C code\n" );
}

int main( void ) {
	func();
	f();
	return 0;
}
