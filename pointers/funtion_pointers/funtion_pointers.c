#include <stdio.h>

int devide(int a, int b) {
		printf("%d/%d is :%d\n",a ,b, a/b);
}

int (*devide_ptr1)(int, int);
int (*devide_ptr2)(int, int);
int (**devide_ptr_ptr)(int, int) = &devide_ptr1;
int (***devide_ptr_ptr_ptr)(int, int) = &devide_ptr_ptr;
int (*devide_array[3])(int , int) = {devide, devide, devide};
typedef int (*devide_funcptr)(int , int);
devide_funcptr my_devide_ptr = devide;

int main(int argc, char* argv[]) {
	devide_ptr1 = devide;
	devide_ptr1(6, 3);

	devide_ptr2 = &devide;
	devide_ptr2(9, 3);

	(*devide_ptr_ptr)(10, 5);
	//*devide_ptr_ptr(10, 5); Error
	
	(**devide_ptr_ptr_ptr)(8, 2);
	int i;
	for(i = 0; i < 3; i++ ) {
		(*devide_array[i])(i+20, i+1);
	}

	my_devide_ptr(99, 9);
	return 0;
}
