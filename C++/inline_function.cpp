#include <iostream>

inline int a_plus_b_power2(int a, int b) {
	return (a + b) * (a + b);
}

int main() {
	for(int a = 0; a < 9999999999999; ++a)
		for(int b = 0; b < 999999999999; ++b)
			a_plus_b_power2(a, b);	

	return 0;
}
