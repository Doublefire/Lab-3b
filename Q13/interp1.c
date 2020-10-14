/*
 *  interp1.c
 *
 *	Linear interpolation.
 *  Created by Fredrik Sandin on 27/08/12.
 *
 */

#include "interp1.h"

/**
	Linear interpolation of a function y=f(x) so that y2 = f(x2).
	It is assumed that x is a sorted and monotonous array. The
	values in x may be ascending or descending.
 
	\param x Array of x values.
	\param y Array of y values.
	\param length Length of x and y arrays.
	\param x2 X value.
	\param y2 Interpolated Y value (output).
 
	\return An index, i, so that x2 is in the range [x[i], x[i+1]),
			or -1 if x2 is out of range in x. 
*/
int interp1(const float x[], const float y[], int length, float x2, float y2[]) {

	/* Check if x2 is within range */
	if(!((x[0]<=x2 &&
	x2<x[length-1]) ||
	(x[0]>x2 &&
	x2>=x[length-1])))
	    return -1;

	/*
		Use a binary / half-interval search algorithm
		to find the relevant index in x[]. For details:
		http://en.wikipedia.org/wiki/Binary_search_algorithm
	*/
	int imin=0, imax=length-1, imid;
	int sgn = (x[imin] < x[imax]) ? 1 : -1;
	while (imax-imin>1) {
		
		/* calculate midpoint */
		imid = (imin+imax)/2;
		
		/* check which half to continue with */
		if((x2-x[imid])*sgn >= 0)
			imin = imid;
		else if((x2-x[imid])*sgn < 0)
			imax = imid;
	}

	(*y2) = (y[imax]-y[imin])/(x[imax]-x[imin])*(x2-x[imin]) + y[imin];
	
	return imin;
}

