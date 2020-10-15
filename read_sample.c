//
// Created by Adam on 2020-10-12.
//

#include "tga.h"







void main(){
    int large=64, *width=&large;
    int vertical=64, *height=&vertical;
    PIXEL_RGB24 *lager, **buffer=&lager;
    int read;
    int bits=24;

    read=tga_read("C:\\Users\\Adam\\Documents\\GitHub\\Lab-3b\\sample.tga", width, height, buffer);
    tga_write("C:\\Users\\Adam\\Documents\\GitHub\\Lab-3b\\sample-24bit.tga", *width, *height, lager, bits);

printf("%i",read);
}


#if 0 //Write comments there
Questions one to three is in the header tga.h
#endif

/*! Question 4
 *
 *  One of the arguments is constants so that it dose not change the pixel that are being coped in the middle of the program.
 */

/*! Question 5
 *
 *  The TGA header is stored on the stack because it dose not use dynamic memory allocation.
 */

/*! Question 6
 *
 *  tga_read returns -97 as it is plus two from -99 in the enum declaration.
 */

/*! Question 7
 *
 *  It means that the information about picture that is being sent is not supported by the program.
 *  In this case it is because imageDescriptor was not set to zero so the program dose not know what image it is.
 */

/*! Question 8
 *
 *  It is returned via the pointer *pixelBuf that points to image.
 */

/*! Question 9
 *
 *  One pixel was R:248 G:128 B:0 witch is a shade of orange.
 *  Another pixel was R:248 G:128 B:0 witch is a shade of orange.
 *  Another pixel was R:248 G:128 B:0 witch is a shade of orange.
 *  Another pixel was R:248 G:128 B:0 witch is a shade of orange.
 *  Another pixel was R:248 G:128 B:0 witch is a shade of orange.
 *  All of them are the same.
 *
 *  Because the entire imageDescriptor is set to zero there are no transparent bits.
 */

/*! Question 10
 *
 *  The file size is 49 kb (49 000 bytes).
 *  The size can be calculated with height*width*3 since there are now three (24/8) bytes per pixel compered to 2 (16/8)
 *  Because there are now more bits per pixel than the last image (24 compered with 16).
 */