#include <iostream>
using namespace std;

void useStaticLocal();

int main (int argc, char const* argv[])
{		
	useStaticLocal();
	useStaticLocal();
	useStaticLocal();
	return 0;
}

void useStaticLocal() {
	static int x = 50;
	x++;
	cout << "Static x is: " << x << endl;
}
