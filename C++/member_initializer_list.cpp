#include <iostream>
using namespace std;

class Foo {
	public:
		Foo( int a, int b):
			non_constant_data_member(a),
			constant_data_member(b)
		{
		}
		int get_non_constant_data_member() {
			return non_constant_data_member;
		}

		int get_constant_data_member() {
			return constant_data_member;
		}
	private:
		int non_constant_data_member;
		const int constant_data_member;
};


int main (int argc, char const* argv[])
{
	Foo foo(2, 3);
	cout << foo.get_non_constant_data_member() << endl;
	cout << foo.get_constant_data_member() << endl;	
	return 0;
}

