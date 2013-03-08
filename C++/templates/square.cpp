/*
 * adopted from http://www.yolinux.com/TUTORIALS/Cpp-Templates.html
 */
#include <iostream>
#define square_macro(x) (x * x) //we can use macro function like class template
using namespace std;

template <class T>  // alt: template <typename T>
inline T square(T x) {
	T result;
	result = x * x;
	return  result;
};


int main (int argc, char const* argv[])
{
		int i, ii;
		float x, xx;
		double y, yy;
		long z, zz;

		i = 2;
		x = 2.2;
		y = 2.2;
		z = 39450835L;

		ii = square<int>(i);
		cout << i << ": " << i << endl;
		
		xx = square<float>(x);
		cout << x << ": " << xx << endl;

		yy = square<double>(y);
		cout << y << ": " << yy << endl;

		zz = square(z);  //implicit template expression
		cout <<  z << ": " << zz << endl;
		
		zz = square_macro(z);
		cout << z << ": " << zz << endl;

		return 0;
}
	
