#include <iostream> 
#include <iomanip>

using namespace std;

struct Time {
	int hours;
	int minutes;
};

ostream &operator << ( ostream &os, Time &t ) {
	os << setfill('0') << setw( 2 ) << t.hours;
	os << ":";
	os << setfill('0') << setw( 2 ) << t.minutes;
	return os;
}

istream &operator >> ( istream &is, Time &t ) {
	is >> t.hours;
	is.ignore(1, ':');
	is >> t.minutes;
	return is;
}

int main (int argc, char const* argv[]) {
	
	Time time;
	time.hours = 1;
	time.minutes = 43;
	int a;

	operator>>( cin, time );
	cout << time << endl;

	cin >> (cin , time);
	cout << time << endl;

	cin >> time;
	cout << time << endl;

	return 0;
}
