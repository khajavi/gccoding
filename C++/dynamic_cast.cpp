#include <iostream>

class CBase{ 
};

class CDerived: public CBase{
};

int main() {
	CBase b;
	CBase* pb;

	CDerived d;
	CDerived* pd;

	pb = dynamic_cast<CBase*>(&d);
	pd = dynamic_cast<CDerived*>(&b); //compiler error

	return 0;
}
