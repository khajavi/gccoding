#include <iostream>
using namespace std;

int main (int argc, char const* argv[])
{
	int student_age;

	cout << "Student age: " ;
	cin >> student_age;

	try {
		if (student_age < 0) {
			throw "Positive Number Required";
		}
		cout << "\nStudent Age: " << student_age << "\n\n";
	} catch (const char* Message) {
		cout << "Error: " << Message;
	}

	return 0;
}

