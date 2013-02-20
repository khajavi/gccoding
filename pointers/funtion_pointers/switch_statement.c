/*
 * This programm is adopted from http://www.newty.de/fpt/intro.html
 */

#include <stdio.h>

float Plusi 	(float, float);
float Minus 	(float, float);
float Multiply(float, float);
float Divide 	(float, float);

void Switch(float, float, char);
void Switch_With_Function_Pointer(float, float, float (*)(float, float));

int main(int argc, char* argv[]) {
	Switch(2, 5, '+');
	Switch_With_Function_Pointer(2, 5, &Minus); 
	Switch_With_Function_Pointer(2, 5, Minus); 
	return 0;
}

float Plus    (float a, float b) { return a+b; }
float Minus   (float a, float b) { return a-b; }
float Multiply(float a, float b) { return a*b; }
float Divide  (float a, float b) { return a/b; }

void Switch(float a, float b, char opCode) {
	float result;

	switch(opCode) {
			case '+': result = Plus   	(a, b); break;
			case '-': result = Minus  	(a, b); break;
			case '*': result = Multiply (a, b); break;
			case '/': result = Divide 	(a, b); break;
	}
	printf( "Switch: %f+%f=%f\n", a, b, result);
}

void Switch_With_Function_Pointer(float a,float b, float (*pt2Func)(float, float)) {
	float result = pt2Func(a, b);
	printf("Switch replaced by function pointer: %f-%f=%f\n", a, b, result);

}
