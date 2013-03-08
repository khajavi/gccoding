#include <iostream>
using namespace std;

template <class T, class U>
void square_and_print(T x, U y) {
	T result;
	U other_var;
	cout << "X: " << x << " " << x * x << endl;
	cout << "Y: " << y << " " << y * y << endl;
};


int main (int argc, char const* argv[])
{
	int ii = 2;
	float jj = 2.1;
	square_and_print<int , float>(ii, jj);
	square_and_print(2, 2.1); //implicit template expression
	square_and_print(2.1, 2); //2.1 will cast to int
	return 0;
}

