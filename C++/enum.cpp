/*
 * adopted from http://en.wikibooks.org/wiki/C%2B%2B_Programming/Programming_Languages/C%2B%2B/Code/Keywords/enum
 */
#include <iostream>
using namespace std;

enum color {Red, Green, Blue};
enum sex {Male, Female} ali, zahra;
enum screen_width {SMALL = 800, MEDIUM = 1280};
enum screen_height {SMALL = 600, MEDIUM = 768};
enum Months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };


int main (int argc, char const* argv[])
{
	color hair = Red;
	color eyes = Blue;
	color skin = Green;

	std::cout << "Hair: " << hair << 
		"\nEye: " << eyes <<
		"\nSkin: " << skin << std::endl;
	
	ali = Male;
	zahra = Female;

	std::cout << "Ali is : " << ali <<
		"\nZahra is :" << zahra << std::endl;
	
	return 0;
}
