/*
 * Adopted from http://stackoverflow.com/a/142809/225052 licensed under cc-by-sa 3.0
 */

#include <stdio.h>
#include <stdlib.h>

void populate_array(int *array,
		size_t array_size,
		int (*get_next_value)(void)) {
	for (size_t i = 0; i < array_size; i++) {
		array[i] = get_next_value();
	}
}

int get_next_value(void) {
	return rand();
}

int main(int argc, char* argv[]) {
	int my_array[10];
	populate_array(my_array, 10, get_next_value);

	for (size_t i = 0; i < 10; i++) {
		printf("my_array[%d]=%d\n", i, my_array[i]);
	}

	return 0;
}
