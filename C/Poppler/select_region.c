#include <gtk/gtk.h>
#include <poppler.h>
#include <gdk/gdk.h>
#include <glib.h>
#include <cairo.h>

static PopplerDocument* doc;
static PopplerPage* page;

static void on_destroy( GtkWidget* w, gpointer data ) {
	gtk_main_quit();
}

static gboolean on_expose( GtkWidget* w, GdkEventExpose* e, gpointer data ) {
	cairo_t* cr;
	cr = gdk_cairo_create( w->window );
	

//	poppler_page_get_size( page, &width, &height );

	//printf("width: %f, Height: %f", width, height);

	PopplerSelectionStyle style;
	style = POPPLER_SELECTION_GLYPH;

	PopplerColor color;
	color.red = (guint) 65535;
	color.green = (guint) 0;
	color.blue = (guint) 0;

	PopplerColor bcolor;
	bcolor.red = (guint) 0;
	bcolor.green = (guint) 65535;
	bcolor.blue = (guint) 0;

	PopplerRectangle rect;
	rect.x1 = 0.0;
	rect.x2 = 100;
	rect.y1 = 0.0;
	rect.y2 = 100;

	PopplerRectangle oldrect;
	rect.x1 = 0.0;
	rect.x2 = 133;
	rect.y1 = 0.0;
	rect.y2 = 200;



	poppler_page_render_selection( page, cr, &rect, &oldrect, style, &color, &bcolor );
//	poppler_page_render( page, cr );
	cairo_destroy( cr );
	return FALSE;
}

int main( int argc, char* argv[] ) {
		
	GtkWidget* window;
	GError* err = NULL;
	
	gtk_init( &argc, &argv );
	

	doc = poppler_document_new_from_file( argv[1], NULL, &err );

	page = poppler_document_get_page( doc, 0 );

	window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	
	g_signal_connect( G_OBJECT( window ), "destroy", G_CALLBACK( on_destroy ), NULL );
	g_signal_connect( G_OBJECT( window ), "expose-event", G_CALLBACK( on_expose ), page );
	gtk_widget_set_app_paintable( window, TRUE );
	gtk_widget_show_all( window );

	gtk_main();

	return 0;
}
