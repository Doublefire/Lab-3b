/*
 *  gradient.c
 *  
 *  Created by Fredrik Sandin on 20/08/12.
 */

#include "tga.h"

int main(void) {

	int i;
	const int width = 256;
	const int height = 256;
	
	PIXEL_RGB24 image[width*height];
	
	for(i=0; i<width*height; i++) {
		image[i].R = i % 256;
		image[i].G = 0;
		image[i].B = i / 256;
	}
	
	if(tga_write("gradient-16bit.tga",width,height,image,16)!=TGA_OK) {
		return -1; /* ERROR OCCURRED */
	}

	if(tga_write("gradient-24bit.tga",width,height,image,24)!=TGA_OK) {
		return -1; /* ERROR OCCURRED */
	}
	
	return 0; /* OK */
}

/* EOF */