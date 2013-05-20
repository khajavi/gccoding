#include <stdio.h>
#include <stdlib.h>
#include <poppler.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo.h>
#include <glib.h>

static PopplerDocument* doc;
static PopplerPage* page;

static void on_destroy( GtkWidget* w, gpointer data ) {
	gtk_main_quit();
}

static gboolean on_expose( GObject* w, GdkEventExpose* e, gpointer data ) {
	cairo_t* cr;
	GtkWidget* win = (GtkWidget*) w;
	cr = gdk_cairo_create( win->window );
	poppler_page_render( page, cr );
	cairo_destroy( cr );
	return FALSE;
}

int main( int argc, char* argv[] ) {
	GtkWidget* win;
	GError* err = NULL;

	gtk_init( &argc, &argv );
	
	doc = poppler_document_new_from_file( argv[1], NULL, &err);

	page = poppler_document_get_page( doc, 0 );

	int pages = poppler_document_get_n_pages( doc );
	printf("There are %d pages in this pdf.\n", pages );

	win = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	g_signal_connect(G_OBJECT( win ), "destroy", G_CALLBACK( on_destroy ), NULL );
	g_signal_connect( G_OBJECT( win ), "expose-event", G_CALLBACK( on_expose ), NULL );
	gtk_widget_set_app_paintable( win, TRUE );
	gtk_widget_show_all( win );
	
	gtk_main();

	return 0;
}
