#include <glib.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <string.h>
 
/*
 *
 * Colorpicker. That's all.
 * gcc -Wall -g colorselector.c -o colorselector `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
 * or
 * gcc -Wall -g colorselector.c -o colorselector `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
 * 
 *
 */
 
static void
print_color(GdkColor *color) {
    g_printf("#%X%X%X",
            color->red / 256, color->green / 256, color->blue / 256);
 
}
 
static void
on_dialog_close(GtkWindow *dialog, GtkWidget *color_selector) {
    GdkColor color;
 
    gtk_color_selection_get_current_color(
            GTK_COLOR_SELECTION(color_selector), &color);
    print_color(&color);
    gtk_main_quit();
}
 
static void
show_selector(GdkColor *color) {
    GtkWidget *dialog, *content_area, *color_selector;
 
    dialog = gtk_dialog_new_with_buttons("Choose color", NULL,
            GTK_DIALOG_MODAL,
            GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
            GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT,
            NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    color_selector = gtk_color_selection_new();
    gtk_container_add(GTK_CONTAINER (content_area), color_selector);
    if (color != NULL) {
        gtk_color_selection_set_current_color(
                GTK_COLOR_SELECTION(color_selector), color);
    }
 
    g_signal_connect_swapped(dialog, "response",
            G_CALLBACK(gtk_widget_destroy), dialog);
    g_signal_connect(dialog, "close",
            G_CALLBACK(on_dialog_close), color_selector);
    g_signal_connect(dialog, "destroy",
            G_CALLBACK(on_dialog_close), color_selector);
 
    gtk_widget_show_all(dialog);
}
 
int
main(int argc, const char *argv[])
{
    GdkColor init_color;
    gdk_color_parse("#ffffff", &init_color);
 
    if (argc > 1) {
        if (gdk_color_parse(argv[1], &init_color) != TRUE) {
            return 3;
        }
    }
 
    gtk_init(&argc, (gchar ***)&argv);
    show_selector(&init_color);
    gtk_main();
    return 0;
}
