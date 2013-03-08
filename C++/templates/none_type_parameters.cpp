#include <iostream>
using namespace std;

template <class T, int count = 3> //count = 3 (default parameter)
void loop_it(T x) {
	T val[count];

	for (int ii = 0; ii < count; ii++) {
		val[ii] = x++;
		cout << val[ii] << endl;
	}
}

int main (int argc, char const* argv[])
{
	float xx = 2.1;
	loop_it<float, 8>(xx);
	cout << "-----------" << endl;
	loop_it<float>(xx);  //c++11
	return 0;
}
