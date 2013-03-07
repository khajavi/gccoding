#include <iostream>
#include <assert.h>

struct add_x {
	add_x(int x)
		:x(x) {

		}
	int operator()(int y) {
		return x + y;
	}
	private:
		int x;
};

int main() {
	add_x add42(42);
	int i = add42(8);
	assert( i == 50 );

	return 0;
}
