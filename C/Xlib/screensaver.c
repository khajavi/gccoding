/* LDFLAGS='-L/usr/X11R6/lib/ -lX11 -lXext -lXss' make xidle */
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/scrnsaver.h>
 
int
main(int argc, char *argv[])
{
    XScreenSaverInfo info;
    Display *dpy = XOpenDisplay(NULL);
 
    if(NULL == dpy) {
        fprintf(stderr, "failed to open display\n");
        return 1;
    }
 
    int a = 0;
    int b = 0;
    XScreenSaverQueryExtension(dpy, &a, &b);
    printf("%d %d\n", a, b);
 
    XScreenSaverQueryInfo(dpy, RootWindow(dpy, DefaultScreen(dpy)), &info);
    printf("%d %d %d %d\n", info.state, info.til_or_since, info.idle, info.kind);
    return 0;
}
