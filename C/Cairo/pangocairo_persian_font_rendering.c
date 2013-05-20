#include <stdio.h>
#include <math.h>
#include <pango/pangocairo.h>

void rendertext(cairo_t *cr);

int main(int argc, char* argv[]) {
	cairo_t *cr;								// cairo instance
	cairo_status_t status;							// variable to hold the various states of the cairo lib
	cairo_surface_t *surface;						// the cairo surface to render to

	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 300, 100);	// cairo_image_surface_create(pixelformat, width, height);
	cr = cairo_create(surface);						// tell the cairo instance 'cr' to output to 'surface'
	cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);				// sets the drawing colour to white
	cairo_paint(cr);							// fill the surface with the active colour (if you don't do this, you will
										// be given a surface with a transparent background to draw on)

	rendertext(cr);								// do pango stuff here
	
	cairo_destroy(cr);							// free the cairo instance
	status = cairo_surface_write_to_png(surface, "out.png");		// output the contents of 'surface' to the file "out.png"
	cairo_surface_destroy(surface);						// free the surface
	if (status != CAIRO_STATUS_SUCCESS) {
		// if 'status' was not set to indicate a successful operation when saving as a png, error
		printf("Could not save to png, \"out.png\"\n");
		return 1;
	}

	return 0;
}

void rendertext(cairo_t *cr) {
	PangoLayout *layout;							// layout for a paragraph of text
	PangoFontDescription *desc;						// this structure stores a description of the style of font you'd most like
	
	cairo_translate(cr, 10, 20);						// set the origin of cairo instance 'cr' to (10,20) (i.e. this is where
										// drawing will start from).
	layout = pango_cairo_create_layout(cr);					// init pango layout ready for use
	pango_layout_set_text(layout, "سلام جهان!", -1);			// sets the text to be associated with the layout (final arg is length, -1
										// to calculate automatically when passing a nul-terminated string)
	desc = pango_font_description_from_string("Iranian sans Bold 12");		// specify the font that would be ideal for your particular use
	pango_layout_set_font_description(layout, desc);			// assign the previous font description to the layout
	pango_font_description_free(desc);					// free the description

	cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);				// set the colour to blue
	pango_cairo_update_layout(cr, layout);					// if the target surface or transformation properties of the cairo instance
										// have changed, update the pango layout to reflect this
	pango_cairo_show_layout(cr, layout);					// draw the pango layout onto the cairo surface

	g_object_unref(layout);							// free the layout
}

