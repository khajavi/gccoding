/* g++ font_path_list.cxx $(pkg-config x11 --libs --cflags) */
 
#include <X11/Xlib.h>
 
#include <cassert>
#include <cstdlib>
 
#include <algorithm>
#include <iostream>
#include <iterator>
 
 
int main()
{
	Display* const d = XOpenDisplay(NULL); assert(d);
	int const s = DefaultScreen(d);
 
	int fontListSize;
	char** const fontList = XGetFontPath(d, &fontListSize); assert(fontList);
 
	std::copy( fontList, fontList + fontListSize,
		std::ostream_iterator<char const*>(std::cout, "\n") );
 
	XFreeFontPath(fontList);
	XCloseDisplay(d);
 
	return EXIT_SUCCESS;
}
