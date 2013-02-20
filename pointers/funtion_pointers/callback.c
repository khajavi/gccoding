/*
 * Adopted from http://stackoverflow.com/a/2738486/225052 licensed under cc-by-sa 3.0
 */
#include <stdio.h>

typedef void (*callback_t)(void);
callback_t callback;

void callback_proc(void) {
	printf("Inside callback funtion\n");
}

void reg(callback_t _callback) {
	printf("Inside registration\n");
	_callback();
}

int main() {
	callback = callback_proc;
	reg(callback);
	reg(callback_proc);

	return 0;
}
