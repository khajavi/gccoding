#include <iostream>

void memory_leak() {
	int *data = new int;
	*data = 15;
//	delete data;
}


int main() {
	while (true) {
		memory_leak();
	}

	return 0;
}
