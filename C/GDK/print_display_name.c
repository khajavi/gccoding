#include <gdk/gdk.h>
#include <glib.h>

int main( int argc, char* argv[] ) {

	gdk_init( &argc, &argv );

	gchar* display_name;


	g_printf("Screen Height: %i", gdk_screen_height());
	gdk_beep();

	gdk_exit( 0 );

	return 0;
}
