/*
 *  mandelbrot.c
 *  
 *  Created by Fredrik Sandin on 21/08/12.
 */

#include "tga.h"


/*!
	Simple Mandelbrot renderer.
 
	Documentation needs to be completed.
	Zooming into the set is presently not supported.
*/
void mandelbrot_color(int x, int y, int width, int height, PIXEL_RGB24 *color, int max_it) {

	int i=0;
	double temp;
	double dx=0, x0 = -2.0 + 3.0*x/width;
	double dy=0, y0 = -1.0 + 2.0*y/height;
	
	while(dx*dx+dy*dy<4 && i++<max_it) {
		temp = dx*dx-dy*dy+x0;
		dy = 2.0*dx*dy + y0;
		dx = temp;
	}
	double s = i;
	s *= 255.0/(max_it);

	/* Purple/magenta colors */
	color->R = s; color->B = 0; color->G = s;

	/* Greyscale */
	/*color->R = color->B = color->G = 255 - s;*/
	
}

int main(void) {

	int x, y, max_it=3, index=0;
	const int width=1024,height=768;
	PIXEL_RGB24 *image;
    PIXEL_RGB24 color;

    /*!
     * Complete this code so that the output TGA file gets some nice colors.
     * Hint: you need to loop over all 1024*768 pixels and color each of them.
     */
    (image) = (PIXEL_RGB24 *) malloc(sizeof(PIXEL_RGB24) * (width*height));
    for (y = 0; y < height; ++y) {
        for ( x = 0; x < width; ++x) {
            mandelbrot_color( x, y, width, height, &color, max_it);
            copy_pixel(&image[index], &color);
            index++;
        }
    }

	if(tga_write("C:\\Users\\Adam\\Documents\\GitHub\\Lab-3b\\Q12\\mandelbrot.tga",width,height,image,24)!=TGA_OK) {
		return -1; /* ERROR OCCURRED */
	}
	
	return 0; /* OK */
}

/* EOF */