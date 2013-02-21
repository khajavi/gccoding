/*
 * Adopted from http://www.cplusplus.com/doc/tutorial/classes2/
 */
#include <iostream>
using namespace std;

class CVector {
	public:
		int x, y;
		CVector() {
			x = 0;
			y = 0;
		};
		CVector(int , int);
		CVector operator + (CVector);
};

CVector::CVector(int a, int b) {
	x = a;
	y = b;
}

CVector CVector::operator+ (CVector param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return (temp);
}

int main() {
	CVector a(3, 4);
	CVector b(1, 2);
	CVector c;

	c = a + b;
	cout << c.x << ", " << c.y << endl;
	
	CVector p(1, 3);
	CVector q(5, 2);
	CVector r;

	r = p.operator+(b);
	cout << r.x << ", " << r.y << endl;
	
	CVector m(5 ,7);
	CVector n;
	n = m;
	cout << "Default Copy Constructor" << endl;
	cout << n.x << ", " << n.y << endl;
	m.x = 8;
	m.y = 3;
	cout << n.x << ", " << n.y << endl;
	cout << m.x << ", " << m.y << endl;


	return 0;
}
