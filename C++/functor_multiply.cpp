/*
 * Adopted from http://stackoverflow.com/a/357022/225052 licensed under cc-by-sa 3.0
 */

#include <iostream>
#include <algorithm>

class MuliplyBy {
	private:
		int factor;
	public:
		MuliplyBy(int x)
			:factor(x) {
			}

		int operator()(int other) const {
			return factor*other;
		}
};

int main() {
	int a;

	MuliplyBy m(3);
	std::cout << m(5) << std::endl;
	std::cout << "----------" << std::endl;
	
	int array[5] = {1, 2, 3, 4, 5};
	std::transform(array, array+5, array, MuliplyBy(4));

	for( int i=0; i < 5; i++) {
		std::cout << array[i] << " ";
	}

	return 0;
}
