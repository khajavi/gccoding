#include <X11/Xlib.h>
 
void move(int dx, int dy) {
    Display* d;
    d = XOpenDisplay(0);
    XWarpPointer(d,0,0,0,0,0,0,dx,dy);
    XCloseDisplay(d);
}
 
int main(void) {
    while(1) {
        move(2,2);
        move(-2,-2);
        sleep(2);
    }
    return 0;
}
