#include <iostream>
#include <sigc++/sigc++.h>


class AlienDetector {
	public:
		AlienDetector();
		void run();
		sigc::signal<void, std::string> signal_detected;
};

AlienDetector::AlienDetector() {}

void AlienDetector::run() {}

void warn_people(std::string where) {
	std::cout<< "There are aliens in "<< where << std::endl;
}

int main() {
	AlienDetector myDetector;
	myDetector.signal_detected.connect(sigc::ptr_fun(warn_people));
	myDetector.run();
	return 0;
}
