/*
 *  plot.c
 *  
 *  Created by Fredrik Sandin on 20/08/12.
 */
#include "tga.h"
#include <math.h>
#include "interp1.h"

#define Max(a, b) a>b?a:b
#define Min(a, b) a>b?b:a

/*!
	Draw circle on image.
 
	\param image Image buffer of size width*height.
	\param width Width of image.
	\param height Height of image.
	\param x0 X-coordinate of circe centre.
	\param y0 Y-coordinate of circe centre.
	\param radius Radius of circle.
	\param color Color of circle.
*/
void draw_circle(PIXEL_RGB24 *image, int width, int height, int x0, int y0, int radius, const PIXEL_RGB24 *color) {

    double alpha; /* angle */
    int x, y, index;

    for (alpha = 0; alpha <= 2 * M_PI; alpha += 0.5 / radius) {

        x = x0 + radius * cos(alpha); /* x coordinate */
        y = y0 + radius * sin(alpha); /* y coordinate */

        if (x >= 0 && x < width && y >= 0 && y < height) {

            index = x + width * y; /* index of pixel in buffer */

            copy_pixel(&image[index], color);
        }
    }
}


void draw_line(PIXEL_RGB24 *image, int width, int height, float x_start, float y_start, float x_end, float y_end, PIXEL_RGB24 *color) {

    float x_vector[2] , y_vector[2];

    x_vector[0] = Min(x_start, x_end);
    x_vector[1] = Max(x_start, x_end);
    //Reorienting the direction of the line to start at the smallest value
    if(x_vector[0] == x_start) {
        y_vector[0] = y_start;
        y_vector[1] = y_end;
    }
    else {
        y_vector[0] = y_end;
        y_vector[1] = y_start;
    }
    //Starting att the smallest value in the vector
    float x = x_vector[0];
    float y = y_vector[0];
    double add;
    int index, number_pixels = (height * width);
    //Placeholder variable to make sure that the return is not an error
    float return_value = 0;
    //If the interp1 sends back a error it stops the while loop
    while (return_value != -1) {
        //If the derivation of the x vector = 0 then just keep the last x otherwise add the length of the vector divided by the number of pixels to x
        if (x_start != x_end) {
            add = sqrt(pow((x_end - x_start) / (double) number_pixels, 2)); // the sqrt in to pow is because we want a positive value
            x = x + add;
        }

        if (x_start != x_end)
            return_value = interp1(x_vector, y_vector, 2, x, &y);

            // In case of a vertical line
        else {
            y += 1;
            return_value = 0;
            if (y > y_vector[1])
                return_value = -1;
        }
        if (x < width && y < height && x > -1 && y > -1) {
            index = (x + (int) y * width);
            copy_pixel(&image[index], color);
        }
    }
}


int main(void) {

    int width;
    int height;
    PIXEL_RGB24 *image, red, green, blue;

    red.R = 255;
    red.G = 0;
    red.B = 0;
    green.R = 0;
    green.G = 255;
    green.B = 0;
    blue.R = 0;
    blue.G = 0;
    blue.B = 255;

    if (tga_read("C:\\Users\\adam\\Documents\\GitHub\\Lab-3b\\Q13\\empty.tga", &width, &height, &image) != TGA_OK) {
        goto error;
    }

    /* Draw a few circles on the image */
    //draw_circle(image,width,height,width/2,height/2,width/3,&red);
    //draw_circle(image,width,height,width/2,height/2,width/4,&green);
    draw_circle(image, width, height, width / 2, 0, width / 2, &blue);

    draw_line(image, width, height, 100, 3, 200, 300, &red);


    if (tga_write("C:\\Users\\adam\\Documents\\GitHub\\Lab-3b\\Q13\\circle.tga", width, height, image, 24) != TGA_OK) {
        goto error_free;
    }

    free(image); /* Free memory allocated by tga_read() */
    return 0;

    error_free:
    free(image);

    error:
    return -1;
}

/* EOF */

