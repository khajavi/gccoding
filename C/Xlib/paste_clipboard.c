// CODE
 
/* test.cc
 * Compile with: g++ `pkg-config --cflags --libs x11` test.cc -o test
 * Run with: ./test
 */
#include <stdio.h>//printf
#include <string.h>//strlen
#include <stdlib.h>//atexit
 
#define Cursor X11_Cursor
#include <X11/Xlib.h> // Every Xlib program must include this
#undef Cursor//F U Mac OS
Display* xconn;
const char* Clipboard_GetText() {
	int size;
	const char* str = XFetchBytes(xconn,&size);
	return str;
}
bool Clipboard_SetText(const char* str) {
	XStoreBytes(xconn,str,strlen(str));
	return true;
}
void cleanup(void) {
	XFree(xconn);
}
 
int main() {
	//atexit ( *cleanup );
	xconn = XOpenDisplay(NULL);
	//Clipboard_SetText("MWAHAHAHA");
	//just spew it out for now
	printf("%s\n",Clipboard_GetText());
	cleanup();
	return 0;
}
