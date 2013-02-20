#include <iostream>

class TMyClass {
	public:
		int Dolt(float a, char b, char c) {
				std::cout << "TMyClass::Dolt" << std::endl;
				return a-b+c;
		}		
};

int main(int argc, char* argv[]) {

		int (TMyClass::*pt2member)(float, char, char) = NULL;
		pt2member = &TMyClass::Dolt;

		TMyClass* instance1 = new TMyClass;
		int result1 = (instance1->*pt2member)(12, 'a', 'b');

		std::cout << "result1 : " << result1 << std::endl;

		TMyClass instance2;
		int result2 = (instance2.*pt2member)(12, 'a', 'b');
		std::cout << "result2 : " << result2 << std::endl;
	
		return 0;
}
