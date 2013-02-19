// Addopted from http://stackoverflow.com/a/840504/225052 under cc-by-sa 3.0 license.

#include <stdio.h>

int addInt(int, int);
int (*funtionPtr)(int , int);

int main(int argc, char* argv[]) {

	funtionPtr = &addInt;

	int sum = (*funtionPtr)(2, 3);
	
	printf("Sum: %d", sum);

	return 0;
}

int addInt(int a, int b) {
		return a + b;
}
