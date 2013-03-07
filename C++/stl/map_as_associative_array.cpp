#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	typedef map<string, float> stringFloatMap;
	stringFloatMap coll;

	coll["VAT"] = 0.15;
	coll["Pi"] = 3.1415;
	coll["an arbitratory number"] = 4983.223;
	coll["Null"] = 0;

	stringFloatMap::iterator pos;
	for (pos = coll.begin(); pos != coll.end(); pos++) {
		cout << "key: \"" << pos->first << "\""
				<< "value: " << pos->second << endl;
	}

	return 0;
}
