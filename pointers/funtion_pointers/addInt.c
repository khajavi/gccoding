// Addopted from http://stackoverflow.com/a/840504/225052 under cc-by-sa 3.0 license.

#include <stdio.h>

int addInt(int, int);
int (*funtionPtr)(int , int);
int add2to3(int);

int main(int argc, char* argv[]) {

	funtionPtr = &addInt;

	int sum = (*funtionPtr)(2, 3);
	
	printf("Sum: %d\n", sum);
	
	//Passing the pointer to another funtion:
	printf("Sum: %d", add2to3(sum));

	return 0;
}

int addInt(int a, int b) {
		return a + b;
}

int add2to3(int a) {
		return a;
}
